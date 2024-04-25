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


uint8_t I2S_buf_one[BUFFER_SIZE];
uint8_t I2S_buf_two[BUFFER_SIZE];
uint8_t I2S_buf_three[BUFFER_SIZE];
uint8_t I2S_buf_four[BUFFER_SIZE];
uint8_t I2S_buf_five[BUFFER_SIZE];
uint8_t I2S_buf_six[BUFFER_SIZE];
uint8_t I2S_buf_seven[BUFFER_SIZE];
uint8_t I2S_buf_eight[BUFFER_SIZE];

uint8_t soundBuffer_I2S_copy[BUFFER_SIZE];
uint8_t interBuffer[BUFFER_SIZE / 2];
uint8_t bruh[128];
uint8_t uppit = 0;
// DMA Configuration Variables
uint8 i2sChannelOne;
uint8 i2sChannelTwo;
uint8 i2sChannelThree;
uint8 i2sChannelFour;
uint8 i2sChannelFive;
uint8 i2sChannelSix;
uint8 i2sChannelSeven;
uint8 i2sChannelEight;

uint8 dmaTdi2sOne;
uint8 dmaTdi2sTwo;
uint8 dmaTdi2sThree;
uint8 dmaTdi2sFour;
uint8 dmaTdi2sFive;
uint8 dmaTdi2sSix;
uint8 dmaTdi2sSeven;
uint8 dmaTdi2sEight;



volatile uint16 dmaIndexOne = 0;
volatile uint16 dmaIndexTwo = 0;
volatile uint16 dmaIndexThree = 0;
volatile uint16 dmaIndexFour = 0;
volatile uint16 dmaIndexFive = 0;
volatile uint16 dmaIndexSix = 0;
volatile uint16 dmaIndexSeven = 0;
volatile uint16 dmaIndexEight = 0;

uint16 cpuIndex = 0;

void initComponents(void);
void initDMA(void);

CY_ISR_PROTO(DmaI2S_one);
CY_ISR_PROTO(DmaI2S_two);
CY_ISR_PROTO(DmaI2S_three);
CY_ISR_PROTO(DmaI2S_four);
CY_ISR_PROTO(DmaI2S_five);
CY_ISR_PROTO(DmaI2S_six);
CY_ISR_PROTO(DmaI2S_seven);
CY_ISR_PROTO(DmaI2S_eight);


char hex_string[13];


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    initComponents();


    
    for(;;)
    {
        
        
                // Wait for DMA transfer completion
        if (dmaIndexOne != 0 && dmaIndexThree != 0) {
            SPIM_ClearTxBuffer();
            for(int i=0;i<1024;i=i+4){
                SPIM_WriteTxData(I2S_buf_one[i]);
                SPIM_WriteTxData(I2S_buf_one[i+1]);
                SPIM_WriteTxData(I2S_buf_three[i]);
                SPIM_WriteTxData(I2S_buf_three[i+1]);
            }
            
            //for(int i=0;i<BUFFER_SIZE/2;i++){
            //    SPIM_WriteTxData(soundBuffer_I2S[i] << 8 | soundBuffer_I2S[i+1]);
                //interBuffer[i] = soundBuffer_I2S[i*2];
            //}
            
            
            //UART_PutArray(soundBuffer_I2S, 1024);
            //SPIM_WriteTxData(0x23);
            //CyDelay(1000);
            //for (int i=0;i<128;i++){
            //    bruh[i] = uppit;
            //}
            dmaIndexOne = 0;
            dmaIndexTwo = 0;
            dmaIndexThree = 0;
            dmaIndexFour = 0;
            dmaIndexFive = 0;
            dmaIndexSix = 0;
            dmaIndexSeven = 0;
            dmaIndexEight = 0;
        }
        
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
    I2Sone_Start();    
    I2Stwo_Start();
    I2Sthree_Start();
    I2Sfour_Start();
    I2Sfive_Start();
    I2Ssix_Start();
    I2Sseven_Start();
    I2Seight_Start();
    
    I2Sone_EnableRx();
    I2Stwo_EnableRx();
    I2Sthree_EnableRx();
    I2Sfour_EnableRx();
    I2Sfive_EnableRx();
    I2Ssix_EnableRx();
    I2Sseven_EnableRx();
    I2Seight_EnableRx();
    
    SPIM_Start();
   
    SPIM_ClearTxBuffer();
    SPIM_ClearFIFO();
    //UART_Start();
    
    DmaI2S_one_StartEx(&DmaI2S_one);
    DmaI2S_two_StartEx(&DmaI2S_two);
    DmaI2S_three_StartEx(&DmaI2S_three);
    DmaI2S_four_StartEx(&DmaI2S_four);
    DmaI2S_five_StartEx(&DmaI2S_five);
    DmaI2S_six_StartEx(&DmaI2S_six);
    DmaI2S_seven_StartEx(&DmaI2S_seven);
    DmaI2S_eight_StartEx(&DmaI2S_eight);
    
    
    


}


