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



// Find ud af hvordan bytes per burst og request per burst skal sættes
#define DMA_BYTES_PER_BURST 1
#define DMA_REQUEST_PER_BURST 1
#define DMA_SRC_BASE (CYDEV_PERIPH_BASE)
#define DMA_DST_BASE (CYDEV_SRAM_BASE)

// Assuming a buffer size of 1024 bytes for demonstration
#define BUFFER_SIZE 1024

uint8_t soundBuffer_I2S[BUFFER_SIZE];


// DMA Configuration Variables
uint8 dmaChannel;
uint8 dmaTd;


volatile uint16 dmaIndex = 0;
uint16 cpuIndex = 0;

void initComponents(void);
void initDMA(void);

CY_ISR_PROTO(DmaI2S);

char hex_string[13];
char newline[6] = "\r\n";



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    initComponents();

    uint32_t* data = (uint32_t*)soundBuffer_I2S;
    size_t num_values = BUFFER_SIZE / sizeof(uint32_t);
    
    for(;;)
    {

            
            if (dmaIndex > 0) {
                for (size_t i = 0; i < num_values; i++) {
                    
                
                    sprintf(hex_string, "%08X\r\n", data[i]);
                    USBUART_PutString(hex_string);
                    dmaIndex = 0;
                }
            }
            
            //CyDelay(1000);
            //sprintf(hex_string, "%08lX\r\n", dmaIndex);
            //    USBUART_PutString(hex_string);
            //   dmaIndex = 0;

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
                                   HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_SRAM_BASE));
    
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
    dmaIndex += 1;
}


/* [] END OF FILE */