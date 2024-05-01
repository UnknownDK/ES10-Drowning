#include <stdio.h>
#include "FIRWeights.h"
#include <math.h>
#include <esp_dsp.h>
#include <time.h>

const float MIC_ARRAY[7] = {0.0,    0.3750,    0.4583,    0.5000,    0.5417,    0.6250,    1.0};


//#define FIR_COEFFS_LEN      64                              // Number of FIR filter coefficients
#define DECIMATION          1                               // Decimation ratio of the FIR filter
#define N_SAMPLES           1024//*4                          // Input samples
//#define FIR_DELAY           (FIR1LENGTH / DECIMATION)    // Amount of samples not being considered for the FFT
#define FIR_BUFF_OUT_LEN_ULA1    (N_SAMPLES + FIR1LENGTH)         // Total length of samples
#define FIR_BUFF_OUT_LEN_ULA2    (N_SAMPLES + FIR2LENGTH)         // Total length of samples
#define FIR_BUFF_OUT_LEN_ULA3    (N_SAMPLES + FIR3LENGTH)         // Total length of samples

static __attribute__((aligned(16))) float tone_combined[FIR_BUFF_OUT_LEN_ULA1];

static __attribute__((aligned(16))) float mic_inputs[7][FIR_BUFF_OUT_LEN_ULA1];

static __attribute__((aligned(16))) float delay_line_ula1[FIR1LENGTH];
static __attribute__((aligned(16))) float delay_line_ula2[FIR2LENGTH];
static __attribute__((aligned(16))) float delay_line_ula3[FIR3LENGTH];

const int32_t speed_of_sound = 1496;
float steerAng = 35; // gonna be set by AoI-detector
const int32_t sampling_frequency = 48e3; 

