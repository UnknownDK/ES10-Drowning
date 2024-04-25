/***************************************************************************
* File Name: I2S_DMA_eight_dma.c  
* Version 1.70
*
*  Description:
*   Provides an API for the DMAC component. The API includes functions
*   for the DMA controller, DMA channels and Transfer Descriptors.
*
*
*   Note:
*     This module requires the developer to finish or fill in the auto
*     generated funcions and setup the dma channel and TD's.
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#include <CYLIB.H>
#include <CYDMAC.H>
#include <I2S_DMA_eight_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* I2S_DMA_eight__DRQ_CTL_REG
* 
* 
* I2S_DMA_eight__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* I2S_DMA_eight__NUMBEROF_TDS
* 
* Priority of this channel.
* I2S_DMA_eight__PRIORITY
* 
* True if I2S_DMA_eight_TERMIN_SEL is used.
* I2S_DMA_eight__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* I2S_DMA_eight__TERMIN_SEL
* 
* 
* True if I2S_DMA_eight_TERMOUT0_SEL is used.
* I2S_DMA_eight__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* I2S_DMA_eight__TERMOUT0_SEL
* 
* 
* True if I2S_DMA_eight_TERMOUT1_SEL is used.
* I2S_DMA_eight__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* I2S_DMA_eight__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of I2S_DMA_eight dma channel */
uint8 I2S_DMA_eight_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 I2S_DMA_eight_DmaInitalize
**********************************************************************
* Summary:
*   Allocates and initialises a channel of the DMAC to be used by the
*   caller.
*
* Parameters:
*   BurstCount.
*       
*       
*   ReqestPerBurst.
*       
*       
*   UpperSrcAddress.
*       
*       
*   UpperDestAddress.
*       
*
* Return:
*   The channel that can be used by the caller for DMA activity.
*   DMA_INVALID_CHANNEL (0xFF) if there are no channels left. 
*
*
*******************************************************************/
uint8 I2S_DMA_eight_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    I2S_DMA_eight_DmaHandle = (uint8)I2S_DMA_eight__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(I2S_DMA_eight_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)I2S_DMA_eight__TERMOUT0_SEL,
                                  (uint8)I2S_DMA_eight__TERMOUT1_SEL,
                                  (uint8)I2S_DMA_eight__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(I2S_DMA_eight_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(I2S_DMA_eight_DmaHandle, (uint8)I2S_DMA_eight__PRIORITY);
    
    return I2S_DMA_eight_DmaHandle;
}

/*********************************************************************
* Function Name: void I2S_DMA_eight_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with I2S_DMA_eight.
*
*
* Parameters:
*   void.
*
*
*
* Return:
*   void.
*
*******************************************************************/
void I2S_DMA_eight_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(I2S_DMA_eight_DmaHandle);
}

