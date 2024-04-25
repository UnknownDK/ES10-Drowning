/*******************************************************************************
* File Name: I2Sfive_PM.c
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

#include "I2Sfive.h"

static I2Sfive_BACKUP_STRUCT  I2Sfive_backup = {0u};


/*******************************************************************************
* Function Name: I2Sfive_SaveConfig
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
void I2Sfive_SaveConfig(void) 
{
    /* Nothing to save. All registers are retention. */
}


/*******************************************************************************
* Function Name: I2Sfive_RestoreConfig
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
void I2Sfive_RestoreConfig(void) 
{
    /* Nothing to restore. All registers are retention. */
}


/*******************************************************************************
* Function Name: I2Sfive_Sleep
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
*  I2Sfive_backup - used to store component state prior entering 
*    sleep mode.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2Sfive_Sleep(void) 
{
    /* Get component state */
    I2Sfive_backup.enableState = I2Sfive_CONTROL_REG;

    /* Stop component */
    I2Sfive_Stop();
}


/*******************************************************************************
* Function Name: I2Sfive_Wakeup
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
*  I2Sfive_backup - used to restore component state after exit from
*    sleep mode.
*
*******************************************************************************/
void I2Sfive_Wakeup(void) 
{
    #if (I2Sfive_DYNAMIC_BIT_RESOLUTION)
        I2Sfive_CONTROL_REG = I2Sfive_backup.enableState & I2Sfive_BIT_RESOLUTION_MODE_MASK;
    #endif /* I2Sfive_DYNAMIC_BIT_RESOLUTION */

    if(0u != (I2Sfive_backup.enableState & I2Sfive_EN))
    {
        /* Enable component's operation */
        I2Sfive_Enable();

        /* Enable Tx/Rx direction if they were enabled before sleep */
        #if(I2Sfive_TX_DIRECTION_ENABLE)
            if(0u != (I2Sfive_backup.enableState & I2Sfive_TX_EN))
            {
                I2Sfive_EnableTx();
            }
        #endif /* (I2Sfive_TX_DIRECTION_ENABLE) */
        
        #if(I2Sfive_RX_DIRECTION_ENABLE)
            if(0u != (I2Sfive_backup.enableState & I2Sfive_RX_EN))
            {
                I2Sfive_EnableRx();
            }
        #endif /* (I2Sfive_RX_DIRECTION_ENABLE) */
    }
}


/* [] END OF FILE */
