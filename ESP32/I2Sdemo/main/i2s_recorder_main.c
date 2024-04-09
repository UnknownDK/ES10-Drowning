#include "driver/i2s.h"
#include "esp_log.h"
#include <inttypes.h>



#include "esp_task_wdt.h"




#include <stdlib.h> // For abs()
#include <stdio.h>

#define I2S_NUM         I2S_NUM_0
#define I2S_SAMPLE_RATE 12000
#define I2S_SAMPLE_BITS 32
#define I2S_BUFFER_SIZE 512 // Size in bytes



static const char *TAG = "I2S_MIC";

// Function to print the binary representation of an integer
void print_binary(int32_t number) {
    for (int i = 31; i >= 0; i--) {
        putchar('0' + ((number >> i) & 1));
    }
    putchar('\n'); // Newline after printing the binary number
}

void i2s_mic_init() {
    i2s_config_t i2s_config = {
        .mode = I2S_MODE_MASTER | I2S_MODE_RX,
        .sample_rate = I2S_SAMPLE_RATE,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
        .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT, // Assuming mono microphone
        .communication_format = I2S_COMM_FORMAT_I2S,
        .intr_alloc_flags = 0, // Default interrupt priority
        .dma_buf_count = 4,
        .dma_buf_len = 1024,
        .use_apll = false,
    };

    i2s_pin_config_t pin_config = {
        .bck_io_num = 26, // SCK, replace with your actual pin number
        .ws_io_num = 20, // WS, replace with your actual pin number
        .data_out_num = I2S_PIN_NO_CHANGE, // Not used
        .data_in_num = 21, // DATA, replace with your actual pin number
    };

    i2s_driver_install(I2S_NUM, &i2s_config, 0, NULL);
    i2s_set_pin(I2S_NUM, &pin_config);
    i2s_zero_dma_buffer(I2S_NUM);
}

int32_t raw_samples[I2S_BUFFER_SIZE];

void log_audio_samples() {
    


    size_t bytes_read = 0;
    while (1) {
        //i2s_read(I2S_NUM, i2s_data, I2S_BUFFER_SIZE, &bytes_read, portMAX_DELAY);
        
          
        i2s_read(I2S_NUM_0, raw_samples, sizeof(int32_t) * I2S_BUFFER_SIZE, &bytes_read, portMAX_DELAY);
        int samples_read = bytes_read / sizeof(int32_t);
        // dump the samples out to the serial channel.
        for (int i = 0; i < samples_read; i++)
        {

            //fwrite(&raw_samples[i], sizeof(raw_samples[i]), 1, stdout);
            //fflush(stdout); // Ensure the data is sent immediately
            printf("%ld\n", raw_samples[i]);
            //print_binary(raw_samples[i]);
            //printf("%" "\n", );
        }
        
        //for (int i = 0; i < bytes_read; i += 4) {
            // Extracting 24-bit audio sample and converting to 32-bit integer
            //int32_t sample = (int32_t)(i2s_data[i+1] << 8 | (i2s_data[i + 2] << 16) | (i2s_data[i + 3] << 24));

            //
            //int32_t abs_sample = abs(sample);
            

            //fwrite(&sample, sizeof(sample), 1, stdout);
            //fflush(stdout); // Ensure the data is sent immediately
            //printf("%" PRId32 "\n", sample);
        //}

    }
    //free(i2s_data);
}

void app_main(void) {
    esp_task_wdt_deinit();
    i2s_mic_init();
    log_audio_samples(); // This function will continuously log audio samples
}



