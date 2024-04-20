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
uint8_t interBuffer[BUFFER_SIZE / 2];
uint8_t bruh[128];
uint8_t uppit = 0;
// DMA Configuration Variables
uint8 i2sChannel;
uint8 dmaTdi2s;


volatile uint16 dmaIndex = 0;
uint16 cpuIndex = 0;

void initComponents(void);
void initDMA(void);

CY_ISR_PROTO(DmaI2S);


char hex_string[13];


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    initComponents();


    for (int i=0;i<128;i++){
        bruh[i] = uppit;
        uppit++;
    }
    
    
    for(;;)
    {
        
        
                // Wait for DMA transfer completion
        //if (dmaIndex != 0) {
        //SPIM_ClearTxBuffer();
            for(int i=0;i<128;i++){
                SPIM_WriteTxData(bruh[i]);
            }
            
            //for(int i=0;i<BUFFER_SIZE/2;i++){
            //    SPIM_WriteTxData(soundBuffer_I2S[i] << 8 | soundBuffer_I2S[i+1]);
                //interBuffer[i] = soundBuffer_I2S[i*2];
            //}
            
            
            //UART_PutArray(soundBuffer_I2S, 1024);
            //SPIM_WriteTxData(0x23);
            CyDelay(1000);
            for (int i=0;i<128;i++){
                bruh[i] = uppit;
                uppit++;
            }
            //for (int i=0;i<128;i++){
            //    bruh[i] = uppit;
            //}
            dmaIndex = 0;
        //}
        
        // Process data and transfer to SPI

            /*
            if (dmaIndex > 0) {
                uint32_t* data = (uint32_t*)soundBuffer_I2S;
                size_t num_values = BUFFER_SIZE / sizeof(uint32_t);
                for (size_t i = 0; i < num_values; i++) {
                    sprintf(hex_string, "%08X\r\n", data[i]);
                    USBUART_PutString(hex_string);
                    dmaIndex = 0;
                }
            }*/
            
            //CyDelay(1000);
            //sprintf(hex_string, "%08lX\r\n", dmaIndex);
            //    USBUART_PutString(hex_string);
            //   dmaIndex = 0;

    }

}


void initComponents() {
    /* Enable global interrupts. */
    CyGlobalIntEnable;


 
    //USBUART_Start(0, USBUART_5V_OPERATION);
    
    //while(USBUART_GetConfiguration()==0){}
    
    /* Start PGA for 3v3 generation. */
    // I2S_3v3_Start();

    initDMA();
    
    /* Start I2S */
    I2S_Start();
    I2S_EnableRx();
    
    SPIM_Start();
   
    SPIM_ClearTxBuffer();
    SPIM_ClearFIFO();
    //UART_Start();
    
    DmaI2S_StartEx(&DmaI2S);
    
    
    


}


void initDMA(void) {
    /* Step 1: DMA Initialization */
    i2sChannel = I2S_DMA_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, 
                                   HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_SRAM_BASE));
    
    
    /* Step 2: Allocate TD */
    dmaTdi2s = CyDmaTdAllocate();

    // Det her virkede! men ændrede det for at se hvad DMA Wizard kunne
    /* Step 3: Configure the TD */ 
    CyDmaTdSetConfiguration(dmaTdi2s, BUFFER_SIZE, dmaTdi2s, 
                            CY_DMA_TD_INC_DST_ADR | I2S_DMA__TD_TERMOUT_EN);
    
    //CyDmaTdSetConfiguration(dmaTdi2s, 1024, dmaTdi2s,
    //                        I2S_DMA__TD_TERMOUT_EN | CY_DMA_TD_INC_DST_ADR);

    /* Step 4: Set the source and destination addresses */
    CyDmaTdSetAddress(dmaTdi2s, LO16((uint32)I2S_RX_CH0_F0_PTR), LO16((uint32)soundBuffer_I2S));

    
    
    /* Step 5: Set the initial TD for the channel */
    CyDmaChSetInitialTd(i2sChannel, dmaTdi2s);
    
    /* Step 6: Enable the DMA channel */
    CyDmaChEnable(i2sChannel, 1);
    
    
}





CY_ISR(DmaI2S) {
    dmaIndex += 1;
}


CY_ISR(DmaSPI) {

}

/* [] END OF FILE */