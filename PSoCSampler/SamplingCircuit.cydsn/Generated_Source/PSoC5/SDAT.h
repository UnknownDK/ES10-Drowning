/*******************************************************************************
* File Name: SDAT.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SDAT_H) /* Pins SDAT_H */
#define CY_PINS_SDAT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SDAT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SDAT__PORT == 15 && ((SDAT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SDAT_Write(uint8 value);
void    SDAT_SetDriveMode(uint8 mode);
uint8   SDAT_ReadDataReg(void);
uint8   SDAT_Read(void);
void    SDAT_SetInterruptMode(uint16 position, uint16 mode);
uint8   SDAT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SDAT_SetDriveMode() function.
     *  @{
     */
        #define SDAT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SDAT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SDAT_DM_RES_UP          PIN_DM_RES_UP
        #define SDAT_DM_RES_DWN         PIN_DM_RES_DWN
        #define SDAT_DM_OD_LO           PIN_DM_OD_LO
        #define SDAT_DM_OD_HI           PIN_DM_OD_HI
        #define SDAT_DM_STRONG          PIN_DM_STRONG
        #define SDAT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SDAT_MASK               SDAT__MASK
#define SDAT_SHIFT              SDAT__SHIFT
#define SDAT_WIDTH              1u

/* Interrupt constants */
#if defined(SDAT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SDAT_SetInterruptMode() function.
     *  @{
     */
        #define SDAT_INTR_NONE      (uint16)(0x0000u)
        #define SDAT_INTR_RISING    (uint16)(0x0001u)
        #define SDAT_INTR_FALLING   (uint16)(0x0002u)
        #define SDAT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SDAT_INTR_MASK      (0x01u) 
#endif /* (SDAT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SDAT_PS                     (* (reg8 *) SDAT__PS)
/* Data Register */
#define SDAT_DR                     (* (reg8 *) SDAT__DR)
/* Port Number */
#define SDAT_PRT_NUM                (* (reg8 *) SDAT__PRT) 
/* Connect to Analog Globals */                                                  
#define SDAT_AG                     (* (reg8 *) SDAT__AG)                       
/* Analog MUX bux enable */
#define SDAT_AMUX                   (* (reg8 *) SDAT__AMUX) 
/* Bidirectional Enable */                                                        
#define SDAT_BIE                    (* (reg8 *) SDAT__BIE)
/* Bit-mask for Aliased Register Access */
#define SDAT_BIT_MASK               (* (reg8 *) SDAT__BIT_MASK)
/* Bypass Enable */
#define SDAT_BYP                    (* (reg8 *) SDAT__BYP)
/* Port wide control signals */                                                   
#define SDAT_CTL                    (* (reg8 *) SDAT__CTL)
/* Drive Modes */
#define SDAT_DM0                    (* (reg8 *) SDAT__DM0) 
#define SDAT_DM1                    (* (reg8 *) SDAT__DM1)
#define SDAT_DM2                    (* (reg8 *) SDAT__DM2) 
/* Input Buffer Disable Override */
#define SDAT_INP_DIS                (* (reg8 *) SDAT__INP_DIS)
/* LCD Common or Segment Drive */
#define SDAT_LCD_COM_SEG            (* (reg8 *) SDAT__LCD_COM_SEG)
/* Enable Segment LCD */
#define SDAT_LCD_EN                 (* (reg8 *) SDAT__LCD_EN)
/* Slew Rate Control */
#define SDAT_SLW                    (* (reg8 *) SDAT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SDAT_PRTDSI__CAPS_SEL       (* (reg8 *) SDAT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SDAT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SDAT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SDAT_PRTDSI__OE_SEL0        (* (reg8 *) SDAT__PRTDSI__OE_SEL0) 
#define SDAT_PRTDSI__OE_SEL1        (* (reg8 *) SDAT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SDAT_PRTDSI__OUT_SEL0       (* (reg8 *) SDAT__PRTDSI__OUT_SEL0) 
#define SDAT_PRTDSI__OUT_SEL1       (* (reg8 *) SDAT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SDAT_PRTDSI__SYNC_OUT       (* (reg8 *) SDAT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SDAT__SIO_CFG)
    #define SDAT_SIO_HYST_EN        (* (reg8 *) SDAT__SIO_HYST_EN)
    #define SDAT_SIO_REG_HIFREQ     (* (reg8 *) SDAT__SIO_REG_HIFREQ)
    #define SDAT_SIO_CFG            (* (reg8 *) SDAT__SIO_CFG)
    #define SDAT_SIO_DIFF           (* (reg8 *) SDAT__SIO_DIFF)
#endif /* (SDAT__SIO_CFG) */

/* Interrupt Registers */
#if defined(SDAT__INTSTAT)
    #define SDAT_INTSTAT            (* (reg8 *) SDAT__INTSTAT)
    #define SDAT_SNAP               (* (reg8 *) SDAT__SNAP)
    
	#define SDAT_0_INTTYPE_REG 		(* (reg8 *) SDAT__0__INTTYPE)
#endif /* (SDAT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SDAT_H */


/* [] END OF FILE */
