/*******************************************************************************
* File Name: I2Sseven_PM.c
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

#include "I2Sseven.h"

static I2Sseven_BACKUP_STRUCT  I2Sseven_backup = {0u};


/*******************************************************************************
* Function Name: I2Sseven_SaveConfig
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
void I2Sseven_SaveConfig(void) 
{
    /* Nothing to save. All registers are retention. */
}


/*******************************************************************************
* Function Name: I2Sseven_RestoreConfig
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
void I2Sseven_RestoreConfig(void) 
{
    /* Nothing to restore. All registers are retention. */
}


/*******************************************************************************
* Function Name: I2Sseven_Sleep
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
*  I2Sseven_backup - used to store component state prior entering 
*    sleep mode.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2Sseven_Sleep(void) 
{
    /* Get component state */
    I2Sseven_backup.enableState = I2Sseven_CONTROL_REG;

    /* Stop component */
    I2Sseven_Stop();
}


/*******************************************************************************
* Function Name: I2Sseven_Wakeup
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
*  I2Sseven_backup - used to restore component state after exit from
*    sleep mode.
*
*******************************************************************************/
void I2Sseven_Wakeup(void) 
{
    #if (I2Sseven_DYNAMIC_BIT_RESOLUTION)
        I2Sseven_CONTROL_REG = I2Sseven_backup.enableState & I2Sseven_BIT_RESOLUTION_MODE_MASK;
    #endif /* I2Sseven_DYNAMIC_BIT_RESOLUTION */

    if(0u != (I2Sseven_backup.enableState & I2Sseven_EN))
    {
        /* Enable component's operation */
        I2Sseven_Enable();

        /* Enable Tx/Rx direction if they were enabled before sleep */
        #if(I2Sseven_TX_DIRECTION_ENABLE)
            if(0u != (I2Sseven_backup.enableState & I2Sseven_TX_EN))
            {
                I2Sseven_EnableTx();
            }
        #endif /* (I2Sseven_TX_DIRECTION_ENABLE) */
        
        #if(I2Sseven_RX_DIRECTION_ENABLE)
            if(0u != (I2Sseven_backup.enableState & I2Sseven_RX_EN))
            {
                I2Sseven_EnableRx();
            }
        #endif /* (I2Sseven_RX_DIRECTION_ENABLE) */
    }
}


/* [] END OF FILE */
