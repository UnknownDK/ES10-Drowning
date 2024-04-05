/*******************************************************************************
* File Name: I2S_3v3.h  
* Version 2.0
*
* Description:
*  This file contains the function prototypes and constants used in
*  the PGA User Module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PGA_I2S_3v3_H) 
#define CY_PGA_I2S_3v3_H 

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PGA_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


#if(!CY_PSOC5A)
    #if(CYDEV_VARIABLE_VDDA == 1)
        #if (!defined(CY_LIB_SC_BST_CLK_EN))
            #error Component PGA_v2_0 requires cy_boot v3.30 or later
        #endif /* (!defined(CY_LIB_SC_BST_CLK_EN)) */
    #endif /* CYDEV_VARIABLE_VDDA == 1 */
#endif /* (!CY_PSOC5A) */

/***************************************
*   Data Struct Definition
***************************************/

/* Low power Mode API Support */
typedef struct
{
    uint8   enableState;
    uint8   scCR1Reg;
    uint8   scCR2Reg;
    uint8   scCR3Reg;
}   I2S_3v3_BACKUP_STRUCT;


/* variable describes init state of the component */
extern uint8 I2S_3v3_initVar;


/***************************************
*        Function Prototypes 
***************************************/

void I2S_3v3_Start(void)                 ; 
void I2S_3v3_Stop(void)                  ; 
void I2S_3v3_SetPower(uint8 power)       ;
void I2S_3v3_SetGain(uint8 gain)         ;
void I2S_3v3_Sleep(void)                 ; 
void I2S_3v3_Wakeup(void)                ;
void I2S_3v3_SaveConfig(void)            ; 
void I2S_3v3_RestoreConfig(void)         ;
void I2S_3v3_Init(void)                  ;
void I2S_3v3_Enable(void)                ;


/***************************************
*            API Constants
***************************************/

/* Power constants for SetPower function */
#define I2S_3v3_MINPOWER                 (0x00u)
#define I2S_3v3_LOWPOWER                 (0x01u)
#define I2S_3v3_MEDPOWER                 (0x02u)
#define I2S_3v3_HIGHPOWER                (0x03u)

/* Constants for SetGain function */
#define I2S_3v3_GAIN_01                  (0x00u)
#define I2S_3v3_GAIN_02                  (0x01u)
#define I2S_3v3_GAIN_04                  (0x02u)
#define I2S_3v3_GAIN_08                  (0x03u)
#define I2S_3v3_GAIN_16                  (0x04u)
#define I2S_3v3_GAIN_24                  (0x05u)
#define I2S_3v3_GAIN_32                  (0x06u)
#define I2S_3v3_GAIN_48                  (0x07u)
#define I2S_3v3_GAIN_50                  (0x08u)
#define I2S_3v3_GAIN_MAX                 (0x08u)


/***************************************
*       Initialization Values
***************************************/

#define I2S_3v3_DEFAULT_GAIN             (1u)
#define I2S_3v3_VREF_MODE                ((1u != 0x00u) ? (0x00u) : I2S_3v3_GNDVREF_E)
#define I2S_3v3_DEFAULT_POWER            (2u)


/***************************************
*              Registers
***************************************/

#define I2S_3v3_CR0_REG                  (* (reg8 *) I2S_3v3_SC__CR0 )
#define I2S_3v3_CR0_PTR                  (  (reg8 *) I2S_3v3_SC__CR0 )
#define I2S_3v3_CR1_REG                  (* (reg8 *) I2S_3v3_SC__CR1 )
#define I2S_3v3_CR1_PTR                  (  (reg8 *) I2S_3v3_SC__CR1 )
#define I2S_3v3_CR2_REG                  (* (reg8 *) I2S_3v3_SC__CR2 )
#define I2S_3v3_CR2_PTR                  (  (reg8 *) I2S_3v3_SC__CR2 )
  /* Power manager */
#define I2S_3v3_PM_ACT_CFG_REG           (* (reg8 *) I2S_3v3_SC__PM_ACT_CFG )
#define I2S_3v3_PM_ACT_CFG_PTR           (  (reg8 *) I2S_3v3_SC__PM_ACT_CFG )  
#define I2S_3v3_PM_STBY_CFG_REG          (* (reg8 *) I2S_3v3_SC__PM_STBY_CFG )
  /* Power manager */
#define I2S_3v3_PM_STBY_CFG_PTR          (  (reg8 *) I2S_3v3_SC__PM_STBY_CFG )  
#define I2S_3v3_BSTCLK_REG               (* (reg8 *) I2S_3v3_SC__BST )
#define I2S_3v3_BSTCLK_PTR               (  (reg8 *) I2S_3v3_SC__BST )
/* Pump clock selectin register */
#define I2S_3v3_PUMP_CR1_REG             (* (reg8 *) CYDEV_ANAIF_CFG_PUMP_CR1)
#define I2S_3v3_PUMP_CR1_PTR             (  (reg8 *) CYDEV_ANAIF_CFG_PUMP_CR1)

/* Pump Register for SC block */
#define I2S_3v3_SC_MISC_REG              (* (reg8 *) CYDEV_ANAIF_RT_SC_MISC)
#define I2S_3v3_SC_MISC_PTR              (  (reg8 *) CYDEV_ANAIF_RT_SC_MISC)

/* PM_ACT_CFG (Active Power Mode CFG Register)mask */ 
#define I2S_3v3_ACT_PWR_EN               I2S_3v3_SC__PM_ACT_MSK 

/* PM_STBY_CFG (Alternate Active Power Mode CFG Register)mask */ 
#define I2S_3v3_STBY_PWR_EN              I2S_3v3_SC__PM_STBY_MSK 


/***************************************
*            Register Constants
***************************************/

