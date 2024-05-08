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

#include "esp_log.h"
#include "driver/spi_slave.h"

#include "driver/gpio.h"



#include <esp_task_wdt.h>
#include "offloading.h"
#include "FIRWeights.h"
#include <math.h>
#include <esp_dsp.h>
#include <time.h>

#include "esp_timer.h"

#define RCV_HOST    SPI2_HOST

#define GPIO_MOSI           11 // P2[1]
#define GPIO_MISO           13 // P2[3]
#define GPIO_SCLK           10  // P2[0]
#define GPIO_CS             12  // P2[2]


int64_t timer = 0;
int64_t bytecount = 0;
int64_t wificount = 0;
int64_t wifbehind = 0;

WORD_ALIGNED_ATTR uint8_t recvbuf[3584];
uint8_t sendbuf[3584];



//Called after a transaction is queued and ready for pickup by master. We use this to set the handshake line high.
void my_post_setup_cb(spi_slave_transaction_t *trans)
{
    //gpio_set_level(GPIO_HANDSHAKE, 1);
}

//Called after transaction is sent/received. We use this to set the handshake line low.
void my_post_trans_cb(spi_slave_transaction_t *trans)
{
    //gpio_set_level(GPIO_HANDSHAKE, 1);
    memcpy(sendbuf, recvbuf, 3584);
    wifbehind += 1;

    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    // Prepare data_to_send
    xQueueSendFromISR(xQueue, &sendbuf, &xHigherPriorityTaskWoken);
    if(xHigherPriorityTaskWoken) {
        portYIELD_FROM_ISR();
    }
}



//Main application
void app_main(void)
{
    esp_task_wdt_deinit();



    wifi_init_sta();


    xQueue = xQueueCreate(10, 3584);

    xTaskCreatePinnedToCore(&socket_task, "socket_task", 8192, NULL, 5, NULL, 1);
    //xTaskCreatePinnedToCore(&spi_task, "spi_task", 4096, NULL, 1, NULL, 1);

    timer = esp_timer_get_time();
    bytecount = 0;


    //esp_err_t ret;

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


    //Enable pull-ups on SPI lines so we don't detect rogue pulses when no master is connected.
    gpio_set_pull_mode(GPIO_MOSI, GPIO_PULLUP_ONLY);
    gpio_set_pull_mode(GPIO_SCLK, GPIO_PULLUP_ONLY);
    gpio_set_pull_mode(GPIO_CS, GPIO_PULLUP_ONLY);

    //Initialize SPI slave interface
    esp_err_t ret;
    ret = spi_slave_initialize(RCV_HOST, &buscfg, &slvcfg, SPI_DMA_CH_AUTO);
    assert(ret == ESP_OK);

    //WORD_ALIGNED_ATTR uint8_t sendbuf[1024];
    
    //memset(recvbuf, 0, 33);
    spi_slave_transaction_t t;
    memset(&t, 0, sizeof(t));



    while (1) {


        //Clear receive buffer, set send buffer to something sane
        memset(recvbuf, 0xA, 3584);
        //sprintf(sendbuf, "This is the receiver, sending data for transmission number %04d.", n);

        //Set up a transaction of 128 bytes to send/receive
        t.length = 3584 * 8;
        t.tx_buffer = NULL;
        t.rx_buffer = recvbuf;
        /* This call enables the SPI slave interface to send/receive to the sendbuf and recvbuf. The transaction is
        initialized by the SPI master, however, so it will not actually happen until the master starts a hardware transaction
        by pulling CS low and pulsing the clock etc. In this specific example, we use the handshake line, pulled up by the
        .post_setup_cb callback that is called as soon as a transaction is ready, to let the master know it is free to transfer
        data.
        */
        ret = spi_slave_transmit(RCV_HOST, &t, portMAX_DELAY);

        //vTaskDelay(pdMS_TO_TICKS(1000)); // Example: Delay for 1 second
        /*        
        bytecount += t.trans_len / 8;

        if (esp_timer_get_time() - timer > 1000000) {
            printf("Bits per second: %lld\n", bytecount);
            printf("wifi: %lld\n", wificount);
            printf("Seconds: %lld\n", esp_timer_get_time() - timer);
            printf("Behind: %lld\n", wifbehind);
            timer = esp_timer_get_time();
            bytecount = 0;
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