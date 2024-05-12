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
#define BUFFER_SIZE 512
#define DATA_SIZE 384 // For now, half of buffer_size


uint8_t I2S_buf_one[BUFFER_SIZE*2];
uint8_t I2S_buf_two[BUFFER_SIZE*2];
uint8_t I2S_buf_three[BUFFER_SIZE*2];
uint8_t I2S_buf_four[BUFFER_SIZE*2];
uint8_t I2S_buf_five[BUFFER_SIZE*2];
uint8_t I2S_buf_six[BUFFER_SIZE*2];
uint8_t I2S_buf_seven[BUFFER_SIZE*2];



// DMA Configuration Variables  
uint8 i2sChannelOne;
uint8 i2sChannelTwo;
uint8 i2sChannelThree;
uint8 i2sChannelFour;
uint8 i2sChannelFive;
uint8 i2sChannelSix;
uint8 i2sChannelSeven;
uint8 spiChannel;

uint8 dmaTdi2sOne;
uint8 dmaTdi2sTwo;
uint8 dmaTdi2sThree;
uint8 dmaTdi2sFour;
uint8 dmaTdi2sFive;
uint8 dmaTdi2sSix;
uint8 dmaTdi2sSeven;




/* DMA Configuration for DMA_TX */
#define DMA_TX_BYTES_PER_BURST      (1u)
#define DMA_TX_REQUEST_PER_BURST    (1u)
#define DMA_TX_SRC_BASE             (CYDEV_SRAM_BASE)
#define DMA_TX_DST_BASE             (CYDEV_PERIPH_BASE)

#define START_DELAY 2 // 2


void DmaTxConfiguration();

/* Variable declarations for DMA_TX*/
uint8 txChannel;
uint8 txTD;

/* Variable declarations for InterruptControl Td*/
uint8_t InterruptControlTD;
uint8 InterruptControl; //this variable stores a copy of the SPI_TX_STATUS_MASK_REG with the SPI_INT_ON_TX_EMPTY bit cleared

uint8_t dataBuffer[DATA_SIZE*7]; //init the data buffer with some values here
uint16_t dataIdx;

volatile uint8 transFlag = 0;

volatile uint8 dmaIndexOne = 0;
volatile uint8 dmaIndexTwo = 0;
volatile uint8 dmaIndexThree = 0;
volatile uint8 dmaIndexFour = 0;
volatile uint8 dmaIndexFive = 0;
volatile uint8 dmaIndexSix = 0;
volatile uint8 dmaIndexSeven = 0;

uint8 circFlagOne = 0;
uint8 circFlagTwo = 0;
uint8 circFlagThree = 0;
uint8 circFlagFour = 0;
uint8 circFlagFive = 0;
uint8 circFlagSix = 0;
uint8 circFlagSeven = 0;

uint8 moveFlag = 0;
uint8 circFlag = 1;


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


char hex_string[13];

