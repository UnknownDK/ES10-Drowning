/*******************************************************************************
* File Name: I2S_3v3.c  
* Version 2.0
*
* Description:
*  This file provides the source code to the API for the PGA 
*  User Module.
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

#if (!CY_PSOC5A)
    #if (CYDEV_VARIABLE_VDDA == 1u)
        #include "CyScBoostClk.h"
    #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
#endif /* (!CY_PSOC5A) */

#if (CY_PSOC5A)
    static I2S_3v3_BACKUP_STRUCT  I2S_3v3_P5backup;
#endif /* (CY_ PSOC5A) */

uint8 I2S_3v3_initVar = 0u;


/*******************************************************************************   
* Function Name: I2S_3v3_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  I2S_3v3_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void I2S_3v3_Init(void) 
{
    /* Set PGA mode */
    I2S_3v3_CR0_REG = I2S_3v3_MODE_PGA;      
    /* Set non-inverting PGA mode and reference mode */
    I2S_3v3_CR1_REG |= I2S_3v3_PGA_NINV;  
    /* Set default gain and ref mode */
    I2S_3v3_CR2_REG = I2S_3v3_VREF_MODE;
    /* Set gain and compensation */
    I2S_3v3_SetGain(I2S_3v3_DEFAULT_GAIN);
    /* Set power */
    I2S_3v3_SetPower(I2S_3v3_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: I2S_3v3_Enable
********************************************************************************
*
* Summary:
*  Enables the PGA block operation.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void I2S_3v3_Enable(void) 
{
    /* This is to restore the value of register CR1 and CR2 which is saved 
      in prior to the modifications in stop() API */
    #if (CY_PSOC5A)
        if(I2S_3v3_P5backup.enableState == 1u)
        {
            I2S_3v3_CR1_REG = I2S_3v3_P5backup.scCR1Reg;
            I2S_3v3_CR2_REG = I2S_3v3_P5backup.scCR2Reg;
            I2S_3v3_P5backup.enableState = 0u;
        }
    #endif /* CY_PSOC5A */   

    /* Enable power to the Amp in Active mode*/
    I2S_3v3_PM_ACT_CFG_REG |= I2S_3v3_ACT_PWR_EN;

    /* Enable power to the Amp in Alternative Active mode*/
    I2S_3v3_PM_STBY_CFG_REG |= I2S_3v3_STBY_PWR_EN;
    
    I2S_3v3_PUMP_CR1_REG |= I2S_3v3_PUMP_CR1_SC_CLKSEL;
    
    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            if(CyScPumpEnabled == 1u)
            {
                I2S_3v3_BSTCLK_REG &= (uint8)(~I2S_3v3_BST_CLK_INDEX_MASK);
                I2S_3v3_BSTCLK_REG |= I2S_3v3_BST_CLK_EN | CyScBoostClk__INDEX;
                I2S_3v3_SC_MISC_REG |= I2S_3v3_PUMP_FORCE;
                CyScBoostClk_Start();
            }
            else
            {
                I2S_3v3_BSTCLK_REG &= (uint8)(~I2S_3v3_BST_CLK_EN);
                I2S_3v3_SC_MISC_REG &= (uint8)(~I2S_3v3_PUMP_FORCE);
            }
        #endif /* (CYDEV_VARIABLE_VDDA == 1u) */
    #endif /* (!CY_PSOC5A) */
}


/*******************************************************************************
* Function Name: I2S_3v3_Start
********************************************************************************
*
* Summary:
*  The start function initializes the PGA with the default values and sets
*  the power to the given level. A power level of 0, is same as executing
*  the stop function.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void I2S_3v3_Start(void) 
{

    /* This is to restore the value of register CR1 and CR2 which is saved 
      in prior to the modification in stop() API */

    if(I2S_3v3_initVar == 0u)
    {
        I2S_3v3_Init();
        I2S_3v3_initVar = 1u;
    }

    I2S_3v3_Enable();
}


/*******************************************************************************
* Function Name: I2S_3v3_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void I2S_3v3_Stop(void) 
{ 
    /* Disble power to the Amp in Active mode template */
    I2S_3v3_PM_ACT_CFG_REG &= (uint8)(~I2S_3v3_ACT_PWR_EN);

    /* Disble power to the Amp in Alternative Active mode template */
    I2S_3v3_PM_STBY_CFG_REG &= (uint8)(~I2S_3v3_STBY_PWR_EN);

    #if (!CY_PSOC5A)
        #if (CYDEV_VARIABLE_VDDA == 1u)
            I2S_3v3_BSTCLK_REG &= (uint8)(~I2S_3v3_BST_CLK_EN);
            /* Disable pumps only if there aren't any SC block in use */
            if ((I2S_3v3_PM_ACT_CFG_REG & I2S_3v3_PM_ACT_CFG_MASK) == 0u)
            {
                I2S_3v3_SC_MISC_REG &= (uint8)(~I2S_3v3_PUMP_FORCE);
                I2S_3v3_PUMP_CR1_REG &= (uint8)(~I2S_3v3_PUMP_CR1_SC_CLKSEL);
                CyScBoostClk_Stop();
            }
        #endif /* CYDEV_VARIABLE_VDDA == 1u */
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /* This sets PGA in zero current mode and output routes are valid */
    #if (CY_PSOC5A)
        I2S_3v3_P5backup.scCR1Reg = I2S_3v3_CR1_REG;
        I2S_3v3_P5backup.scCR2Reg = I2S_3v3_CR2_REG;
        I2S_3v3_CR1_REG = 0x00u;
        I2S_3v3_CR2_REG = 0x00u;
        I2S_3v3_P5backup.enableState = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: I2S_3v3_SetPower
