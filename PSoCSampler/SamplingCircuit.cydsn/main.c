/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>

#define I2S_CLOCK_FACTOR    (I2S_DATA_BITS*AUDIO_CH*2)
#define I2S_DATA_SIZE       (I2S_DATA_BITS/8*AUDIO_CH)
#define I2S_TRANSFER_SIZE   (TRANSFER_SIZE*I2S_DATA_SIZE)
#define I2S_BUFFER_SIZE     (I2S_TRANSFER_SIZE * NUM_OF_BUFFERS)


#define DMA_BYTES_PER_BURST 2
#define DMA_REQUEST_PER_BURST 1
#define DMA_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_DST_BASE (CYDEV_SRAM_BASE)

// Assuming a buffer size of 1024 bytes for demonstration
#define BUFFER_SIZE 1024

// Circular buffer
uint8 circularBuffer[BUFFER_SIZE];
uint16 writeIndex = 0; // Index where the DMA will write next
uint16 readIndex = 0;  // Index where the CPU will read next

// DMA Configuration Variables
uint8 dmaChannel;
uint8 dmaTd;




void initComponents(void);
void initDMA(void);
void OutputAudioValuesToUSBUART(uint8* buffer, uint16 start, uint16 numSamples);


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    initComponents();
    
    uint16 numSamplesToOutput = 1; // Example: Number of samples to output each time

    
    for(;;)
    {
        if (USBUART_GetConfiguration()) {
            // Assuming `readIndex` is updated elsewhere (e.g., in an ISR) to point to new data
            OutputAudioValuesToUSBUART(circularBuffer, readIndex, numSamplesToOutput);
            // Ensure `readIndex` management avoids buffer overrun and correctly handles wraparound
        }
        CyDelay(100); // Delay to control the output rate (for demonstration purposes)
    }
}


void initComponents() {
    /* Enable global interrupts. */
    CyGlobalIntEnable;


 
    USBUART_Start(0, USBUART_5V_OPERATION);
    
    while(USBUART_GetConfiguration()==0){}
    
    /* Start PGA for 3v3 generation. */
    I2S_3v3_Start();

    /* Start I2S */
    I2S_Start();
    I2S_EnableRx();
    
    initDMA();
    
    



}


void initDMA(void) {
    /* Step 1: DMA Initialization */
    dmaChannel = I2S_DMA_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, 
                                   HI16(DMA_SRC_BASE), HI16(DMA_DST_BASE));
    
    /* Step 2: Allocate TD */
    dmaTd = CyDmaTdAllocate();
    
    /* Step 3: Configure the TD */
    CyDmaTdSetConfiguration(dmaTd, BUFFER_SIZE, dmaTd, 
                            TD_INC_DST_ADR | I2S_DMA__TD_TERMOUT_EN);
    
    /* Step 4: Set the source and destination addresses */
    CyDmaTdSetAddress(dmaTd, LO16((uint32)I2S_RX_CH0_F0_PTR), LO16((uint32)circularBuffer));
    
    /* Step 5: Set the initial TD for the channel */
    CyDmaChSetInitialTd(dmaChannel, dmaTd);
    
    /* Step 6: Enable the DMA channel */
    CyDmaChEnable(dmaChannel, 1);
}



void OutputAudioValuesToUSBUART(uint8* buffer, uint16 start, uint16 numSamples) {
    char str[12]; // Buffer for decimal representation

    for (uint16 i = 0; i < numSamples; ++i) {
        uint32 index = (start + i * 4) % BUFFER_SIZE; // For 32-bit words
        // Extract the 24-bit audio data, assuming the relevant data is in the LSBs
        uint32 sample = (uint32)((buffer[index + 1] << 16) |
                                 (buffer[index + 2] << 8)  |
                                  buffer[index + 3]);

        // Assuming the 24-bit data is left-aligned and we need to ignore the 6 null bits,
        // we shift the sample right by 6 bits. This adjusts the 24-bit data to 18-bit precision.
        int32 signedSample = (sample >> 6) & 0x3FFFF; // Extract 18-bit precision data

        // For signed representation, adjust if necessary
        // Here you would handle sign extension if your data is in two's complement format
        // This example does not perform sign extension

        // Format the sample as a decimal integer string
        snprintf(str, sizeof(str), "%ld\r\n", signedSample);

        // Output routine remains the same
        while (!USBUART_GetConfiguration()) { /* Wait */ }
        while(!USBUART_CDCIsReady()) { /* Wait */ }
        USBUART_PutString(str);
    }
}



/* [] END OF FILE */
