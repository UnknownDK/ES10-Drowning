/*******************************************************************************
* File Name: I2S_4_PM.c
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

#include "I2S_4.h"

static I2S_4_BACKUP_STRUCT  I2S_4_backup = {0u};


/*******************************************************************************
* Function Name: I2S_4_SaveConfig
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
void I2S_4_SaveConfig(void) 
{
    /* Nothing to save. All registers are retention. */
}


/*******************************************************************************
* Function Name: I2S_4_RestoreConfig
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
void I2S_4_RestoreConfig(void) 
{
    /* Nothing to restore. All registers are retention. */
}


/*******************************************************************************
* Function Name: I2S_4_Sleep
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
*  I2S_4_backup - used to store component state prior entering 
*    sleep mode.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2S_4_Sleep(void) 
{
    /* Get component state */
    I2S_4_backup.enableState = I2S_4_CONTROL_REG;

    /* Stop component */
    I2S_4_Stop();
}


/*******************************************************************************
* Function Name: I2S_4_Wakeup
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
*  I2S_4_backup - used to restore component state after exit from
*    sleep mode.
*
*******************************************************************************/
void I2S_4_Wakeup(void) 
{
    #if (I2S_4_DYNAMIC_BIT_RESOLUTION)
        I2S_4_CONTROL_REG = I2S_4_backup.enableState & I2S_4_BIT_RESOLUTION_MODE_MASK;
    #endif /* I2S_4_DYNAMIC_BIT_RESOLUTION */

    if(0u != (I2S_4_backup.enableState & I2S_4_EN))
    {
        /* Enable component's operation */
        I2S_4_Enable();

        /* Enable Tx/Rx direction if they were enabled before sleep */
        #if(I2S_4_TX_DIRECTION_ENABLE)
            if(0u != (I2S_4_backup.enableState & I2S_4_TX_EN))
            {
                I2S_4_EnableTx();
            }
        #endif /* (I2S_4_TX_DIRECTION_ENABLE) */
        
        #if(I2S_4_RX_DIRECTION_ENABLE)
            if(0u != (I2S_4_backup.enableState & I2S_4_RX_EN))
            {
                I2S_4_EnableRx();
            }
        #endif /* (I2S_4_RX_DIRECTION_ENABLE) */
    }
}


/* [] END OF FILE */
