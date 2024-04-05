/*******************************************************************************
* File Name: I2S_3v3_PM.c  
* Version 2.0
*
* Description:
*  This file provides the power manager source code to the API for PGA 
*  Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "I2S_3v3.h"

static I2S_3v3_BACKUP_STRUCT  I2S_3v3_backup;


/*******************************************************************************
* Function Name: I2S_3v3_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current user register configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void I2S_3v3_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************  
* Function Name: I2S_3v3_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void I2S_3v3_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************   
* Function Name: I2S_3v3_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  I2S_3v3_backup: The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void I2S_3v3_Sleep(void) 
{
    /* Save PGA enable state */
    if((I2S_3v3_PM_ACT_CFG_REG & I2S_3v3_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        I2S_3v3_backup.enableState = 1u;
        /* Stop the configuration */
        I2S_3v3_Stop();
    }
    else
    {
        /* Component is disabled */
        I2S_3v3_backup.enableState = 0u;
    }
    /* Save the configuration */
    I2S_3v3_SaveConfig();
}


/*******************************************************************************
* Function Name: I2S_3v3_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  void
*
* Global variables:
*  I2S_3v3_backup: The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
* 
*******************************************************************************/
void I2S_3v3_Wakeup(void) 
{
    /* Restore the configurations */
    I2S_3v3_RestoreConfig();
     /* Enables the component operation */
    if(I2S_3v3_backup.enableState == 1u)
    {
        I2S_3v3_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