void app_main()
{
    const int32_t fir_len_ula1 = FIR1LENGTH;
    const int32_t fir_len_ula2 = FIR2LENGTH;
    const int32_t fir_len_ula3 = FIR3LENGTH;

    const int32_t N = N_SAMPLES;                                            // Number of input samples
    const int32_t fir_decim = DECIMATION;                                   // FIR filter decimation
    const int32_t N_buff = FIR_BUFF_OUT_LEN_ULA1;                                // Total length of samples with ignored

    fir_f32_t fir_ula1;
    fir_f32_t fir_ula2;
    fir_f32_t fir_ula3;
    //esp_err_t ret;

    // Generate input signal as 2 sine waves
    //float *tone_1 = (float *)malloc(N_buff * sizeof(float));
    //float *tone_2 = (float *)malloc(N_buff * sizeof(float));

    //dsps_tone_gen_f32(tone_1, N_buff, 1, 0.025, 0);
    //dsps_tone_gen_f32(tone_2, N_buff, 0, 0.1, 0);

    // Generate windowing coefficients/**/
    //float *window = (float *)malloc(N * sizeof(float));
    //dsps_wind_blackman_harris_f32(window, N);

    // Add the two waves together
    srand((unsigned int)time(NULL));
    const float input_sig_angle = 65*180/M_PI; 

    for (int i = 0 ; i < N_buff ; i++) {
        //tone_combined[i] = tone_1[i] + tone_2[i];
        //tone_combined[i] = sinf(2 * M_PI * (float)rand() / (float)RAND_MAX * 0.5); // Random frequency between 0 and 24 kHz (0 and 0.5 Nyquist)
        tone_combined[i] = sinf(2*M_PI*500*i*1/sampling_frequency + MIC_ARRAY[1]*input_sig_angle/speed_of_sound);
    }/*
    for (int j = 0 ; j < 7 ; j++){
        for (int i = 0 ; i < N_buff ; i++) {
            mic_inputs[j][i] = sinf(2*M_PI*500*i*1/sampling_frequency + MIC_ARRAY[j]*input_sig_angle/speed_of_sound);
        }
    }*/
    
    //free(tone_1);
    //free(tone_2);

    // Apply the windowing
    //for (int i = 0 ; i < N ; i++) {
    //    window[i] *= tone_combined[i];
    //}

    // Filter the input signal with FIR filter
    float *fir_out_ula1 = (float *)malloc( N_buff * sizeof(float));
    dsps_fird_init_f32(&fir_ula1, FIR1WEIGHTS, delay_line_ula1, fir_len_ula1, fir_decim); 
    float *fir_out_ula2 = (float *)malloc( N_buff * sizeof(float));
    dsps_fird_init_f32(&fir_ula2, FIR2WEIGHTS, delay_line_ula2, fir_len_ula2, fir_decim); 
    float *fir_out_ula3 = (float *)malloc( N_buff * sizeof(float));
    dsps_fird_init_f32(&fir_ula3, FIR3WEIGHTS, delay_line_ula3, fir_len_ula3, fir_decim); 

    // Apply filters
    dsps_fird_f32_ae32(&fir_ula1, tone_combined, fir_out_ula1, N_buff / fir_decim);       // _ae32 for ESP32 optimisation
    dsps_fird_f32_ae32(&fir_ula2, tone_combined, fir_out_ula2, N_buff / fir_decim);
    dsps_fird_f32_ae32(&fir_ula3, tone_combined, fir_out_ula3, N_buff / fir_decim);
    
    if (1 == 1){ 
        printf("In- and outputs\n");
        for (int i = 0; i < N_buff; i++) { 
            printf("%f, ", tone_combined[i]);
            printf("%f, ", fir_out_ula1[i]);
            printf("%f, ", fir_out_ula2[i]);
            printf("%f\n", fir_out_ula3[i]);
        }
    }
    

    //////// DAS ///////////
    const float spacings_ula1[3] = {MIC_ARRAY[0] - MIC_ARRAY[0], MIC_ARRAY[3] - MIC_ARRAY[0], MIC_ARRAY[6] - MIC_ARRAY[0]};
    const float spacings_ula2[3] = {MIC_ARRAY[1] - MIC_ARRAY[1], MIC_ARRAY[3] - MIC_ARRAY[1], MIC_ARRAY[5] - MIC_ARRAY[1]};
    const float spacings_ula3[3] = {MIC_ARRAY[2] - MIC_ARRAY[2], MIC_ARRAY[3] - MIC_ARRAY[2], MIC_ARRAY[4] - MIC_ARRAY[2]};
    
    float *delay_in_time_ula1 = (float *)malloc( 3 * sizeof(float)); //float delay_in_time_ula1[3];
    float *delay_in_time_ula2 = (float *)malloc( 3 * sizeof(float));
    float *delay_in_time_ula3 = (float *)malloc( 3 * sizeof(float));

    for (int i = 0 ; i < 3 ; i++) {
        delay_in_time_ula1[i] = sinf((steerAng - 90)*M_PI/180)*spacings_ula1[i]/speed_of_sound;
        delay_in_time_ula2[i] = sinf((steerAng - 90)*M_PI/180)*spacings_ula2[i]/speed_of_sound;
        delay_in_time_ula3[i] = sinf((steerAng - 90)*M_PI/180)*spacings_ula3[i]/speed_of_sound;
    }
    
    // in samples now
    int32_t delay_in_samples_ula1[3] = {round(delay_in_time_ula1[0]*sampling_frequency), round(delay_in_time_ula1[1]*sampling_frequency), round(delay_in_time_ula1[2]*sampling_frequency)};
    int32_t delay_in_samples_ula2[3] = {round(delay_in_time_ula2[0]*sampling_frequency), round(delay_in_time_ula2[1]*sampling_frequency), round(delay_in_time_ula2[2]*sampling_frequency)};
    int32_t delay_in_samples_ula3[3] = {round(delay_in_time_ula3[0]*sampling_frequency), round(delay_in_time_ula3[1]*sampling_frequency), round(delay_in_time_ula3[2]*sampling_frequency)};

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

    free(delay_in_time_ula1);
    free(delay_in_time_ula2);
    free(delay_in_time_ula3);


}