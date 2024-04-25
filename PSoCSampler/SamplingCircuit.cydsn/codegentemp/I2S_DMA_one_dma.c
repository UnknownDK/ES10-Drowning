/***************************************************************************
* File Name: I2S_DMA_one_dma.c  
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
#include <I2S_DMA_one_dma.H>



/****************************************************************************
* 
* The following defines are available in Cyfitter.h
* 
* 
* 
* I2S_DMA_one__DRQ_CTL_REG
* 
* 
* I2S_DMA_one__DRQ_NUMBER
* 
* Number of TD's used by this channel.
* I2S_DMA_one__NUMBEROF_TDS
* 
* Priority of this channel.
* I2S_DMA_one__PRIORITY
* 
* True if I2S_DMA_one_TERMIN_SEL is used.
* I2S_DMA_one__TERMIN_EN
* 
* TERMIN interrupt line to signal terminate.
* I2S_DMA_one__TERMIN_SEL
* 
* 
* True if I2S_DMA_one_TERMOUT0_SEL is used.
* I2S_DMA_one__TERMOUT0_EN
* 
* 
* TERMOUT0 interrupt line to signal completion.
* I2S_DMA_one__TERMOUT0_SEL
* 
* 
* True if I2S_DMA_one_TERMOUT1_SEL is used.
* I2S_DMA_one__TERMOUT1_EN
* 
* 
* TERMOUT1 interrupt line to signal completion.
* I2S_DMA_one__TERMOUT1_SEL
* 
****************************************************************************/


/* Zero based index of I2S_DMA_one dma channel */
uint8 I2S_DMA_one_DmaHandle = DMA_INVALID_CHANNEL;

/*********************************************************************
* Function Name: uint8 I2S_DMA_one_DmaInitalize
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
uint8 I2S_DMA_one_DmaInitialize(uint8 BurstCount, uint8 ReqestPerBurst, uint16 UpperSrcAddress, uint16 UpperDestAddress) 
{

    /* Allocate a DMA channel. */
    I2S_DMA_one_DmaHandle = (uint8)I2S_DMA_one__DRQ_NUMBER;

    /* Configure the channel. */
    (void)CyDmaChSetConfiguration(I2S_DMA_one_DmaHandle,
                                  BurstCount,
                                  ReqestPerBurst,
                                  (uint8)I2S_DMA_one__TERMOUT0_SEL,
                                  (uint8)I2S_DMA_one__TERMOUT1_SEL,
                                  (uint8)I2S_DMA_one__TERMIN_SEL);

    /* Set the extended address for the transfers */
    (void)CyDmaChSetExtendedAddress(I2S_DMA_one_DmaHandle, UpperSrcAddress, UpperDestAddress);

    /* Set the priority for this channel */
    (void)CyDmaChPriority(I2S_DMA_one_DmaHandle, (uint8)I2S_DMA_one__PRIORITY);
    
    return I2S_DMA_one_DmaHandle;
}

/*********************************************************************
* Function Name: void I2S_DMA_one_DmaRelease
**********************************************************************
* Summary:
*   Frees the channel associated with I2S_DMA_one.
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
void I2S_DMA_one_DmaRelease(void) 
{
    /* Disable the channel */
    (void)CyDmaChDisable(I2S_DMA_one_DmaHandle);
}