void moveBytes(uint8 *dest, uint8 *src, uint16 size) {
    uint8 *srcPtr = src;
    uint8 *destPtr = dest;
    
    for (int i = 0; i < size; i += 4) {
        *(destPtr++) = *(srcPtr++);
        *(destPtr++) = *(srcPtr++);
        *(destPtr++) = *(srcPtr++);
        
        srcPtr += 1; // Skip two bytes
    }
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    initComponents();

    
    for(;;)
    {
       if (dmaIndexOne != 0){
            CyDmaTdSetAddress(dmaTdi2sOne, LO16((uint32)I2Sone_RX_CH0_F0_PTR), LO16((uint32)&I2S_buf_one[BUFFER_SIZE*circFlag]));
            moveBytes(&dataBuffer[0], &I2S_buf_one[BUFFER_SIZE*moveFlag], BUFFER_SIZE);
            transFlag++;
            circFlagOne = (circFlagOne == 0) ? 1 : 0;
            
            dmaIndexOne = 0;
        }
       if (dmaIndexTwo != 0){
            CyDmaTdSetAddress(dmaTdi2sTwo, LO16((uint32)I2Stwo_RX_CH0_F0_PTR), LO16((uint32)&I2S_buf_two[BUFFER_SIZE*circFlag]));
            moveBytes(&dataBuffer[DATA_SIZE], &I2S_buf_two[BUFFER_SIZE*moveFlag], BUFFER_SIZE);
            transFlag++;
            circFlagTwo = (circFlagTwo == 0) ? 1 : 0;
            dmaIndexTwo = 0;
        }
        
       if (dmaIndexThree != 0){
            CyDmaTdSetAddress(dmaTdi2sThree, LO16((uint32)I2Sthree_RX_CH0_F0_PTR), LO16((uint32)&I2S_buf_three[BUFFER_SIZE*circFlag]));
            moveBytes(&dataBuffer[DATA_SIZE*2], &I2S_buf_three[BUFFER_SIZE*moveFlag], BUFFER_SIZE);
            transFlag++;
            circFlagThree = (circFlagThree == 0) ? 1 : 0;
             dmaIndexThree = 0;
        }
        
       if (dmaIndexFour != 0){
            CyDmaTdSetAddress(dmaTdi2sFour, LO16((uint32)I2Sfour_RX_CH0_F0_PTR), LO16((uint32)&I2S_buf_four[BUFFER_SIZE*circFlag]));
            moveBytes(&dataBuffer[DATA_SIZE*3], &I2S_buf_four[BUFFER_SIZE*moveFlag], BUFFER_SIZE);
            transFlag++;
            circFlagFour = (circFlagFour == 0) ? 1 : 0;
            dmaIndexFour = 0;
        }
       if (dmaIndexFive != 0){
            CyDmaTdSetAddress(dmaTdi2sFive, LO16((uint32)I2Sfive_RX_CH0_F0_PTR), LO16((uint32)&I2S_buf_five[BUFFER_SIZE*circFlag]));
            moveBytes(&dataBuffer[DATA_SIZE*4], &I2S_buf_five[BUFFER_SIZE*moveFlag], BUFFER_SIZE);
            transFlag++;
            circFlagFive = (circFlagFive == 0) ? 1 : 0;
            dmaIndexFive = 0;
        }
       if (dmaIndexSix != 0){
            CyDmaTdSetAddress(dmaTdi2sSix, LO16((uint32)I2Ssix_RX_CH0_F0_PTR), LO16((uint32)&I2S_buf_six[BUFFER_SIZE*circFlag]));
            moveBytes(&dataBuffer[DATA_SIZE*5], &I2S_buf_six[BUFFER_SIZE*moveFlag], BUFFER_SIZE);
            transFlag++;
            circFlagSix = (circFlagSix == 0) ? 1 : 0;
            dmaIndexSix = 0;
        }
       if (dmaIndexSeven != 0){
            CyDmaTdSetAddress(dmaTdi2sSeven, LO16((uint32)I2Sseven_RX_CH0_F0_PTR), LO16((uint32)&I2S_buf_seven[BUFFER_SIZE*circFlag]));
            moveBytes(&dataBuffer[DATA_SIZE*6], &I2S_buf_seven[BUFFER_SIZE*moveFlag], BUFFER_SIZE);
            transFlag++;
            circFlagSeven = (circFlagSeven == 0) ? 1 : 0;
            dmaIndexSeven = 0;
        }
        
                // Wait for DMA transfer completion
        //if (dmaIndexOne != 0 && dmaIndexTwo != 0 && dmaIndexThree != 0 && dmaIndexFour != 0 && dmaIndexFive != 0 && dmaIndexSix !=0 && dmaIndexSeven != 0) {
        if (transFlag > 5){
            SPIM_TX_STATUS_MASK_REG|=(SPIM_INT_ON_TX_EMPTY);          //start new transfer
            circFlag = (circFlag == 0) ? 1 : 0;
            moveFlag = (moveFlag == 0) ? 1 : 0;
            transFlag = 0;
        }
        

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
    CyDelay(START_DELAY);
    I2Stwo_Start();
    CyDelay(START_DELAY);
    I2Sthree_Start();
    CyDelay(START_DELAY);
    I2Sfour_Start();
    CyDelay(START_DELAY);
    I2Sfive_Start();
    CyDelay(START_DELAY);
    I2Ssix_Start();
    CyDelay(START_DELAY);
    I2Sseven_Start();
    CyDelay(START_DELAY);
    
    I2Sone_EnableRx();
    CyDelay(START_DELAY);
    I2Stwo_EnableRx();
    CyDelay(START_DELAY);
    I2Sthree_EnableRx();
    CyDelay(START_DELAY);
    I2Sfour_EnableRx();
    CyDelay(START_DELAY);
    I2Sfive_EnableRx();
    CyDelay(START_DELAY);
    I2Ssix_EnableRx();
    CyDelay(START_DELAY);
    I2Sseven_EnableRx();
    CyDelay(START_DELAY);
    
    SPIM_Start();
    SPIM_ClearFIFO();
    /* Disable the TX interrupt of SPIM */
    SPIM_TX_STATUS_MASK_REG&=(~SPIM_INT_ON_TX_EMPTY);
       
    /* Take a copy of SPIM_TX_STATUS_MASK_REG which will be used to disable the TX interrupt using DMA */
    InterruptControl=SPIM_TX_STATUS_MASK_REG;

    DmaTxConfiguration();
    
    CyDelay(START_DELAY);
    DmaI2S_one_StartEx(&DmaI2S_one);
    CyDelay(START_DELAY);
    DmaI2S_two_StartEx(&DmaI2S_two);
    CyDelay(START_DELAY);
    DmaI2S_three_StartEx(&DmaI2S_three);
    CyDelay(START_DELAY);
    DmaI2S_four_StartEx(&DmaI2S_four);
    CyDelay(START_DELAY);
    DmaI2S_five_StartEx(&DmaI2S_five);
    CyDelay(START_DELAY);
    DmaI2S_six_StartEx(&DmaI2S_six);
    CyDelay(START_DELAY);
    DmaI2S_seven_StartEx(&DmaI2S_seven);
    
    
    


}


void DmaTxConfiguration()
{
 /* Init DMA, 1 byte bursts, each burst requires a request */
    txChannel = DMA_TX_DmaInitialize(DMA_TX_BYTES_PER_BURST, DMA_TX_REQUEST_PER_BURST, HI16(((uint32)&dataBuffer[0])), HI16(((uint32)SPIM_TXDATA_PTR)));
   
    //Allocate TD to transfer x bytes
    txTD = CyDmaTdAllocate();
   
    //Allocate TD to disable the SPI Master TX interrupt
    InterruptControlTD = CyDmaTdAllocate();
   
    /* txTD = From the memory to the SPIM */
    CyDmaTdSetAddress(txTD, LO16(((uint32)&dataBuffer[0])), LO16(((uint32) SPIM_TXDATA_PTR)));
   
    /* Set the source address as variable 'InterruptControl' which stores the value 0 to disable the SPI_INT_ON_TX_EMPTY
	* and the destination is Control_Reg_SPIM_ctrl_reg__CONTROL_REG */
    CyDmaTdSetAddress(InterruptControlTD, (uint16)((uint32)&InterruptControl), (uint16)((uint32)&SPIM_TX_STATUS_MASK_REG));
   
    /* Set TD_tx transfer count as "burstLength" to transfer the data packet
    * Next Td as InterruptControlTD, and auto increment source address after each transaction .*/
    CyDmaTdSetConfiguration(txTD,DATA_SIZE*7,InterruptControlTD, TD_INC_SRC_ADR );
   
    /* Set InterruptControlTD with transfer count 1, next TD as txTD
    * Also enable the Terminal Output . This can be used to monitor whether transfer is complete */
	CyDmaTdSetConfiguration(InterruptControlTD,1,txTD, 0 );
   
    /* ************ Terminate the chain of TDs; this clears any pending request to the DMA************** */
    CyDmaChSetRequest(txChannel, CPU_TERM_CHAIN);
    CyDmaChEnable(txChannel,1);
   
    /* Set TD_tx as the initial TD associated with channel_tx */
    CyDmaChSetInitialTd(txChannel, txTD); 
   
    /* Enable the DMA channel - channel_tx */
    CyDmaChEnable(txChannel,1);
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
   
    /* Step 2: Allocate TD */
    dmaTdi2sOne = CyDmaTdAllocate();
    dmaTdi2sTwo = CyDmaTdAllocate();
    dmaTdi2sThree = CyDmaTdAllocate();
    dmaTdi2sFour = CyDmaTdAllocate();
    dmaTdi2sFive = CyDmaTdAllocate();
    dmaTdi2sSix = CyDmaTdAllocate();
    dmaTdi2sSeven = CyDmaTdAllocate();


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
    
    /* Step 4: Set the source and destination addresses */
    CyDmaTdSetAddress(dmaTdi2sOne, LO16((uint32)I2Sone_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_one));
    CyDmaTdSetAddress(dmaTdi2sTwo, LO16((uint32)I2Stwo_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_two));
    CyDmaTdSetAddress(dmaTdi2sThree, LO16((uint32)I2Sthree_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_three));
    CyDmaTdSetAddress(dmaTdi2sFour, LO16((uint32)I2Sfour_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_four));
    CyDmaTdSetAddress(dmaTdi2sFive, LO16((uint32)I2Sfive_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_five));
    CyDmaTdSetAddress(dmaTdi2sSix, LO16((uint32)I2Ssix_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_six));
    CyDmaTdSetAddress(dmaTdi2sSeven, LO16((uint32)I2Sseven_RX_CH0_F0_PTR), LO16((uint32)I2S_buf_seven));

    
    /* Step 5: Set the initial TD for the channel */
    CyDmaChSetInitialTd(i2sChannelOne, dmaTdi2sOne);
    CyDmaChSetInitialTd(i2sChannelTwo, dmaTdi2sTwo);
    CyDmaChSetInitialTd(i2sChannelThree, dmaTdi2sThree);
    CyDmaChSetInitialTd(i2sChannelFour, dmaTdi2sFour);
    CyDmaChSetInitialTd(i2sChannelFive, dmaTdi2sFive);
    CyDmaChSetInitialTd(i2sChannelSix, dmaTdi2sSix);
    CyDmaChSetInitialTd(i2sChannelSeven, dmaTdi2sSeven);
    
    /* Step 6: Enable the DMA channel */
    CyDmaChEnable(i2sChannelOne, 1);
    CyDmaChEnable(i2sChannelTwo, 1);
    CyDmaChEnable(i2sChannelThree, 1);
    CyDmaChEnable(i2sChannelFour, 1);
    CyDmaChEnable(i2sChannelFive, 1);
    CyDmaChEnable(i2sChannelSix, 1);
    CyDmaChEnable(i2sChannelSeven, 1);
    
    
}


CY_ISR(DmaI2S_one) {
    //int z = 0;
    //for(int i=0;i<512;i=i+4){
    //    dataBuffer[z] = I2S_buf_one[i];
    //    dataBuffer[z+1] = I2S_buf_one[i+1];
    //    z = z + 2;
    //}
    
    dmaIndexOne++;
}


CY_ISR(DmaI2S_two) {
    /*
    int z = 256;
    for(int i=0;i<512;i=i+4){
        dataBuffer[z] = I2S_buf_two[i];
        dataBuffer[z+1] = I2S_buf_two[i+1];
        z = z + 2;
    }*/
    dmaIndexTwo++;;
}

CY_ISR(DmaI2S_three) {
    /*
    int z = 512;
    for(int i=0;i<512;i=i+4){
        dataBuffer[z] = I2S_buf_three[i];
        dataBuffer[z+1] = I2S_buf_three[i+1];
        z = z + 2;
    }*/
    dmaIndexThree++;
}

CY_ISR(DmaI2S_four) {
    /*
    int z = 768;
    for(int i=0;i<512;i=i+4){
        dataBuffer[z] = I2S_buf_four[i];
        dataBuffer[z+1] = I2S_buf_four[i+1];
        z = z + 2;
    }*/
    dmaIndexFour++;
}
CY_ISR(DmaI2S_five) {
    /*
    int z = 1024;
    for(int i=0;i<512;i=i+4){
        dataBuffer[z] = I2S_buf_five[i];
        dataBuffer[z+1] = I2S_buf_five[i+1];
        z = z + 2;
    }*/
    dmaIndexFive++;
}
CY_ISR(DmaI2S_six) {
    /*
    int z = 1280;
    for(int i=0;i<512;i=i+4){
        dataBuffer[z] = I2S_buf_six[i];
        dataBuffer[z+1] = I2S_buf_six[i+1];
        z = z + 2;
    }*/
    dmaIndexSix++;
}
CY_ISR(DmaI2S_seven) {
    /*
    int z = 1536;
    for(int i=0;i<512;i=i+4){
        dataBuffer[z] = I2S_buf_seven[i];
        dataBuffer[z+1] = I2S_buf_seven[i+1];
        z = z + 2;
    }*/
    dmaIndexSeven++;
}

/* [] END OF FILE */