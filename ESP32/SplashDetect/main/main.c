/* SPI Slave example, receiver (uses SPI Slave driver to communicate with sender)

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <freertos/semphr.h>
#include "esp_task_wdt.h"
#include "freertos/queue.h"
#include "constants.h"

#include "esp_log.h"
#include "driver/spi_slave.h"

#include "driver/gpio.h"



#include <esp_task_wdt.h>
#include "offloading.h"
#include "DAS.h"
#include <math.h>
#include <esp_dsp.h>
#include <time.h>

#include "esp_timer.h"

#include "FIRWeights.h"

#define RCV_HOST    SPI2_HOST

#define GPIO_MOSI           11 // P2[1]
#define GPIO_MISO           13 // P2[3]
#define GPIO_SCLK           10  // P2[0]
#define GPIO_CS             12  // P2[2]

QueueHandle_t dasQueue;
QueueHandle_t wifiQueue;

int64_t timer = 0;
int64_t bytecount = 0;
int64_t wificount = 0;
int64_t wifbehind = 0;

WORD_ALIGNED_ATTR uint8_t recvbuf[3990]; //  
uint8_t sendbuf[3990];

TaskHandle_t spi_task_handle = NULL;

//Called after a transaction is queued and ready for pickup by master. We use this to set the handshake line high.
void my_post_setup_cb(spi_slave_transaction_t *trans)
{
    //gpio_set_level(GPIO_HANDSHAKE, 1);
}

//Called after transaction is sent/received. We use this to set the handshake line low.
void my_post_trans_cb(spi_slave_transaction_t *trans)
{
    //gpio_set_level(GPIO_HANDSHAKE, 1);
    
    wifbehind += 1;
    // BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    //vTaskNotifyGiveFromISR(spi_task_handle, &xHigherPriorityTaskWoken);
    //if (xHigherPriorityTaskWoken == pdTRUE) {
    //    portYIELD_FROM_ISR();
    //}
}

// Define your SPI slave task function
void spi_slave_task(void *pvParameters) {
    // Initialize SPI slave

    //Configuration for the SPI bus
    spi_bus_config_t buscfg = {
        .mosi_io_num = GPIO_MOSI,
        .miso_io_num = GPIO_MISO,
        .sclk_io_num = GPIO_SCLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
    };

    //Configuration for the SPI slave interface
    spi_slave_interface_config_t slvcfg = {
        .mode = 0,
        .spics_io_num = GPIO_CS,
        .queue_size = 3,
        .flags = 0,
        .post_setup_cb = my_post_setup_cb,
        .post_trans_cb = my_post_trans_cb
    };

    //Initialize SPI slave interface
    esp_err_t ret;
    ret = spi_slave_initialize(RCV_HOST, &buscfg, &slvcfg, SPI_DMA_CH_AUTO);
    assert(ret == ESP_OK);

    //WORD_ALIGNED_ATTR uint8_t sendbuf[1024];
    
    //memset(recvbuf, 0, 33);
    spi_slave_transaction_t t;
    memset(&t, 0, sizeof(t));
        //Clear receive buffer, set send buffer to something sane
    memset(recvbuf, 0xA, 3990);
    //sprintf(sendbuf, "This is the receiver, sending data for transmission number %04d.", n);

    //Set up a transaction of 128 bytes to send/receive
    t.length = 3990 * 8;
    t.tx_buffer = NULL;
    t.rx_buffer = recvbuf;

    uint32_t lasttime_b = dsp_get_cpu_cycle_count();
    while(1) {
        // Wait for a signal to transmit data
        //ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        ret = spi_slave_transmit(RCV_HOST, &t, portMAX_DELAY);
        memcpy(sendbuf, recvbuf, 3990);
        
        xQueueSend(dasQueue, &sendbuf, ( TickType_t ) 0 ); //&
        //printf("sendetask: %ld\n", dsp_get_cpu_cycle_count()-lasttime_b);
        lasttime_b = dsp_get_cpu_cycle_count();
        

    }
}

///////////////////////// DAS SETUP ////////////////////
#define SAMPLES_PER_MIC 190
#define NUMBER_OF_MICS 7

//static __attribute__((aligned(16))) float mic_inputs[SAMPLES_PER_MIC*NUMBER_OF_MICS];//NUMBER_OF_MICS*SAMPLES_PER_MIC];
static float mic_inputs[SAMPLES_PER_MIC*NUMBER_OF_MICS];
//int32_t mic_inputs[SAMPLES_PER_MIC*NUMBER_OF_MICS];
static __attribute__((aligned(16))) float delay_line_ula1[FIR1LENGTH];
static __attribute__((aligned(16))) float delay_line_ula2[FIR2LENGTH];
static __attribute__((aligned(16))) float delay_line_ula3[FIR3LENGTH];
//static __attribute__((aligned(16))) float mic_inputs_big[NUMBER_OF_MICS*SAMPLES_PER_MIC*3];
static float mic_inputs_big[NUMBER_OF_MICS*SAMPLES_PER_MIC*3];
static __attribute__((aligned(16))) float ula1_output_summed[SAMPLES_PER_MIC];
static __attribute__((aligned(16))) float ula2_output_summed[SAMPLES_PER_MIC];
static __attribute__((aligned(16))) float ula3_output_summed[SAMPLES_PER_MIC];
//static __attribute__((aligned(16))) float ula_output_summed[SAMPLES_PER_MIC];
static float ula_output_summed[SAMPLES_PER_MIC];
//static __attribute__((aligned(16))) float fir_output_summed[SAMPLES_PER_MIC];
static float fir_output_summed[SAMPLES_PER_MIC];

const float MIC_ARRAY[7] = {0.0,    0.3333,    0.4286,    0.5000,    0.5714,    0.6667,    1.0};
const float speed_of_sound = 1496;
const float sampling_frequency = 41.6667e3; 
static float steerAng = 35;

static int32_t offset_in_samples_ula1[3];
static int32_t offset_in_samples_ula2[3];
static int32_t offset_in_samples_ula3[3];

static int8_t memory_pointer_new = 2; // Designates which buffer the new data is input to
static int8_t memory_pointer_middle = 1; // Designates which buffer should be used in DAS (delayed by 1, such surrounding buffers with old and new data are accesible)
static int8_t memory_pointer_old = 0;


void calculate_DAS_delays(){
    const float spacings_ula1[3] = {MIC_ARRAY[0] - MIC_ARRAY[0], MIC_ARRAY[3] - MIC_ARRAY[0], MIC_ARRAY[6] - MIC_ARRAY[0]};
    const float spacings_ula2[3] = {MIC_ARRAY[1] - MIC_ARRAY[1], MIC_ARRAY[3] - MIC_ARRAY[1], MIC_ARRAY[5] - MIC_ARRAY[1]};
    const float spacings_ula3[3] = {MIC_ARRAY[2] - MIC_ARRAY[2], MIC_ARRAY[3] - MIC_ARRAY[2], MIC_ARRAY[4] - MIC_ARRAY[2]};
    
    float *delay_in_time_ula1 = (float *)malloc( 3 * sizeof(float)); 
    float *delay_in_time_ula2 = (float *)malloc( 3 * sizeof(float));
    float *delay_in_time_ula3 = (float *)malloc( 3 * sizeof(float));

    for (int i = 0 ; i < 3 ; i++) {
        //delay_in_time_ula1[i] = sinf((steerAng - 90)*M_PI/180)*spacings_ula1[i]/speed_of_sound;
        //delay_in_time_ula2[i] = sinf((steerAng - 90)*M_PI/180)*spacings_ula2[i]/speed_of_sound;
        //delay_in_time_ula3[i] = sinf((steerAng - 90)*M_PI/180)*spacings_ula3[i]/speed_of_sound;
        delay_in_time_ula1[i] = -cosf(steerAng*M_PI/180)*spacings_ula1[i]/speed_of_sound;
        delay_in_time_ula2[i] = -cosf(steerAng*M_PI/180)*spacings_ula2[i]/speed_of_sound;
        delay_in_time_ula3[i] = -cosf(steerAng*M_PI/180)*spacings_ula3[i]/speed_of_sound;
        //printf("ULA1, mic %d: %f\n", i, delay_in_time_ula1[i]);
        //printf("ULA2, mic %d: %f\n", i, delay_in_time_ula2[i]);
        //printf("ULA3, mic %d: %f\n", i, delay_in_time_ula3[i]);

        // possibility to add fractional delays here
        offset_in_samples_ula1[i] = round(delay_in_time_ula1[i]*sampling_frequency);
        offset_in_samples_ula2[i] = round(delay_in_time_ula2[i]*sampling_frequency);
        offset_in_samples_ula3[i] = round(delay_in_time_ula3[i]*sampling_frequency);
    }
    free(delay_in_time_ula1);
    free(delay_in_time_ula2);
    free(delay_in_time_ula3);
}

///////////////////////// DAS SETUP END ////////////////////////

#define WIFI_SEND_ARRAY_SIZE SAMPLES_PER_MIC*8//*NUMBER_OF_MICS//+FIR1LENGTH // NUMBER OF INDICES IN ARRAY TO SEND TO WIFI (NOT NUMBER OF BITS) MATCH WITH VAR IN offloading.c
static float wifiOutputArray[WIFI_SEND_ARRAY_SIZE]; 
uint8_t rawinput[3990];
//Main application
void app_main(void)
{
    esp_task_wdt_deinit();

    wifi_init_sta();
    esp_log_level_set("wifi",ESP_LOG_NONE);
    
    dasQueue = xQueueCreate(10, 3990);
    wifiQueue = xQueueCreate(10, WIFI_SEND_ARRAY_SIZE*4); // IN BYTES!!

    xTaskCreatePinnedToCore(&socket_task, "socket_task", 8192*2, NULL, 5, NULL, 1);
    //xTaskCreatePinnedToCore(&das_task, "das_task", 16384, NULL, 1, NULL, 1);
    //xTaskCreatePinnedToCore(&spi_task, "spi_task", 4096, NULL, 1, NULL, 1);
    xTaskCreatePinnedToCore(&spi_slave_task, "spi_slave_task", 2048, NULL, 1, &spi_task_handle, 0);

    timer = esp_timer_get_time();
    bytecount = 0;


    //esp_err_t ret;

    //Enable pull-ups on SPI lines so we don't detect rogue pulses when no master is connected.
    gpio_set_pull_mode(GPIO_MOSI, GPIO_PULLUP_ONLY);
    gpio_set_pull_mode(GPIO_SCLK, GPIO_PULLUP_ONLY);
    gpio_set_pull_mode(GPIO_CS, GPIO_PULLUP_ONLY);



    calculate_DAS_delays();
    //const int32_t fir_len_ula = FIR1LENGTH;
    //const int32_t fir_decim = 1;                                   // FIR filter decimation
    //const int32_t N_buff = SAMPLES_PER_MIC + fir_len_ula;

    fir_f32_t fir_ula1;
    fir_f32_t fir_ula2;
    fir_f32_t fir_ula3;

    //float *fir_out_ula1 = (float *)malloc( N_buff * sizeof(float));
    float *fir_out_ula1 = (float *)malloc( SAMPLES_PER_MIC * sizeof(float));
    dsps_fir_init_f32(&fir_ula1, FIR1WEIGHTS, delay_line_ula1, FIR1LENGTH); //fir_len_ula
    float *fir_out_ula2 = (float *)malloc( SAMPLES_PER_MIC * sizeof(float));
    dsps_fir_init_f32(&fir_ula2, FIR2WEIGHTS, delay_line_ula2, FIR2LENGTH); 
    float *fir_out_ula3 = (float *)malloc( SAMPLES_PER_MIC * sizeof(float));
    dsps_fir_init_f32(&fir_ula3, FIR3WEIGHTS, delay_line_ula3, FIR3LENGTH); 

    //uint32_t dastime = dsp_get_cpu_cycle_count();
    while (1) {
        if(xQueueReceive(dasQueue, &rawinput, portMAX_DELAY) == pdPASS) {
            //printf("dastask: %ld\n", dsp_get_cpu_cycle_count()-dastime);


        /* This call enables the SPI slave interface to send/receive to the sendbuf and recvbuf. The transaction is
        initialized by the SPI master, however, so it will not actually happen until the master starts a hardware transaction
        by pulling CS low and pulsing the clock etc. In this specific example, we use the handshake line, pulled up by the
        .post_setup_cb callback that is called as soon as a transaction is ready, to let the master know it is free to transfer
        data.
        */
        //ret = spi_slave_transmit(RCV_HOST, &t, portMAX_DELAY);

        
        /////////////////////////// DAS MAIN /////////////////////////////////////
        // Hopefully only runs once on updated data

        // Update steerAng
        //calculate_DAS_delays();

        //uint32_t start_b = dsp_get_cpu_cycle_count();


        /*for (int i = 0; i < 512*7 - 1; i +=2){
            int16_t concatenated_data = (rawinput[i] << 8) | rawinput[i + 1];
            mic_inputs[i/2] = (float)concatenated_data / (0.5f*65535.0f);
        }*/
        for (int i = 0; i < SAMPLES_PER_MIC*NUMBER_OF_MICS*3 - 1; i +=3){ // 2688 - last int is number of bytes per sample (24 bit = 3)
            int32_t concatenated_data = (rawinput[i] << 24) | (rawinput[i + 1] << 16) | (rawinput[i + 2] << 8);
            mic_inputs[i/3] = (float)concatenated_data;// / (pow(2,31)); //-1
            //mic_inputs[i/3] = (float)concatenated_data / 2147483648.0f
        }

        //uint32_t end_b = dsp_get_cpu_cycle_count();
        //printf("clocks in for loop: %ld\n", end_b-start_b);

        if (1 == 0){ 
             //printf("Mic inputs\n");The extension (_ae32) is optimized for ESP32 chip.
            for (int i = 0; i < SAMPLES_PER_MIC; i++) {  
                for (int j = 0 ; j < NUMBER_OF_MICS ; j++){
                    //printf("%f", mic_inputs[i+SAMPLES_PER_MIC*j]);
                    if (j < NUMBER_OF_MICS - 1){
                        printf(", ");
                    } else {
                        printf("\n");
                    }
                }
            }
        }
        
        memcpy(&mic_inputs_big[memory_pointer_new*SAMPLES_PER_MIC*NUMBER_OF_MICS], mic_inputs, sizeof(float)*NUMBER_OF_MICS*SAMPLES_PER_MIC);

        int32_t ula1_mic_list[3] = {0, 3, 6}; 
        int32_t ula2_mic_list[3] = {1, 3, 5}; 
        int32_t ula3_mic_list[3] = {2, 3, 4}; 

        memset(ula1_output_summed, 0, SAMPLES_PER_MIC*sizeof(float));
        memset(ula2_output_summed, 0, SAMPLES_PER_MIC*sizeof(float));
        memset(ula3_output_summed, 0, SAMPLES_PER_MIC*sizeof(float));
    
        for (int j = 0; j < 3; j++){ // Number of microphones in ULA
            for (int i = 0; i < SAMPLES_PER_MIC; i++) {
                //printf("mem. pointer mid.: %d\n", memory_pointer_middle);
                //printf("sample index: %d\n", i);
                if ((i + offset_in_samples_ula1[j]) >= SAMPLES_PER_MIC){ 
                // offset is positive (forwards in time), meaning rightmost mic of ULA is furthest away
                    ula1_output_summed[i] += mic_inputs_big[memory_pointer_new*NUMBER_OF_MICS*SAMPLES_PER_MIC+ula1_mic_list[j]*SAMPLES_PER_MIC+i+offset_in_samples_ula1[j]-SAMPLES_PER_MIC] * 1/3;
                    //printf("offset: %ld\n", offset_in_samples_ula1[j]);
                    //printf("sample with os: %ld\n", memory_pointer_new*NUMBER_OF_MICS*SAMPLES_PER_MIC+ula1_mic_list[j]*SAMPLES_PER_MIC+i+offset_in_samples_ula1[j]-SAMPLES_PER_MIC);
                } else if((i + offset_in_samples_ula1[j]) < 0){ 
                    ula1_output_summed[i] += mic_inputs_big[memory_pointer_old*NUMBER_OF_MICS*SAMPLES_PER_MIC+ula1_mic_list[j]*SAMPLES_PER_MIC+i+offset_in_samples_ula1[j]+SAMPLES_PER_MIC] * 1/3;
                    //printf("offset: %ld\n", offset_in_samples_ula1[j]);
                    //printf("sample with os: %ld\n", memory_pointer_old*NUMBER_OF_MICS*SAMPLES_PER_MIC+ula1_mic_list[j]*SAMPLES_PER_MIC+i+offset_in_samples_ula1[j]+SAMPLES_PER_MIC);
                    //printf("jamen, %ld\n", i+offset_in_samples_ula1[j]+SAMPLES_PER_MIC);
                } else{
                    ula1_output_summed[i] += mic_inputs_big[memory_pointer_middle*NUMBER_OF_MICS*SAMPLES_PER_MIC+ula1_mic_list[j]*SAMPLES_PER_MIC+i+offset_in_samples_ula1[j]] * 1/3;
                    //printf("mic no.: %ld\n", ula1_mic_list[j]);
                    //printf("sample in mid buffer: %ld\n", memory_pointer_middle*NUMBER_OF_MICS*SAMPLES_PER_MIC+ula1_mic_list[j]*SAMPLES_PER_MIC+i+offset_in_samples_ula1[j]);
                }
                // ULA2
                if ((i + offset_in_samples_ula2[j]) >= SAMPLES_PER_MIC){ 
                // offset is positive (forwards in time), meaning rightmost mic of ULA is furthest away
                    ula2_output_summed[i] += mic_inputs_big[memory_pointer_new*NUMBER_OF_MICS*SAMPLES_PER_MIC+ula2_mic_list[j]*SAMPLES_PER_MIC+i+offset_in_samples_ula2[j]-SAMPLES_PER_MIC] * 1/3;

                } else if((i + offset_in_samples_ula2[j]) < 0){ 
                    ula2_output_summed[i] += mic_inputs_big[memory_pointer_old*NUMBER_OF_MICS*SAMPLES_PER_MIC+ula2_mic_list[j]*SAMPLES_PER_MIC+i+offset_in_samples_ula2[j]+SAMPLES_PER_MIC] * 1/3;
                } else{
                    ula2_output_summed[i] += mic_inputs_big[memory_pointer_middle*NUMBER_OF_MICS*SAMPLES_PER_MIC+ula2_mic_list[j]*SAMPLES_PER_MIC+i+offset_in_samples_ula2[j]] * 1/3;
                }
                 // ULA3
                if ((i + offset_in_samples_ula3[j]) >= SAMPLES_PER_MIC){ 
                // offset is positive (forwards in time), meaning rightmost mic of ULA is furthest away
                    ula3_output_summed[i] += mic_inputs_big[memory_pointer_new*NUMBER_OF_MICS*SAMPLES_PER_MIC+ula3_mic_list[j]*SAMPLES_PER_MIC+i+offset_in_samples_ula3[j]-SAMPLES_PER_MIC] * 1/3;

                } else if((i + offset_in_samples_ula3[j]) < 0){ 
                    ula3_output_summed[i] += mic_inputs_big[memory_pointer_old*NUMBER_OF_MICS*SAMPLES_PER_MIC+ula3_mic_list[j]*SAMPLES_PER_MIC+i+offset_in_samples_ula3[j]+SAMPLES_PER_MIC] * 1/3;
                } else{
                    ula3_output_summed[i] += mic_inputs_big[memory_pointer_middle*NUMBER_OF_MICS*SAMPLES_PER_MIC+ula3_mic_list[j]*SAMPLES_PER_MIC+i+offset_in_samples_ula3[j]] * 1/3;
                }
            }
        }

        //for (int i = 0; i < SAMPLES_PER_MIC; i++){
        //    ula_output_summed[i] = (ula1_output_summed[i]+ula2_output_summed[i]+ula3_output_summed[i])*1/3; // combined 1/3 pga. før filter
        // }

        memory_pointer_old = memory_pointer_middle;
        memory_pointer_middle = memory_pointer_new;
        memory_pointer_new++;
        if (memory_pointer_new > 2){        // Ascending
            memory_pointer_new = 0;
        }else if (memory_pointer_new < 0){  // Descending
            memory_pointer_new = 2;
        }

        //printf("Delay line \n");
        //for (int i = 0; i < FIR1LENGTH; i++){
        //    printf("%f\n",delay_line_ula1[i]);
        //}        

        //uint32_t firstart = dsp_get_cpu_cycle_count();
        //dsps_fird_f32_ae32(&fir_ula1, ula1_output_summed, fir_out_ula1, N_buff);
        //dsps_fird_f32(&fir_ula1, ula1_output_summed, fir_out_ula1, N_buff / fir_decim);
        dsps_fir_f32(&fir_ula1, ula1_output_summed, fir_out_ula1, SAMPLES_PER_MIC); //FIR1LENGTH +
        //printf("Fir1: %ld\n", dsp_get_cpu_cycle_count()-firstart);
        //dsps_fird_f32_ae32(&fir_ula2, ula2_output_summed, fir_out_ula2, N_buff);
        //dsps_fird_f32(&fir_ula2, ula2_output_summed, fir_out_ula2, N_buff / fir_decim);
        dsps_fir_f32(&fir_ula2, ula2_output_summed, fir_out_ula2, SAMPLES_PER_MIC);
        //printf("Fir2: %ld\n", dsp_get_cpu_cycle_count()-firstart);
        //dsps_fird_f32_ae32(&fir_ula3, ula3_output_summed, fir_out_ula3, N_buff);
        //dsps_fird_f32(&fir_ula3, ula3_output_summed, fir_out_ula3, N_buff / fir_decim);
        dsps_fir_f32(&fir_ula3, ula3_output_summed, fir_out_ula3, SAMPLES_PER_MIC);
        //printf("Fir3: %ld\n", dsp_get_cpu_cycle_count()-firstart);
        
        //printf("Outputs \n");
        //for (int i = 0; i < SAMPLES_PER_MIC; i++){
        //     printf("%f\n",fir_out_ula1[i]);
        //}        

        for (int i = 0; i < SAMPLES_PER_MIC; i++){
            //fir_output_summed[i] = fir_out_ula1[FIR1LENGTH+i] + fir_out_ula2[FIR2LENGTH+i] + fir_out_ula3[FIR3LENGTH+i]; //+ fir_out_ula2[FIR1LENGTH+i] + fir_out_ula3[FIR1LENGTH+i]; // combined
            fir_output_summed[i] = fir_out_ula1[i] + fir_out_ula2[i] + fir_out_ula3[i]; //+ fir_out_ula2[FIR1LENGTH+i] + fir_out_ula3[FIR1LENGTH+i]; // combined
        }
        
        memcpy(&wifiOutputArray, mic_inputs, NUMBER_OF_MICS*SAMPLES_PER_MIC*sizeof(float));
        
        memcpy(&wifiOutputArray[NUMBER_OF_MICS*SAMPLES_PER_MIC], fir_output_summed, (SAMPLES_PER_MIC)*sizeof(float));
        //memcpy(&wifiOutputArray[NUMBER_OF_MICS*SAMPLES_PER_MIC], ula_output_summed, (SAMPLES_PER_MIC)*sizeof(float));

        //testArray[3584] = {1};
        //for (int i = 0; i < 3584/4; i++){
        //    testArray[i] = i/(i+0.1234f);
        //}
        
        //xQueueSend(wifiQueue, &ula1_output_summed, ( TickType_t ) 0 );
        xQueueSend(wifiQueue, &wifiOutputArray, ( TickType_t ) 0 );
        //xQueueSend(wifiQueue, &mic_inputs, ( TickType_t ) 0 ); //&
        //xQueueSend(wifiQueue, &mic_inputs, ( TickType_t ) 0 ); //&
        //dastime = dsp_get_cpu_cycle_count();
        ////////////////////////// DAS MAIN END /////////////////////////////////
        
        //vTaskDelay(pdMS_TO_TICKS(1000)); // Example: Delay for 1 second
        /*        
        bytecount += t.trans_len / 8;

        if (esp_timer_get_time() - timer > 1000000) {
            printf("Bits per second: %lld\n", bytecount);
            printf("wifi: %lld\n", wificount);
            printf("Seconds: %lld\n", esp_timer_get_time() - timer);
            printf("Behind: %lld\n", wifbehind);
            timer = esp_timer_get_time();
            bytecount = 0;ata_2024-05-15 16:22:57.793140
            wificount = 0;
        }
        */
        //spi_slave_transmit does not return until the master has done a transmission, so by here we have sent our data and
        //received data from the master. Print it.
        //printf("Received: %s\n", recvbuf);

        //for (int i = 0; i < 16; i++) {
        //    printf("%02x", recvbuf[i]);
        //}
        //printf("\n");
        //printf("First byte: %02x ", recvbuf[0]);
        //printf("Last byte: %02x ", recvbuf[127]);
        //printf("Transaction length in bits: %d\n", t.trans_len);

        /*
            Try to move this logic into ISR.
        */
        }
    }

}