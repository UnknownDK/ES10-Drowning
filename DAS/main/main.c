#include <stdio.h>
#include "FIRWeights.h"
#include <math.h>
#include <esp_dsp.h>
#include <time.h>
#include <freertos/FreeRTOS.h>
#include <string.h>
#include <esp_task_wdt.h>
//#include "semphr.h"

//#define FIR_COEFFS_LEN      64                              // Number of FIR filter coefficients
#define DECIMATION          1                               // Decimation ratio of the FIR filter
//#define N_SAMPLES           1024//*4                          // Input samples
//#define FIR_DELAY           (FIR1LENGTH / DECIMATION)    // Amount of samples not being considered for the FFT


//static __attribute__((aligned(16))) float tone_combined[FIR_BUFF_OUT_LEN_ULA1];

static __attribute__((aligned(16))) float delay_line_ula1[FIR1LENGTH];
static __attribute__((aligned(16))) float delay_line_ula2[FIR2LENGTH];
static __attribute__((aligned(16))) float delay_line_ula3[FIR3LENGTH];

const float speed_of_sound = 1496;
float steerAng = 35; // gonna be set by AoI-detector
const float sampling_frequency = 48e3; 

// Emulate packet updates
// 1024 samples per update divided over 8 mics
// 128 samples per mic each consisting of 16 bits 
#define SAMPLES_PER_MIC 128
#define NUMBER_OF_MICS 7
#define FIR_BUFF_OUT_LEN_ULA1    (SAMPLES_PER_MIC + FIR1LENGTH)         // Total length of samples
#define FIR_BUFF_OUT_LEN_ULA2    (SAMPLES_PER_MIC + FIR2LENGTH)         // Total length of samples
#define FIR_BUFF_OUT_LEN_ULA3    (SAMPLES_PER_MIC + FIR3LENGTH)         // Total length of samples

const float input_sig_angle = 35;//35 
const float MIC_ARRAY[7] = {0.0,    0.3750,    0.4583,    0.5000,    0.5417,    0.6250,    1.0};
static __attribute__((aligned(16))) float mic_inputs[NUMBER_OF_MICS*SAMPLES_PER_MIC];
void data_feeder(){
    srand((unsigned int)time(NULL));
    int random_frequency[SAMPLES_PER_MIC];
    for (int i = 0 ; i < SAMPLES_PER_MIC ; i++) {
        random_frequency[i] = rand() % 24000 + 1;
    }
    for (int j = 0 ; j < NUMBER_OF_MICS ; j++){
        for (int i = 0 ; i < SAMPLES_PER_MIC ; i++) {
            //mic_inputs[i+j*SAMPLES_PER_MIC] = sinf(2*M_PI*500*(i*1/sampling_frequency + MIC_ARRAY[j]*cosf(input_sig_angle*M_PI/180.0)/speed_of_sound));
            //mic_inputs[i+j*SAMPLES_PER_MIC] = sinf(2*M_PI*random_frequency[i]*(i*1/sampling_frequency + MIC_ARRAY[j]*cosf(input_sig_angle*M_PI/180.0)/speed_of_sound));
            //mic_inputs[i+j*SAMPLES_PER_MIC] = sinf(2*M_PI*random_frequency[i]*(1/sampling_frequency + MIC_ARRAY[j]*cosf(input_sig_angle*M_PI/180.0)/speed_of_sound));
            mic_inputs[i+j*SAMPLES_PER_MIC] = sinf(2*M_PI*100*(i*1/sampling_frequency + MIC_ARRAY[j]*cosf(input_sig_angle*M_PI/180.0)/speed_of_sound));
        } // mistænker at faseskift er for stort
    }
}

static int32_t delay_in_samples_ula1[3];
static int32_t delay_in_samples_ula2[3];
static int32_t delay_in_samples_ula3[3];
void calculate_DAS_delays(){
    const float spacings_ula1[3] = {MIC_ARRAY[0] - MIC_ARRAY[0], MIC_ARRAY[3] - MIC_ARRAY[0], MIC_ARRAY[6] - MIC_ARRAY[0]};
    const float spacings_ula2[3] = {MIC_ARRAY[1] - MIC_ARRAY[1], MIC_ARRAY[3] - MIC_ARRAY[1], MIC_ARRAY[5] - MIC_ARRAY[1]};
    const float spacings_ula3[3] = {MIC_ARRAY[2] - MIC_ARRAY[2], MIC_ARRAY[3] - MIC_ARRAY[2], MIC_ARRAY[4] - MIC_ARRAY[2]};
    
    float *delay_in_time_ula1 = (float *)malloc( 3 * sizeof(float)); 
    float *delay_in_time_ula2 = (float *)malloc( 3 * sizeof(float));
    float *delay_in_time_ula3 = (float *)malloc( 3 * sizeof(float));

    for (int i = 0 ; i < 3 ; i++) {
        delay_in_time_ula1[i] = sinf((steerAng - 90)*M_PI/180)*spacings_ula1[i]/speed_of_sound;
        delay_in_time_ula2[i] = sinf((steerAng - 90)*M_PI/180)*spacings_ula2[i]/speed_of_sound;
        delay_in_time_ula3[i] = sinf((steerAng - 90)*M_PI/180)*spacings_ula3[i]/speed_of_sound;
        // possibility to add fractional delays here
        delay_in_samples_ula1[i] = delay_in_time_ula1[i]*sampling_frequency;
        delay_in_samples_ula2[i] = delay_in_time_ula2[i]*sampling_frequency;
        delay_in_samples_ula3[i] = delay_in_time_ula3[i]*sampling_frequency;
    }
    free(delay_in_time_ula1);
    free(delay_in_time_ula2);
    free(delay_in_time_ula3);
}

