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
#include <stdlib.h>




#define DMA_BYTES_PER_BURST 4
#define DMA_REQUEST_PER_BURST 1
#define DMA_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_DST_BASE (CYDEV_SRAM_BASE)

// Assuming a buffer size of 1024 bytes for demonstration
#define BUFFER_SIZE 1024

uint8 soundBuffer_I2S[BUFFER_SIZE];


// DMA Configuration Variables
uint8 dmaChannel;
uint8 dmaTd;


volatile uint16 dmaIndex = 0;
uint16 cpuIndex = 0;

void initComponents(void);
void initDMA(void);
void OutputAudioValuesToUSBUART(uint32* buffer, uint16 start, uint16 numSamples);

CY_ISR_PROTO(DmaI2S);


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    initComponents();
    char str[12]; // Buffer for decimal representation
    
    for(;;)
    {

        if (dmaIndex != cpuIndex) {
            cpuIndex = dmaIndex;

            // Assuming cpuIndex is properly initialized and within bounds of soundBuffer_I2S
            // Extract the first byte and perform sign extension.
            int32_t value = 0;
            
            value |= soundBuffer_I2S[cpuIndex]     << 24; // Shift the first byte 24 bits to the left
            value |= soundBuffer_I2S[cpuIndex + 1] << 16; // Shift the second byte 16 bits to the left
            value |= soundBuffer_I2S[cpuIndex + 2] << 8;  // Shift the third byte 8 bits to the left
            value |= soundBuffer_I2S[cpuIndex + 3];       // No shift needed for the fourth byte

            // Note: sampleValue is already a signed 32-bit integer due to the sign extension performed.

            // Preparing for UART transmission
            char str[15]; // Adjusted size for "-2147483648\r\n\0"
            sprintf(str, "%ld\r\n", value); // Convert the integer to a string and append \r\n for newline

            
            USBUART_PutString(str);
        }
                //CyDelay(10); // Delay to control the output rate (for demonstration purposes)
        //}
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
    
    DmaI2S_StartEx(&DmaI2S);
    


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
    CyDmaTdSetAddress(dmaTd, LO16((uint32)I2S_RX_CH0_F0_PTR), LO16((uint32)soundBuffer_I2S));
    
    /* Step 5: Set the initial TD for the channel */
    CyDmaChSetInitialTd(dmaChannel, dmaTd);
    
    /* Step 6: Enable the DMA channel */
    CyDmaChEnable(dmaChannel, 1);
    
    
}




CY_ISR(DmaI2S) {
    if (dmaIndex + 4 > BUFFER_SIZE) {
        dmaIndex = 0;
    } else {
        dmaIndex = dmaIndex + 4;
    }

}


/* [] END OF FILE */