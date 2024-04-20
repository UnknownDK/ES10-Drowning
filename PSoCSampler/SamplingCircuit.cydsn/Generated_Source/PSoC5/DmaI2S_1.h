/*******************************************************************************
* File Name: DmaI2S_1.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_DmaI2S_1_H)
#define CY_ISR_DmaI2S_1_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void DmaI2S_1_Start(void);
void DmaI2S_1_StartEx(cyisraddress address);
void DmaI2S_1_Stop(void);

CY_ISR_PROTO(DmaI2S_1_Interrupt);

void DmaI2S_1_SetVector(cyisraddress address);
cyisraddress DmaI2S_1_GetVector(void);

void DmaI2S_1_SetPriority(uint8 priority);
uint8 DmaI2S_1_GetPriority(void);

void DmaI2S_1_Enable(void);
uint8 DmaI2S_1_GetState(void);
void DmaI2S_1_Disable(void);

void DmaI2S_1_SetPending(void);
void DmaI2S_1_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the DmaI2S_1 ISR. */
#define DmaI2S_1_INTC_VECTOR            ((reg32 *) DmaI2S_1__INTC_VECT)

/* Address of the DmaI2S_1 ISR priority. */
#define DmaI2S_1_INTC_PRIOR             ((reg8 *) DmaI2S_1__INTC_PRIOR_REG)

/* Priority of the DmaI2S_1 interrupt. */
#define DmaI2S_1_INTC_PRIOR_NUMBER      DmaI2S_1__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable DmaI2S_1 interrupt. */
#define DmaI2S_1_INTC_SET_EN            ((reg32 *) DmaI2S_1__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the DmaI2S_1 interrupt. */
#define DmaI2S_1_INTC_CLR_EN            ((reg32 *) DmaI2S_1__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the DmaI2S_1 interrupt state to pending. */
#define DmaI2S_1_INTC_SET_PD            ((reg32 *) DmaI2S_1__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the DmaI2S_1 interrupt. */
#define DmaI2S_1_INTC_CLR_PD            ((reg32 *) DmaI2S_1__INTC_CLR_PD_REG)


#endif /* CY_ISR_DmaI2S_1_H */


/* [] END OF FILE */