/* SC_MISC constants */
#define I2S_3v3_PUMP_FORCE               (0x20u)
#define I2S_3v3_PUMP_AUTO                (0x10u)
#define I2S_3v3_DIFF_PGA_1_3             (0x02u)
#define I2S_3v3_DIFF_PGA_0_2             (0x01u)

/* ANIF.PUMP.CR1 Constants */
#define I2S_3v3_PUMP_CR1_SC_CLKSEL       (0x80u)

/* CR0 SC/CT Control Register 0 definitions */
#define I2S_3v3_MODE_PGA                 (0x0Cu)

/* CR1 SC/CT Control Register 1 definitions */

/* Bit Field  SC_COMP_ENUM */
#define I2S_3v3_COMP_MASK                (0x0Cu)
#define I2S_3v3_COMP_3P0PF               (0x00u)
#define I2S_3v3_COMP_3P6PF               (0x04u)
#define I2S_3v3_COMP_4P35PF              (0x08u)
#define I2S_3v3_COMP_5P1PF               (0x0Cu)

/* Bit Field  SC_DIV2_ENUM */
#define I2S_3v3_DIV2_MASK                (0x10u)
#define I2S_3v3_DIV2_DISABLE             (0x00u)
#define I2S_3v3_DIV2_ENABLE              (0x10u)

/* Bit Field  SC_DRIVE_ENUM */
#define I2S_3v3_DRIVE_MASK               (0x03u)
#define I2S_3v3_DRIVE_280UA              (0x00u)
#define I2S_3v3_DRIVE_420UA              (0x01u)
#define I2S_3v3_DRIVE_530UA              (0x02u)
#define I2S_3v3_DRIVE_650UA              (0x03u)

/* Bit Field  SC_PGA_MODE_ENUM */
#define I2S_3v3_PGA_MODE_MASK            (0x20u)
#define I2S_3v3_PGA_INV                  (0x00u)
#define I2S_3v3_PGA_NINV                 (0x20u)

/* CR2 SC/CT Control Register 2 definitions */

/* Bit Field  SC_BIAS_CONTROL_ENUM */
#define I2S_3v3_BIAS_MASK                (0x01u)
#define I2S_3v3_BIAS_NORMAL              (0x00u)
#define I2S_3v3_BIAS_LOW                 (0x01u)

/* Bit Field  SC_PGA_GNDVREF_ENUM  */
#define I2S_3v3_GNDVREF_MASK             (0x80u)
#define I2S_3v3_GNDVREF_DI               (0x00u)
#define I2S_3v3_GNDVREF_E                (0x80u)

/* Bit Field  SC_R20_40B_ENUM */
#define I2S_3v3_R20_40B_MASK             (0x02u)
#define I2S_3v3_R20_40B_40K              (0x00u)
#define I2S_3v3_R20_40B_20K              (0x02u)

/* Bit Field  SC_REDC_ENUM */
#define I2S_3v3_REDC_MASK                (0x0Cu)
#define I2S_3v3_REDC_00                  (0x00u)
#define I2S_3v3_REDC_01                  (0x04u)
#define I2S_3v3_REDC_10                  (0x08u)
#define I2S_3v3_REDC_11                  (0x0Cu)

/* Bit Field  SC_RVAL_ENUM */
#define I2S_3v3_RVAL_MASK                (0x70u)
#define I2S_3v3_RVAL_0K                  (0x00u)
#define I2S_3v3_RVAL_40K                 (0x10u)
#define I2S_3v3_RVAL_120K                (0x20u)
#define I2S_3v3_RVAL_280K                (0x30u)
#define I2S_3v3_RVAL_600K                (0x40u)
#define I2S_3v3_RVAL_460K                (0x60u)
#define I2S_3v3_RVAL_620K                (0x50u)
#define I2S_3v3_RVAL_470K                (0x60u)
#define I2S_3v3_RVAL_490K                (0x70u)

/* Bit Field  PGA_GAIN_ENUM */
#define I2S_3v3_PGA_GAIN_MASK            (0x72u)
#define I2S_3v3_PGA_GAIN_01              (0x00u)
#define I2S_3v3_PGA_GAIN_02              (0x10u)
#define I2S_3v3_PGA_GAIN_04              (0x20u)
#define I2S_3v3_PGA_GAIN_08              (0x30u)
#define I2S_3v3_PGA_GAIN_16              (0x40u)
#define I2S_3v3_PGA_GAIN_24              (0x50u)
#define I2S_3v3_PGA_GAIN_25              (0x70u)
#define I2S_3v3_PGA_GAIN_32              (0x52u)
#define I2S_3v3_PGA_GAIN_48              (0x62u)
#define I2S_3v3_PGA_GAIN_50              (0x72u)

#define I2S_3v3_BST_CLK_EN               (0x08u)
#define I2S_3v3_BST_CLK_INDEX_MASK       (0x07u)
#define I2S_3v3_PM_ACT_CFG_MASK          (0x0Fu)

/* Constant for VDDA Threshold */
#define I2S_3v3_CYDEV_VDDA_MV       (CYDEV_VDDA_MV)
#define I2S_3v3_MINIMUM_VDDA_THRESHOLD_MV   (2700u)

/*******************************************************************************
* Following code are OBSOLETE and must not be used starting from PGA 2.0
*******************************************************************************/
#define I2S_3v3_BST_REG            (I2S_3v3_BSTCLK_REG)
#define I2S_3v3_BST_PTR            (I2S_3v3_BSTCLK_PTR)
#define I2S_3v3_SC_REG_CLR         (0x00u)
#define I2S_3v3_BST_REG_EN         (0x08u)


#endif /* CY_PGA_I2S_3v3_H */


/* [] END OF FILE */
