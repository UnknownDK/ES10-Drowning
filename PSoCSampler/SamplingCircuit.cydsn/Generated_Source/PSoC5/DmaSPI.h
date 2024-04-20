/*******************************************************************************
* File Name: DmaSPI.h
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
#if !defined(CY_ISR_DmaSPI_H)
#define CY_ISR_DmaSPI_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void DmaSPI_Start(void);
void DmaSPI_StartEx(cyisraddress address);
void DmaSPI_Stop(void);

CY_ISR_PROTO(DmaSPI_Interrupt);

void DmaSPI_SetVector(cyisraddress address);
cyisraddress DmaSPI_GetVector(void);

void DmaSPI_SetPriority(uint8 priority);
uint8 DmaSPI_GetPriority(void);

void DmaSPI_Enable(void);
uint8 DmaSPI_GetState(void);
void DmaSPI_Disable(void);

void DmaSPI_SetPending(void);
void DmaSPI_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the DmaSPI ISR. */
#define DmaSPI_INTC_VECTOR            ((reg32 *) DmaSPI__INTC_VECT)

/* Address of the DmaSPI ISR priority. */
#define DmaSPI_INTC_PRIOR             ((reg8 *) DmaSPI__INTC_PRIOR_REG)

/* Priority of the DmaSPI interrupt. */
#define DmaSPI_INTC_PRIOR_NUMBER      DmaSPI__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable DmaSPI interrupt. */
#define DmaSPI_INTC_SET_EN            ((reg32 *) DmaSPI__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the DmaSPI interrupt. */
#define DmaSPI_INTC_CLR_EN            ((reg32 *) DmaSPI__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the DmaSPI interrupt state to pending. */
#define DmaSPI_INTC_SET_PD            ((reg32 *) DmaSPI__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the DmaSPI interrupt. */
#define DmaSPI_INTC_CLR_PD            ((reg32 *) DmaSPI__INTC_CLR_PD_REG)


#endif /* CY_ISR_DmaSPI_H */


/* [] END OF FILE */
