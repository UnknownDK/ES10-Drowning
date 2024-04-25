/*******************************************************************************
* File Name: I2Sthree_PM.c
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

#include "I2Sthree.h"

static I2Sthree_BACKUP_STRUCT  I2Sthree_backup = {0u};


/*******************************************************************************
* Function Name: I2Sthree_SaveConfig
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
void I2Sthree_SaveConfig(void) 
{
    /* Nothing to save. All registers are retention. */
}


/*******************************************************************************
* Function Name: I2Sthree_RestoreConfig
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
void I2Sthree_RestoreConfig(void) 
{
    /* Nothing to restore. All registers are retention. */
}


/*******************************************************************************
* Function Name: I2Sthree_Sleep
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
*  I2Sthree_backup - used to store component state prior entering 
*    sleep mode.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2Sthree_Sleep(void) 
{
    /* Get component state */
    I2Sthree_backup.enableState = I2Sthree_CONTROL_REG;

    /* Stop component */
    I2Sthree_Stop();
}


/*******************************************************************************
* Function Name: I2Sthree_Wakeup
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
*  I2Sthree_backup - used to restore component state after exit from
*    sleep mode.
*
*******************************************************************************/
void I2Sthree_Wakeup(void) 
{
    #if (I2Sthree_DYNAMIC_BIT_RESOLUTION)
        I2Sthree_CONTROL_REG = I2Sthree_backup.enableState & I2Sthree_BIT_RESOLUTION_MODE_MASK;
    #endif /* I2Sthree_DYNAMIC_BIT_RESOLUTION */

    if(0u != (I2Sthree_backup.enableState & I2Sthree_EN))
    {
        /* Enable component's operation */
        I2Sthree_Enable();

        /* Enable Tx/Rx direction if they were enabled before sleep */
        #if(I2Sthree_TX_DIRECTION_ENABLE)
            if(0u != (I2Sthree_backup.enableState & I2Sthree_TX_EN))
            {
                I2Sthree_EnableTx();
            }
        #endif /* (I2Sthree_TX_DIRECTION_ENABLE) */
        
        #if(I2Sthree_RX_DIRECTION_ENABLE)
            if(0u != (I2Sthree_backup.enableState & I2Sthree_RX_EN))
            {
                I2Sthree_EnableRx();
            }
        #endif /* (I2Sthree_RX_DIRECTION_ENABLE) */
    }
}


/* [] END OF FILE */