static __attribute__((aligned(16))) float mic_inputs_big[NUMBER_OF_MICS*SAMPLES_PER_MIC*3];

static __attribute__((aligned(16))) float ula1_output_summed[SAMPLES_PER_MIC];
static __attribute__((aligned(16))) float ula2_output_summed[SAMPLES_PER_MIC];
static __attribute__((aligned(16))) float ula3_output_summed[SAMPLES_PER_MIC];


void app_main()
{    
    esp_task_wdt_deinit();
    
    const int32_t fir_len_ula1 = FIR1LENGTH;
    const int32_t fir_len_ula2 = FIR2LENGTH;
    const int32_t fir_len_ula3 = FIR3LENGTH;

    const int32_t fir_decim = DECIMATION;                                   // FIR filter decimation
    const int32_t N_buff = FIR_BUFF_OUT_LEN_ULA1;                                // Total length of samples with ignored

    fir_f32_t fir_ula1;
    fir_f32_t fir_ula2;
    fir_f32_t fir_ula3;
    //esp_err_t ret;

    // Initialise FIR filter
    
    float *fir_out_ula1 = (float *)malloc( N_buff * sizeof(float));
    dsps_fird_init_f32(&fir_ula1, FIR1WEIGHTS, delay_line_ula1, fir_len_ula1, fir_decim); 
    float *fir_out_ula2 = (float *)malloc( N_buff * sizeof(float));
    dsps_fird_init_f32(&fir_ula2, FIR2WEIGHTS, delay_line_ula2, fir_len_ula2, fir_decim); 
    float *fir_out_ula3 = (float *)malloc( N_buff * sizeof(float));
    dsps_fird_init_f32(&fir_ula3, FIR3WEIGHTS, delay_line_ula3, fir_len_ula3, fir_decim); //UNDERSØG DELAY LINES!!!!

    calculate_DAS_delays();
    int8_t memory_pointer_new = 1; // Designates which buffer the new data is input to
    int8_t memory_pointer_middle = 2; // Designates which buffer should be used in DAS (delayed by 1, such surrounding buffers with old and new data are accesible)
    int8_t memory_pointer_old = 0;
    int16_t runonlyonce = 0;
    while(runonlyonce<20){
        runonlyonce++; 
        // Update mic inputs
        vTaskDelay(pdMS_TO_TICKS(2.66666666));
        // 48000/128 Hz
        data_feeder(); // sets mic_inputs


        memcpy(&mic_inputs_big[memory_pointer_new*SAMPLES_PER_MIC*NUMBER_OF_MICS], mic_inputs, sizeof(float)*NUMBER_OF_MICS*SAMPLES_PER_MIC);

        if (1 == 1){ 
            //printf("Mic inputs\n");
            for (int i = 0; i < SAMPLES_PER_MIC; i++) {  
                for (int j = 0 ; j < NUMBER_OF_MICS ; j++){
                    printf("%f", mic_inputs_big[memory_pointer_new*SAMPLES_PER_MIC*NUMBER_OF_MICS+j*SAMPLES_PER_MIC+i]);
                    if (j < NUMBER_OF_MICS - 1){
                        printf(", ");
                    } else {
                        printf("\n");
                    }
                    
                }
            }
        }
        int32_t ula1_mic_list[3] = {0, 3, 6}; 
        int32_t ula2_mic_list[3] = {1, 3, 5}; 
        int32_t ula3_mic_list[3] = {2, 3, 4}; 

        memset(ula1_output_summed, 0, SAMPLES_PER_MIC*sizeof(float));
        memset(ula2_output_summed, 0, SAMPLES_PER_MIC*sizeof(float));
        memset(ula3_output_summed, 0, SAMPLES_PER_MIC*sizeof(float));

        // not the most readable code I've ever wrote
        for (int j = 0; j < 3; j++){ // Number of microphones in ULA
            for (int i = 0; i < SAMPLES_PER_MIC; i++) {
                // ULA1
                if ((i + delay_in_samples_ula1[j]) < 0){ // delay is negative - move to newest buffer - index to mic+1 - subtract from there
                    ula1_output_summed[i] += mic_inputs_big[memory_pointer_new*NUMBER_OF_MICS*SAMPLES_PER_MIC+(ula1_mic_list[j]+1)*SAMPLES_PER_MIC+delay_in_samples_ula1[j] + i] * 1/3;
                    //printf("Negative delay: %ld\n", memory_pointer_new*NUMBER_OF_MICS*SAMPLES_PER_MIC+(ula1_mic_list[j]+1)*SAMPLES_PER_MIC+delay_in_samples_ula1[j] + i);
                    //printf("Delay value: %ld\n", delay_in_samples_ula1[j]);
                    //printf("Current buffer start: %d\n", memory_pointer_middle*NUMBER_OF_MICS*SAMPLES_PER_MIC);
                } else if((i + delay_in_samples_ula1[j]) >= SAMPLES_PER_MIC){ // delay is positive - move to oldest buffer 
                    ula1_output_summed[i] += mic_inputs_big[memory_pointer_old*NUMBER_OF_MICS*SAMPLES_PER_MIC+(ula1_mic_list[j]-1)*SAMPLES_PER_MIC+delay_in_samples_ula1[j] + i] * 1/3;
                    //printf("Postive delay: %ld\n", memory_pointer_old*NUMBER_OF_MICS*SAMPLES_PER_MIC+(ula1_mic_list[j]-1)*SAMPLES_PER_MIC+delay_in_samples_ula1[j] + i);
                } else{
                    ula1_output_summed[i] += mic_inputs_big[memory_pointer_middle*NUMBER_OF_MICS*SAMPLES_PER_MIC+delay_in_samples_ula1[j] + i] * 1/3;
                }
                // ULA2
                if ((i + delay_in_samples_ula2[j]) < 0){ // delay is negative - move to newest buffer - index to mic+1 - subtract from there
                    ula2_output_summed[i] += mic_inputs_big[memory_pointer_new*NUMBER_OF_MICS*SAMPLES_PER_MIC+(ula2_mic_list[j]+1)*SAMPLES_PER_MIC+delay_in_samples_ula2[j] + i] * 1/3;
                } else if((i + delay_in_samples_ula2[j]) >= SAMPLES_PER_MIC){ // delay is positive - move to oldest buffer 
                    ula2_output_summed[i] += mic_inputs_big[memory_pointer_old*NUMBER_OF_MICS*SAMPLES_PER_MIC+(ula2_mic_list[j]-1)*SAMPLES_PER_MIC+delay_in_samples_ula2[j] + i] * 1/3;
                } else{
                    ula2_output_summed[i] += mic_inputs_big[memory_pointer_middle*NUMBER_OF_MICS*SAMPLES_PER_MIC+delay_in_samples_ula2[j] + i] * 1/3;
                }
                // ULA3
                if ((i + delay_in_samples_ula3[j]) < 0){ // delay is negative - move to newest buffer - index to mic+1 - subtract from there
                    ula3_output_summed[i] += mic_inputs_big[memory_pointer_new*NUMBER_OF_MICS*SAMPLES_PER_MIC+(ula3_mic_list[j]+1)*SAMPLES_PER_MIC+delay_in_samples_ula3[j] + i] * 1/3;
                } else if((i + delay_in_samples_ula3[j]) >= SAMPLES_PER_MIC){ // delay is positive - move to oldest buffer 
                    ula3_output_summed[i] += mic_inputs_big[memory_pointer_old*NUMBER_OF_MICS*SAMPLES_PER_MIC+(ula3_mic_list[j]-1)*SAMPLES_PER_MIC+delay_in_samples_ula3[j] + i] * 1/3;
                } else{
                    ula3_output_summed[i] += mic_inputs_big[memory_pointer_middle*NUMBER_OF_MICS*SAMPLES_PER_MIC+delay_in_samples_ula3[j] + i] * 1/3;
                }
            }
        }
        memory_pointer_old = memory_pointer_middle;
        memory_pointer_middle = memory_pointer_new;
        memory_pointer_new--;
        if (memory_pointer_new > 2){
            memory_pointer_new = 0;
        }else if (memory_pointer_new < 0){
            memory_pointer_new = 2;
        }
        if (1 == 0){ 
            //printf("ulas summed\n");delay_in_samples_ula3
            for (int i = 0; i < SAMPLES_PER_MIC; i++) { 
                printf("%f, ", ula1_output_summed[i]);
                printf("%f, ", ula2_output_summed[i]);
                printf("%f\n", ula3_output_summed[i]);
            }
        }
        // ULA2
        // ULA1OUTPUT = mic_inputs_big[memory_pointer]
        // Update DAS
        // if steerAng = new
            //calculate_DAS_delays();
        //float FIR1SUM = 0;
        //for (int i = 0; i < FIR1LENGTH; i++){
        //   FIR1SUM += FIR1WEIGHTS[i];
        //}
        //printf("FIR1 sum: %f\n", FIR1SUM);

        // Apply filters
        dsps_fird_f32_ae32(&fir_ula1, ula1_output_summed, fir_out_ula1, N_buff / fir_decim);       // _ae32 for ESP32 optimisation
        dsps_fird_f32_ae32(&fir_ula2, ula2_output_summed, fir_out_ula2, N_buff / fir_decim);
        dsps_fird_f32_ae32(&fir_ula3, ula3_output_summed, fir_out_ula3, N_buff / fir_decim);
        if (1 == 0){ 
            //printf("Filter outputs\n");
            for (int i = 0; i < FIR_BUFF_OUT_LEN_ULA3; i++) { 
                printf("%f, ", fir_out_ula1[i]);
                printf("%f, ", fir_out_ula2[i]);
                printf("%f, ", fir_out_ula3[i]);
                printf("%f\n", fir_out_ula1[i]+fir_out_ula2[i]+fir_out_ula3[i]);
            }
        }
        if (1 == 0){
            double das_output_mag = 0;
            double sig_input_mag = 0;
            //for (int i = 0; i < FIR_BUFF_OUT_LEN_ULA1; i++){
            //    das_output_mag += (pow(fir_out_ula1[i],2) + pow(fir_out_ula2[i],2) + pow(fir_out_ula3[i],2))/3;
            //}
            for (int i = 0; i < SAMPLES_PER_MIC; i++){
                das_output_mag += (pow(ula1_output_summed[i],2) + pow(ula2_output_summed[i],2) + pow(ula3_output_summed[i],2))/3;

            }
            for (int i = 0; i < NUMBER_OF_MICS*SAMPLES_PER_MIC; i++){
                sig_input_mag += pow(mic_inputs[i],2)/NUMBER_OF_MICS;
            }
            printf("magratio: %f\n", das_output_mag/sig_input_mag);
        }
    }
}