********************************************************************************
*
* Summary:
*  Set the power of the PGA.
*
* Parameters:
*  power: Sets power level between (0) and (3) high power
*
* Return:
*  void
*
*******************************************************************************/
void I2S_3v3_SetPower(uint8 power) 
{
    uint8 tmpCR;

    tmpCR = I2S_3v3_CR1_REG & (uint8)(~I2S_3v3_DRIVE_MASK);
    tmpCR |= (power & I2S_3v3_DRIVE_MASK);
    I2S_3v3_CR1_REG = tmpCR;  
}


/*******************************************************************************
* Function Name: I2S_3v3_SetGain
********************************************************************************
*
* Summary:
*  This function sets values of the input and feedback resistors to set a 
*  specific gain of the amplifier.
*
* Parameters:
*  gain: Gain value of PGA (See header file for gain values.)
*
* Return:
*  void 
*
*******************************************************************************/
void I2S_3v3_SetGain(uint8 gain) 
{
    /* Constant array for gain settings */
    const uint8 I2S_3v3_GainArray[9] = { 
        (I2S_3v3_RVAL_0K   | I2S_3v3_R20_40B_40K | I2S_3v3_BIAS_LOW), /* G=1  */
        (I2S_3v3_RVAL_40K  | I2S_3v3_R20_40B_40K | I2S_3v3_BIAS_LOW), /* G=2  */
        (I2S_3v3_RVAL_120K | I2S_3v3_R20_40B_40K | I2S_3v3_BIAS_LOW), /* G=4  */
        (I2S_3v3_RVAL_280K | I2S_3v3_R20_40B_40K | I2S_3v3_BIAS_LOW), /* G=8  */
        (I2S_3v3_RVAL_600K | I2S_3v3_R20_40B_40K | I2S_3v3_BIAS_LOW), /* G=16 */
        (I2S_3v3_RVAL_460K | I2S_3v3_R20_40B_40K | I2S_3v3_BIAS_LOW), /* G=24, Sets Rin as 20k */
        (I2S_3v3_RVAL_620K | I2S_3v3_R20_40B_20K | I2S_3v3_BIAS_LOW), /* G=32 */
        (I2S_3v3_RVAL_470K | I2S_3v3_R20_40B_20K | I2S_3v3_BIAS_LOW), /* G=48, Sets Rin as 10k */
        (I2S_3v3_RVAL_490K | I2S_3v3_R20_40B_20K | I2S_3v3_BIAS_LOW)  /* G=50, Sets Rin as 10k */
    };
    
    /* Constant array for gain compenstion settings */
    const uint8 I2S_3v3_GainComp[9] = { 
        ( I2S_3v3_COMP_4P35PF  | (uint8)( I2S_3v3_REDC_00 >> 2 )), /* G=1  */
        ( I2S_3v3_COMP_4P35PF  | (uint8)( I2S_3v3_REDC_01 >> 2 )), /* G=2  */
        ( I2S_3v3_COMP_3P0PF   | (uint8)( I2S_3v3_REDC_01 >> 2 )), /* G=4  */
        ( I2S_3v3_COMP_3P0PF   | (uint8)( I2S_3v3_REDC_01 >> 2 )), /* G=8  */
        ( I2S_3v3_COMP_3P6PF   | (uint8)( I2S_3v3_REDC_01 >> 2 )), /* G=16 */
        ( I2S_3v3_COMP_3P6PF   | (uint8)( I2S_3v3_REDC_11 >> 2 )), /* G=24 */
        ( I2S_3v3_COMP_3P6PF   | (uint8)( I2S_3v3_REDC_11 >> 2 )), /* G=32 */
        ( I2S_3v3_COMP_3P6PF   | (uint8)( I2S_3v3_REDC_00 >> 2 )), /* G=48 */
        ( I2S_3v3_COMP_3P6PF   | (uint8)( I2S_3v3_REDC_00 >> 2 ))  /* G=50 */
    };
    
    /* Only set new gain if it is a valid gain */
    if( gain <= I2S_3v3_GAIN_MAX)
    {
        /* Clear resistors, redc, and bias */
        I2S_3v3_CR2_REG &= (uint8)(~(I2S_3v3_RVAL_MASK | I2S_3v3_R20_40B_MASK | 
                                I2S_3v3_REDC_MASK | I2S_3v3_BIAS_MASK ));

        /* Set gain value resistors, redc comp, and bias */
        I2S_3v3_CR2_REG |= (I2S_3v3_GainArray[gain] |
                                ((uint8)(I2S_3v3_GainComp[gain] << 2 ) & I2S_3v3_REDC_MASK));

        /* Clear sc_comp  */
        I2S_3v3_CR1_REG &= (uint8)(~I2S_3v3_COMP_MASK);
        /* Set sc_comp  */
        I2S_3v3_CR1_REG |= ( I2S_3v3_GainComp[gain] | I2S_3v3_COMP_MASK );
    }
}


/* [] END OF FILE */