void initDMA(void) {
    /* Step 1: DMA Initialization */
    i2sChannelOne = I2S_DMA_one_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, 
                                   HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_SRAM_BASE));
    i2sChannelTwo = I2S_DMA_two_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, 
                                   HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_SRAM_BASE));
    i2sChannelThree = I2S_DMA_three_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, 
                                   HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_SRAM_BASE));
    i2sChannelFour = I2S_DMA_four_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, 
                                   HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_SRAM_BASE));
    i2sChannelFive = I2S_DMA_five_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, 
                                   HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_SRAM_BASE));
    i2sChannelSix = I2S_DMA_six_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, 
                                   HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_SRAM_BASE));
    i2sChannelSeven = I2S_DMA_seven_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, 
                                   HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_SRAM_BASE));
    i2sChannelEight = I2S_DMA_eight_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, 
                                   HI16(CYDEV_PERIPH_BASE), HI16(CYDEV_SRAM_BASE));
    /* Step 2: Allocate TD */
    dmaTdi2sOne = CyDmaTdAllocate();
    dmaTdi2sTwo = CyDmaTdAllocate();
    dmaTdi2sThree = CyDmaTdAllocate();
    dmaTdi2sFour = CyDmaTdAllocate();
    dmaTdi2sFive = CyDmaTdAllocate();
    dmaTdi2sSix = CyDmaTdAllocate();
    dmaTdi2sSeven = CyDmaTdAllocate();
    dmaTdi2sEight = CyDmaTdAllocate();


    // Det her virkede! men ændrede det for at se hvad DMA Wizard kunne
    /* Step 3: Configure the TD */ 
    CyDmaTdSetConfiguration(dmaTdi2sOne, BUFFER_SIZE, dmaTdi2sOne, 
                            CY_DMA_TD_INC_DST_ADR | I2S_DMA_one__TD_TERMOUT_EN);
    CyDmaTdSetConfiguration(dmaTdi2sTwo, BUFFER_SIZE, dmaTdi2sTwo, 
                            CY_DMA_TD_INC_DST_ADR | I2S_DMA_two__TD_TERMOUT_EN);
    CyDmaTdSetConfiguration(dmaTdi2sThree, BUFFER_SIZE, dmaTdi2sThree, 
                            CY_DMA_TD_INC_DST_ADR | I2S_DMA_three__TD_TERMOUT_EN);    
    CyDmaTdSetConfiguration(dmaTdi2sFour, BUFFER_SIZE, dmaTdi2sFour, 
                            CY_DMA_TD_INC_DST_ADR | I2S_DMA_four__TD_TERMOUT_EN);
    CyDmaTdSetConfiguration(dmaTdi2sFive, BUFFER_SIZE, dmaTdi2sFive, 
                            CY_DMA_TD_INC_DST_ADR | I2S_DMA_five__TD_TERMOUT_EN);
    CyDmaTdSetConfiguration(dmaTdi2sSix, BUFFER_SIZE, dmaTdi2sSix, 
                            CY_DMA_TD_INC_DST_ADR | I2S_DMA_six__TD_TERMOUT_EN);
    CyDmaTdSetConfiguration(dmaTdi2sSeven, BUFFER_SIZE, dmaTdi2sSeven, 
                            CY_DMA_TD_INC_DST_ADR | I2S_DMA_seven__TD_TERMOUT_EN);
    CyDmaTdSetConfiguration(dmaTdi2sEight, BUFFER_SIZE, dmaTdi2sEight, 
                            CY_DMA_TD_INC_DST_ADR | I2S_DMA_eight__TD_TERMOUT_EN);
    
    /* Step 4: Set the source and destination addresses */
    CyDmaTdSetAddress(dmaTdi2sOne, LO16((uint32)I2Sone_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_one));
    CyDmaTdSetAddress(dmaTdi2sTwo, LO16((uint32)I2Stwo_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_two));
    CyDmaTdSetAddress(dmaTdi2sThree, LO16((uint32)I2Sthree_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_three));
    CyDmaTdSetAddress(dmaTdi2sFour, LO16((uint32)I2Sfour_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_four));
    CyDmaTdSetAddress(dmaTdi2sFive, LO16((uint32)I2Sfive_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_five));
    CyDmaTdSetAddress(dmaTdi2sSix, LO16((uint32)I2Ssix_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_six));
    CyDmaTdSetAddress(dmaTdi2sSeven, LO16((uint32)I2Sseven_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_seven));
    CyDmaTdSetAddress(dmaTdi2sEight, LO16((uint32)I2Seight_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_eight));
    
    
    /* Step 5: Set the initial TD for the channel */
    CyDmaChSetInitialTd(i2sChannelOne, dmaTdi2sOne);
    CyDmaChSetInitialTd(i2sChannelTwo, dmaTdi2sTwo);
    CyDmaChSetInitialTd(i2sChannelThree, dmaTdi2sThree);
    CyDmaChSetInitialTd(i2sChannelFour, dmaTdi2sFour);
    CyDmaChSetInitialTd(i2sChannelFive, dmaTdi2sFive);
    CyDmaChSetInitialTd(i2sChannelSix, dmaTdi2sSix);
    CyDmaChSetInitialTd(i2sChannelSeven, dmaTdi2sSeven);
    CyDmaChSetInitialTd(i2sChannelEight, dmaTdi2sEight);
    
    /* Step 6: Enable the DMA channel */
    CyDmaChEnable(i2sChannelOne, 1);
    CyDmaChEnable(i2sChannelTwo, 1);
    CyDmaChEnable(i2sChannelThree, 1);
    CyDmaChEnable(i2sChannelFour, 1);
    CyDmaChEnable(i2sChannelFive, 1);
    CyDmaChEnable(i2sChannelSix, 1);
    CyDmaChEnable(i2sChannelSeven, 1);
    CyDmaChEnable(i2sChannelEight, 1);
    
    
}





CY_ISR(DmaI2S_one) {
    dmaIndexOne += 1;
}


CY_ISR(DmaI2S_two) {
    dmaIndexTwo += 1;
}

CY_ISR(DmaI2S_three) {
    dmaIndexThree += 1;
}

CY_ISR(DmaI2S_four) {
    dmaIndexFour += 1;
}
CY_ISR(DmaI2S_five) {
    dmaIndexFive += 1;
}
CY_ISR(DmaI2S_six) {
    dmaIndexSix += 1;
}
CY_ISR(DmaI2S_seven) {
    dmaIndexSeven += 1;
}
CY_ISR(DmaI2S_eight) {
    dmaIndexEight += 1;
}

/* [] END OF FILE */