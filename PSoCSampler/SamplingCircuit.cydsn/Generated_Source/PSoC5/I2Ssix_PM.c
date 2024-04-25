/*******************************************************************************
* File Name: I2Ssix_PM.c
* Version 2.70
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2Ssix.h"

static I2Ssix_BACKUP_STRUCT  I2Ssix_backup = {0u};


/*******************************************************************************
* Function Name: I2Ssix_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Left to preserve backward compatibility.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void I2Ssix_SaveConfig(void) 
{
    /* Nothing to save. All registers are retention. */
}


/*******************************************************************************
* Function Name: I2Ssix_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Left to preserve backward compatibility.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void I2Ssix_RestoreConfig(void) 
{
    /* Nothing to restore. All registers are retention. */
}


/*******************************************************************************
* Function Name: I2Ssix_Sleep
********************************************************************************
*
* Summary:
*  Prepares I2S for entering sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  I2Ssix_backup - used to store component state prior entering 
*    sleep mode.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2Ssix_Sleep(void) 
{
    /* Get component state */
    I2Ssix_backup.enableState = I2Ssix_CONTROL_REG;

    /* Stop component */
    I2Ssix_Stop();
}


/*******************************************************************************
* Function Name: I2Ssix_Wakeup
********************************************************************************
*
* Summary:
*  Prepares I2S for exit from sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  I2Ssix_backup - used to restore component state after exit from
*    sleep mode.
*
*******************************************************************************/
void I2Ssix_Wakeup(void) 
{
    #if (I2Ssix_DYNAMIC_BIT_RESOLUTION)
        I2Ssix_CONTROL_REG = I2Ssix_backup.enableState & I2Ssix_BIT_RESOLUTION_MODE_MASK;
    #endif /* I2Ssix_DYNAMIC_BIT_RESOLUTION */

    if(0u != (I2Ssix_backup.enableState & I2Ssix_EN))
    {
        /* Enable component's operation */
        I2Ssix_Enable();

        /* Enable Tx/Rx direction if they were enabled before sleep */
        #if(I2Ssix_TX_DIRECTION_ENABLE)
            if(0u != (I2Ssix_backup.enableState & I2Ssix_TX_EN))
            {
                I2Ssix_EnableTx();
            }
        #endif /* (I2Ssix_TX_DIRECTION_ENABLE) */
        
        #if(I2Ssix_RX_DIRECTION_ENABLE)
            if(0u != (I2Ssix_backup.enableState & I2Ssix_RX_EN))
            {
                I2Ssix_EnableRx();
            }
        #endif /* (I2Ssix_RX_DIRECTION_ENABLE) */
    }
}


/* [] END OF FILE */