////////////// PRINTERS /////////////
/*
if (1 == 0){ 
    printf("In- and outputs\n");
    for (int i = 0; i < N_buff; i++) { 
        printf("%f, ", tone_combined[i]);
        printf("%f, ", fir_out_ula1[i]);
        printf("%f, ", fir_out_ula2[i]);
        printf("%f\n", fir_out_ula3[i]);
    }
}

if (1 == 0){
    printf("\nULA1 spacings: %f, %f, %f\n", spacings_ula1[0], spacings_ula1[1], spacings_ula1[2]);
    printf("ULA2 spacings: %f, %f, %f\n", spacings_ula2[0], spacings_ula2[1], spacings_ula2[2]);
    printf("ULA3 spacings: %f, %f, %f\n", spacings_ula3[0], spacings_ula3[1], spacings_ula3[2]);

    printf("\nULA1 time delays: %f, %f, %f\n", delay_in_time_ula1[0], delay_in_time_ula1[1], delay_in_time_ula1[2]);
    printf("ULA2 time delays: %f, %f, %f\n", delay_in_time_ula2[0], delay_in_time_ula2[1], delay_in_time_ula2[2]);
    printf("ULA3 time delays: %f, %f, %f\n", delay_in_time_ula3[0], delay_in_time_ula3[1], delay_in_time_ula3[2]);

    printf("\nULA1 sample delays: %li, %li, %li\n", delay_in_samples_ula1[0], delay_in_samples_ula1[1], delay_in_samples_ula1[2]);
    printf("ULA2 sample delays: %li, %li, %li\n", delay_in_samples_ula2[0], delay_in_samples_ula2[1], delay_in_samples_ula2[2]);
    printf("ULA3 sample delays: %li, %li, %li\n", delay_in_samples_ula3[0], delay_in_samples_ula3[1], delay_in_samples_ula3[2]);
}

if (1 == 0){ 
    printf("Mic inputs\n");
    for (int i = 0; i < SAMPLES_PER_MIC; i++) {  
        for (int j = 0 ; j < NUMBER_OF_MICS ; j++){
            printf("%f", mic_inputs[j][i]);
            if (j < 6){
                printf(", ");
            } else {
                printf("\n");
            }
            
        }
    }
}
*/