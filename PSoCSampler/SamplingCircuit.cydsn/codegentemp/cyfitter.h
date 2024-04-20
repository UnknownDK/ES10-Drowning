/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* cs */
#define cs__0__INTTYPE CYREG_PICU2_INTTYPE2
#define cs__0__MASK 0x04u
#define cs__0__PC CYREG_PRT2_PC2
#define cs__0__PORT 2u
#define cs__0__SHIFT 2u
#define cs__AG CYREG_PRT2_AG
#define cs__AMUX CYREG_PRT2_AMUX
#define cs__BIE CYREG_PRT2_BIE
#define cs__BIT_MASK CYREG_PRT2_BIT_MASK
#define cs__BYP CYREG_PRT2_BYP
#define cs__CTL CYREG_PRT2_CTL
#define cs__DM0 CYREG_PRT2_DM0
#define cs__DM1 CYREG_PRT2_DM1
#define cs__DM2 CYREG_PRT2_DM2
#define cs__DR CYREG_PRT2_DR
#define cs__INP_DIS CYREG_PRT2_INP_DIS
#define cs__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define cs__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define cs__LCD_EN CYREG_PRT2_LCD_EN
#define cs__MASK 0x04u
#define cs__PORT 2u
#define cs__PRT CYREG_PRT2_PRT
#define cs__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define cs__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define cs__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define cs__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define cs__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define cs__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define cs__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define cs__PS CYREG_PRT2_PS
#define cs__SHIFT 2u
#define cs__SLW CYREG_PRT2_SLW

/* I2S */
#define I2S_bI2S_BitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB01_02_ACTL
#define I2S_bI2S_BitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB01_02_CTL
#define I2S_bI2S_BitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB01_02_CTL
#define I2S_bI2S_BitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB01_02_CTL
#define I2S_bI2S_BitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB01_02_CTL
#define I2S_bI2S_BitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB01_02_MSK
#define I2S_bI2S_BitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB01_02_MSK
#define I2S_bI2S_BitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB01_02_MSK
#define I2S_bI2S_BitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB01_02_MSK
#define I2S_bI2S_BitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB01_ACTL
#define I2S_bI2S_BitCounter__CONTROL_REG CYREG_B0_UDB01_CTL
#define I2S_bI2S_BitCounter__CONTROL_ST_REG CYREG_B0_UDB01_ST_CTL
#define I2S_bI2S_BitCounter__COUNT_REG CYREG_B0_UDB01_CTL
#define I2S_bI2S_BitCounter__COUNT_ST_REG CYREG_B0_UDB01_ST_CTL
#define I2S_bI2S_BitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB01_MSK_ACTL
#define I2S_bI2S_BitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB01_MSK_ACTL
#define I2S_bI2S_BitCounter__PERIOD_REG CYREG_B0_UDB01_MSK
#define I2S_bI2S_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB01_02_ACTL
#define I2S_bI2S_BitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB01_02_ST
#define I2S_bI2S_BitCounter_ST__MASK_REG CYREG_B0_UDB01_MSK
#define I2S_bI2S_BitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB01_MSK_ACTL
#define I2S_bI2S_BitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB01_MSK_ACTL
#define I2S_bI2S_BitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB01_ACTL
#define I2S_bI2S_BitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB01_ST_CTL
#define I2S_bI2S_BitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB01_ST_CTL
#define I2S_bI2S_BitCounter_ST__STATUS_REG CYREG_B0_UDB01_ST
#define I2S_bI2S_CtlReg__1__MASK 0x02u
#define I2S_bI2S_CtlReg__1__POS 1
#define I2S_bI2S_CtlReg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB06_07_ACTL
#define I2S_bI2S_CtlReg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB06_07_CTL
#define I2S_bI2S_CtlReg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB06_07_CTL
#define I2S_bI2S_CtlReg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB06_07_CTL
#define I2S_bI2S_CtlReg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB06_07_CTL
#define I2S_bI2S_CtlReg__16BIT_MASK_MASK_REG CYREG_B0_UDB06_07_MSK
#define I2S_bI2S_CtlReg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB06_07_MSK
#define I2S_bI2S_CtlReg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB06_07_MSK
#define I2S_bI2S_CtlReg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB06_07_MSK
#define I2S_bI2S_CtlReg__2__MASK 0x04u
#define I2S_bI2S_CtlReg__2__POS 2
#define I2S_bI2S_CtlReg__CONTROL_AUX_CTL_REG CYREG_B0_UDB06_ACTL
#define I2S_bI2S_CtlReg__CONTROL_REG CYREG_B0_UDB06_CTL
#define I2S_bI2S_CtlReg__CONTROL_ST_REG CYREG_B0_UDB06_ST_CTL
#define I2S_bI2S_CtlReg__COUNT_REG CYREG_B0_UDB06_CTL
#define I2S_bI2S_CtlReg__COUNT_ST_REG CYREG_B0_UDB06_ST_CTL
#define I2S_bI2S_CtlReg__MASK 0x06u
#define I2S_bI2S_CtlReg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define I2S_bI2S_CtlReg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define I2S_bI2S_CtlReg__PERIOD_REG CYREG_B0_UDB06_MSK
#define I2S_bI2S_Rx_CH_0__dpRx_u0__16BIT_A0_REG CYREG_B0_UDB06_07_A0
#define I2S_bI2S_Rx_CH_0__dpRx_u0__16BIT_A1_REG CYREG_B0_UDB06_07_A1
#define I2S_bI2S_Rx_CH_0__dpRx_u0__16BIT_D0_REG CYREG_B0_UDB06_07_D0
#define I2S_bI2S_Rx_CH_0__dpRx_u0__16BIT_D1_REG CYREG_B0_UDB06_07_D1
#define I2S_bI2S_Rx_CH_0__dpRx_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB06_07_ACTL
#define I2S_bI2S_Rx_CH_0__dpRx_u0__16BIT_F0_REG CYREG_B0_UDB06_07_F0
#define I2S_bI2S_Rx_CH_0__dpRx_u0__16BIT_F1_REG CYREG_B0_UDB06_07_F1
#define I2S_bI2S_Rx_CH_0__dpRx_u0__A0_A1_REG CYREG_B0_UDB06_A0_A1
#define I2S_bI2S_Rx_CH_0__dpRx_u0__A0_REG CYREG_B0_UDB06_A0
#define I2S_bI2S_Rx_CH_0__dpRx_u0__A1_REG CYREG_B0_UDB06_A1
#define I2S_bI2S_Rx_CH_0__dpRx_u0__D0_D1_REG CYREG_B0_UDB06_D0_D1
#define I2S_bI2S_Rx_CH_0__dpRx_u0__D0_REG CYREG_B0_UDB06_D0
#define I2S_bI2S_Rx_CH_0__dpRx_u0__D1_REG CYREG_B0_UDB06_D1
#define I2S_bI2S_Rx_CH_0__dpRx_u0__DP_AUX_CTL_REG CYREG_B0_UDB06_ACTL
#define I2S_bI2S_Rx_CH_0__dpRx_u0__F0_F1_REG CYREG_B0_UDB06_F0_F1
#define I2S_bI2S_Rx_CH_0__dpRx_u0__F0_REG CYREG_B0_UDB06_F0
#define I2S_bI2S_Rx_CH_0__dpRx_u0__F1_REG CYREG_B0_UDB06_F1
#define I2S_bI2S_Rx_CH_0__dpRx_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define I2S_bI2S_Rx_CH_0__dpRx_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define I2S_bI2S_Rx_STS_0__Sts__0__MASK 0x01u
#define I2S_bI2S_Rx_STS_0__Sts__0__POS 0
#define I2S_bI2S_Rx_STS_0__Sts__1__MASK 0x02u
#define I2S_bI2S_Rx_STS_0__Sts__1__POS 1
#define I2S_bI2S_Rx_STS_0__Sts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB06_07_ACTL
#define I2S_bI2S_Rx_STS_0__Sts__16BIT_STATUS_REG CYREG_B0_UDB06_07_ST
#define I2S_bI2S_Rx_STS_0__Sts__MASK 0x03u
#define I2S_bI2S_Rx_STS_0__Sts__MASK_REG CYREG_B0_UDB06_MSK
#define I2S_bI2S_Rx_STS_0__Sts__MASK_ST_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define I2S_bI2S_Rx_STS_0__Sts__PER_ST_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define I2S_bI2S_Rx_STS_0__Sts__STATUS_AUX_CTL_REG CYREG_B0_UDB06_ACTL
#define I2S_bI2S_Rx_STS_0__Sts__STATUS_CNT_REG CYREG_B0_UDB06_ST_CTL
#define I2S_bI2S_Rx_STS_0__Sts__STATUS_CONTROL_REG CYREG_B0_UDB06_ST_CTL
#define I2S_bI2S_Rx_STS_0__Sts__STATUS_REG CYREG_B0_UDB06_ST
#define I2S_CLK__0__INTTYPE CYREG_PICU12_INTTYPE2
#define I2S_CLK__0__MASK 0x04u
#define I2S_CLK__0__PC CYREG_PRT12_PC2
#define I2S_CLK__0__PORT 12u
#define I2S_CLK__0__SHIFT 2u
#define I2S_CLK__1__INTTYPE CYREG_PICU12_INTTYPE3
#define I2S_CLK__1__MASK 0x08u
#define I2S_CLK__1__PC CYREG_PRT12_PC3
#define I2S_CLK__1__PORT 12u
#define I2S_CLK__1__SHIFT 3u
#define I2S_CLK__AG CYREG_PRT12_AG
#define I2S_CLK__BIE CYREG_PRT12_BIE
#define I2S_CLK__BIT_MASK CYREG_PRT12_BIT_MASK
#define I2S_CLK__BYP CYREG_PRT12_BYP
#define I2S_CLK__DM0 CYREG_PRT12_DM0
#define I2S_CLK__DM1 CYREG_PRT12_DM1
#define I2S_CLK__DM2 CYREG_PRT12_DM2
#define I2S_CLK__DR CYREG_PRT12_DR
#define I2S_CLK__INP_DIS CYREG_PRT12_INP_DIS
#define I2S_CLK__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define I2S_CLK__MASK 0x0Cu
#define I2S_CLK__PORT 12u
#define I2S_CLK__PRT CYREG_PRT12_PRT
#define I2S_CLK__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define I2S_CLK__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define I2S_CLK__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define I2S_CLK__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define I2S_CLK__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define I2S_CLK__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define I2S_CLK__PS CYREG_PRT12_PS
#define I2S_CLK__SCK__INTTYPE CYREG_PICU12_INTTYPE2
#define I2S_CLK__SCK__MASK 0x04u
#define I2S_CLK__SCK__PC CYREG_PRT12_PC2
#define I2S_CLK__SCK__PORT 12u
#define I2S_CLK__SCK__SHIFT 2u
#define I2S_CLK__SHIFT 2u
#define I2S_CLK__SIO_CFG CYREG_PRT12_SIO_CFG
#define I2S_CLK__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define I2S_CLK__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define I2S_CLK__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define I2S_CLK__SLW CYREG_PRT12_SLW
#define I2S_CLK__WS__INTTYPE CYREG_PICU12_INTTYPE3
#define I2S_CLK__WS__MASK 0x08u
#define I2S_CLK__WS__PC CYREG_PRT12_PC3
#define I2S_CLK__WS__PORT 12u
#define I2S_CLK__WS__SHIFT 3u
#define I2S_DMA__DRQ_CTL CYREG_IDMUX_DRQ_CTL0
#define I2S_DMA__DRQ_NUMBER 0u
#define I2S_DMA__NUMBEROF_TDS 0u
#define I2S_DMA__PRIORITY 2u
#define I2S_DMA__TERMIN_EN 0u
#define I2S_DMA__TERMIN_SEL 0u
#define I2S_DMA__TERMOUT0_EN 1u
#define I2S_DMA__TERMOUT0_SEL 0u
#define I2S_DMA__TERMOUT1_EN 0u
#define I2S_DMA__TERMOUT1_SEL 0u
#define I2S_SDI__0__INTTYPE CYREG_PICU12_INTTYPE4
#define I2S_SDI__0__MASK 0x10u
#define I2S_SDI__0__PC CYREG_PRT12_PC4
#define I2S_SDI__0__PORT 12u
#define I2S_SDI__0__SHIFT 4u
#define I2S_SDI__AG CYREG_PRT12_AG
#define I2S_SDI__BIE CYREG_PRT12_BIE
#define I2S_SDI__BIT_MASK CYREG_PRT12_BIT_MASK
#define I2S_SDI__BYP CYREG_PRT12_BYP
#define I2S_SDI__DM0 CYREG_PRT12_DM0
#define I2S_SDI__DM1 CYREG_PRT12_DM1
#define I2S_SDI__DM2 CYREG_PRT12_DM2
#define I2S_SDI__DR CYREG_PRT12_DR
#define I2S_SDI__INP_DIS CYREG_PRT12_INP_DIS
#define I2S_SDI__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU12_BASE
#define I2S_SDI__MASK 0x10u
#define I2S_SDI__PORT 12u
#define I2S_SDI__PRT CYREG_PRT12_PRT
#define I2S_SDI__PRTDSI__DBL_SYNC_IN CYREG_PRT12_DBL_SYNC_IN
#define I2S_SDI__PRTDSI__OE_SEL0 CYREG_PRT12_OE_SEL0
#define I2S_SDI__PRTDSI__OE_SEL1 CYREG_PRT12_OE_SEL1
#define I2S_SDI__PRTDSI__OUT_SEL0 CYREG_PRT12_OUT_SEL0
#define I2S_SDI__PRTDSI__OUT_SEL1 CYREG_PRT12_OUT_SEL1
#define I2S_SDI__PRTDSI__SYNC_OUT CYREG_PRT12_SYNC_OUT
#define I2S_SDI__PS CYREG_PRT12_PS
#define I2S_SDI__SHIFT 4u
#define I2S_SDI__SIO_CFG CYREG_PRT12_SIO_CFG
#define I2S_SDI__SIO_DIFF CYREG_PRT12_SIO_DIFF
#define I2S_SDI__SIO_HYST_EN CYREG_PRT12_SIO_HYST_EN
#define I2S_SDI__SIO_REG_HIFREQ CYREG_PRT12_SIO_REG_HIFREQ
#define I2S_SDI__SLW CYREG_PRT12_SLW

/* Rx_1 */
#define Rx_1__0__INTTYPE CYREG_PICU15_INTTYPE2
#define Rx_1__0__MASK 0x04u
#define Rx_1__0__PC CYREG_IO_PC_PRT15_PC2
#define Rx_1__0__PORT 15u
#define Rx_1__0__SHIFT 2u
#define Rx_1__AG CYREG_PRT15_AG
#define Rx_1__AMUX CYREG_PRT15_AMUX
#define Rx_1__BIE CYREG_PRT15_BIE
#define Rx_1__BIT_MASK CYREG_PRT15_BIT_MASK
#define Rx_1__BYP CYREG_PRT15_BYP
#define Rx_1__CTL CYREG_PRT15_CTL
#define Rx_1__DM0 CYREG_PRT15_DM0
#define Rx_1__DM1 CYREG_PRT15_DM1
#define Rx_1__DM2 CYREG_PRT15_DM2
#define Rx_1__DR CYREG_PRT15_DR
#define Rx_1__INP_DIS CYREG_PRT15_INP_DIS
#define Rx_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define Rx_1__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define Rx_1__LCD_EN CYREG_PRT15_LCD_EN
#define Rx_1__MASK 0x04u
#define Rx_1__PORT 15u
#define Rx_1__PRT CYREG_PRT15_PRT
#define Rx_1__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define Rx_1__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define Rx_1__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define Rx_1__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define Rx_1__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define Rx_1__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define Rx_1__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define Rx_1__PS CYREG_PRT15_PS
#define Rx_1__SHIFT 2u
#define Rx_1__SLW CYREG_PRT15_SLW

/* SPIM */
#define SPIM_BSPIM_BitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB02_03_ACTL
#define SPIM_BSPIM_BitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB02_03_CTL
#define SPIM_BSPIM_BitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB02_03_CTL
#define SPIM_BSPIM_BitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB02_03_CTL
#define SPIM_BSPIM_BitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB02_03_CTL
#define SPIM_BSPIM_BitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB02_03_MSK
#define SPIM_BSPIM_BitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB02_03_MSK
#define SPIM_BSPIM_BitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB02_03_MSK
#define SPIM_BSPIM_BitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB02_03_MSK
#define SPIM_BSPIM_BitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB02_ACTL
#define SPIM_BSPIM_BitCounter__CONTROL_REG CYREG_B0_UDB02_CTL
#define SPIM_BSPIM_BitCounter__CONTROL_ST_REG CYREG_B0_UDB02_ST_CTL
#define SPIM_BSPIM_BitCounter__COUNT_REG CYREG_B0_UDB02_CTL
#define SPIM_BSPIM_BitCounter__COUNT_ST_REG CYREG_B0_UDB02_ST_CTL
#define SPIM_BSPIM_BitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB02_MSK_ACTL
#define SPIM_BSPIM_BitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB02_MSK_ACTL
#define SPIM_BSPIM_BitCounter__PERIOD_REG CYREG_B0_UDB02_MSK
#define SPIM_BSPIM_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB02_03_ACTL
#define SPIM_BSPIM_BitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB02_03_ST
#define SPIM_BSPIM_BitCounter_ST__MASK_REG CYREG_B0_UDB02_MSK
#define SPIM_BSPIM_BitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB02_MSK_ACTL
#define SPIM_BSPIM_BitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB02_MSK_ACTL
#define SPIM_BSPIM_BitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB02_ACTL
#define SPIM_BSPIM_BitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB02_ST_CTL
#define SPIM_BSPIM_BitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB02_ST_CTL
#define SPIM_BSPIM_BitCounter_ST__STATUS_REG CYREG_B0_UDB02_ST
#define SPIM_BSPIM_RxStsReg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB07_08_ACTL
#define SPIM_BSPIM_RxStsReg__16BIT_STATUS_REG CYREG_B0_UDB07_08_ST
#define SPIM_BSPIM_RxStsReg__4__MASK 0x10u
#define SPIM_BSPIM_RxStsReg__4__POS 4
#define SPIM_BSPIM_RxStsReg__5__MASK 0x20u
#define SPIM_BSPIM_RxStsReg__5__POS 5
#define SPIM_BSPIM_RxStsReg__6__MASK 0x40u
#define SPIM_BSPIM_RxStsReg__6__POS 6
#define SPIM_BSPIM_RxStsReg__MASK 0x70u
#define SPIM_BSPIM_RxStsReg__MASK_REG CYREG_B0_UDB07_MSK
#define SPIM_BSPIM_RxStsReg__STATUS_AUX_CTL_REG CYREG_B0_UDB07_ACTL
#define SPIM_BSPIM_RxStsReg__STATUS_REG CYREG_B0_UDB07_ST
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_A0_REG CYREG_B0_UDB05_06_A0
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_A1_REG CYREG_B0_UDB05_06_A1
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_D0_REG CYREG_B0_UDB05_06_D0
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_D1_REG CYREG_B0_UDB05_06_D1
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB05_06_ACTL
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_F0_REG CYREG_B0_UDB05_06_F0
#define SPIM_BSPIM_sR8_Dp_u0__16BIT_F1_REG CYREG_B0_UDB05_06_F1
#define SPIM_BSPIM_sR8_Dp_u0__A0_A1_REG CYREG_B0_UDB05_A0_A1
#define SPIM_BSPIM_sR8_Dp_u0__A0_REG CYREG_B0_UDB05_A0
#define SPIM_BSPIM_sR8_Dp_u0__A1_REG CYREG_B0_UDB05_A1
#define SPIM_BSPIM_sR8_Dp_u0__D0_D1_REG CYREG_B0_UDB05_D0_D1
#define SPIM_BSPIM_sR8_Dp_u0__D0_REG CYREG_B0_UDB05_D0
#define SPIM_BSPIM_sR8_Dp_u0__D1_REG CYREG_B0_UDB05_D1
#define SPIM_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG CYREG_B0_UDB05_ACTL
#define SPIM_BSPIM_sR8_Dp_u0__F0_F1_REG CYREG_B0_UDB05_F0_F1
#define SPIM_BSPIM_sR8_Dp_u0__F0_REG CYREG_B0_UDB05_F0
#define SPIM_BSPIM_sR8_Dp_u0__F1_REG CYREG_B0_UDB05_F1
#define SPIM_BSPIM_TxStsReg__0__MASK 0x01u
#define SPIM_BSPIM_TxStsReg__0__POS 0
#define SPIM_BSPIM_TxStsReg__1__MASK 0x02u
#define SPIM_BSPIM_TxStsReg__1__POS 1
#define SPIM_BSPIM_TxStsReg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB05_06_ACTL
#define SPIM_BSPIM_TxStsReg__16BIT_STATUS_REG CYREG_B0_UDB05_06_ST
#define SPIM_BSPIM_TxStsReg__2__MASK 0x04u
#define SPIM_BSPIM_TxStsReg__2__POS 2
#define SPIM_BSPIM_TxStsReg__3__MASK 0x08u
#define SPIM_BSPIM_TxStsReg__3__POS 3
#define SPIM_BSPIM_TxStsReg__4__MASK 0x10u
#define SPIM_BSPIM_TxStsReg__4__POS 4
#define SPIM_BSPIM_TxStsReg__MASK 0x1Fu
#define SPIM_BSPIM_TxStsReg__MASK_REG CYREG_B0_UDB05_MSK
#define SPIM_BSPIM_TxStsReg__STATUS_AUX_CTL_REG CYREG_B0_UDB05_ACTL
#define SPIM_BSPIM_TxStsReg__STATUS_REG CYREG_B0_UDB05_ST

/* Tx_1 */
#define Tx_1__0__INTTYPE CYREG_PICU15_INTTYPE1
#define Tx_1__0__MASK 0x02u
#define Tx_1__0__PC CYREG_IO_PC_PRT15_PC1
#define Tx_1__0__PORT 15u
#define Tx_1__0__SHIFT 1u
#define Tx_1__AG CYREG_PRT15_AG
#define Tx_1__AMUX CYREG_PRT15_AMUX
#define Tx_1__BIE CYREG_PRT15_BIE
#define Tx_1__BIT_MASK CYREG_PRT15_BIT_MASK
#define Tx_1__BYP CYREG_PRT15_BYP
#define Tx_1__CTL CYREG_PRT15_CTL
#define Tx_1__DM0 CYREG_PRT15_DM0
#define Tx_1__DM1 CYREG_PRT15_DM1
#define Tx_1__DM2 CYREG_PRT15_DM2
#define Tx_1__DR CYREG_PRT15_DR
#define Tx_1__INP_DIS CYREG_PRT15_INP_DIS
#define Tx_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define Tx_1__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define Tx_1__LCD_EN CYREG_PRT15_LCD_EN
#define Tx_1__MASK 0x02u
#define Tx_1__PORT 15u
#define Tx_1__PRT CYREG_PRT15_PRT
#define Tx_1__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define Tx_1__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define Tx_1__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define Tx_1__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define Tx_1__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define Tx_1__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define Tx_1__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define Tx_1__PS CYREG_PRT15_PS
#define Tx_1__SHIFT 1u
#define Tx_1__SLW CYREG_PRT15_SLW

/* UART */
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B1_UDB07_08_ACTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B1_UDB07_08_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG CYREG_B1_UDB07_08_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG CYREG_B1_UDB07_08_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG CYREG_B1_UDB07_08_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG CYREG_B1_UDB07_08_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG CYREG_B1_UDB07_08_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG CYREG_B1_UDB07_08_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B1_UDB07_08_MSK
#define UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG CYREG_B1_UDB07_ACTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_REG CYREG_B1_UDB07_CTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_ST_REG CYREG_B1_UDB07_ST_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_REG CYREG_B1_UDB07_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_ST_REG CYREG_B1_UDB07_ST_CTL
#define UART_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG CYREG_B1_UDB07_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG CYREG_B1_UDB07_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PERIOD_REG CYREG_B1_UDB07_MSK
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B1_UDB07_08_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG CYREG_B1_UDB07_08_ST
#define UART_BUART_sRX_RxBitCounter_ST__MASK_REG CYREG_B1_UDB07_MSK
#define UART_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B1_UDB07_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B1_UDB07_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG CYREG_B1_UDB07_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG CYREG_B1_UDB07_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG CYREG_B1_UDB07_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_REG CYREG_B1_UDB07_ST
#define UART_BUART_sRX_RxShifter_u0__16BIT_A0_REG CYREG_B0_UDB07_08_A0
#define UART_BUART_sRX_RxShifter_u0__16BIT_A1_REG CYREG_B0_UDB07_08_A1
#define UART_BUART_sRX_RxShifter_u0__16BIT_D0_REG CYREG_B0_UDB07_08_D0
#define UART_BUART_sRX_RxShifter_u0__16BIT_D1_REG CYREG_B0_UDB07_08_D1
#define UART_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB07_08_ACTL
#define UART_BUART_sRX_RxShifter_u0__16BIT_F0_REG CYREG_B0_UDB07_08_F0
#define UART_BUART_sRX_RxShifter_u0__16BIT_F1_REG CYREG_B0_UDB07_08_F1
#define UART_BUART_sRX_RxShifter_u0__A0_A1_REG CYREG_B0_UDB07_A0_A1
#define UART_BUART_sRX_RxShifter_u0__A0_REG CYREG_B0_UDB07_A0
#define UART_BUART_sRX_RxShifter_u0__A1_REG CYREG_B0_UDB07_A1
#define UART_BUART_sRX_RxShifter_u0__D0_D1_REG CYREG_B0_UDB07_D0_D1
#define UART_BUART_sRX_RxShifter_u0__D0_REG CYREG_B0_UDB07_D0
#define UART_BUART_sRX_RxShifter_u0__D1_REG CYREG_B0_UDB07_D1
#define UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB07_ACTL
#define UART_BUART_sRX_RxShifter_u0__F0_F1_REG CYREG_B0_UDB07_F0_F1
#define UART_BUART_sRX_RxShifter_u0__F0_REG CYREG_B0_UDB07_F0
#define UART_BUART_sRX_RxShifter_u0__F1_REG CYREG_B0_UDB07_F1
#define UART_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B1_UDB06_07_ACTL
#define UART_BUART_sRX_RxSts__16BIT_STATUS_REG CYREG_B1_UDB06_07_ST
#define UART_BUART_sRX_RxSts__3__MASK 0x08u
#define UART_BUART_sRX_RxSts__3__POS 3
#define UART_BUART_sRX_RxSts__4__MASK 0x10u
#define UART_BUART_sRX_RxSts__4__POS 4
#define UART_BUART_sRX_RxSts__5__MASK 0x20u
#define UART_BUART_sRX_RxSts__5__POS 5
#define UART_BUART_sRX_RxSts__MASK 0x38u
#define UART_BUART_sRX_RxSts__MASK_REG CYREG_B1_UDB06_MSK
#define UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG CYREG_B1_UDB06_ACTL
#define UART_BUART_sRX_RxSts__STATUS_REG CYREG_B1_UDB06_ST
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG CYREG_B0_UDB04_05_A0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG CYREG_B0_UDB04_05_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG CYREG_B0_UDB04_05_D0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG CYREG_B0_UDB04_05_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB04_05_ACTL
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG CYREG_B0_UDB04_05_F0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG CYREG_B0_UDB04_05_F1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG CYREG_B0_UDB04_A0_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG CYREG_B0_UDB04_A0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG CYREG_B0_UDB04_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG CYREG_B0_UDB04_D0_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG CYREG_B0_UDB04_D0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG CYREG_B0_UDB04_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG CYREG_B0_UDB04_ACTL
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG CYREG_B0_UDB04_F0_F1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG CYREG_B0_UDB04_F0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG CYREG_B0_UDB04_F1
#define UART_BUART_sTX_TxShifter_u0__16BIT_A0_REG CYREG_B0_UDB03_04_A0
#define UART_BUART_sTX_TxShifter_u0__16BIT_A1_REG CYREG_B0_UDB03_04_A1
#define UART_BUART_sTX_TxShifter_u0__16BIT_D0_REG CYREG_B0_UDB03_04_D0
#define UART_BUART_sTX_TxShifter_u0__16BIT_D1_REG CYREG_B0_UDB03_04_D1
#define UART_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB03_04_ACTL
#define UART_BUART_sTX_TxShifter_u0__16BIT_F0_REG CYREG_B0_UDB03_04_F0
#define UART_BUART_sTX_TxShifter_u0__16BIT_F1_REG CYREG_B0_UDB03_04_F1
#define UART_BUART_sTX_TxShifter_u0__A0_A1_REG CYREG_B0_UDB03_A0_A1
#define UART_BUART_sTX_TxShifter_u0__A0_REG CYREG_B0_UDB03_A0
#define UART_BUART_sTX_TxShifter_u0__A1_REG CYREG_B0_UDB03_A1
#define UART_BUART_sTX_TxShifter_u0__D0_D1_REG CYREG_B0_UDB03_D0_D1
#define UART_BUART_sTX_TxShifter_u0__D0_REG CYREG_B0_UDB03_D0
#define UART_BUART_sTX_TxShifter_u0__D1_REG CYREG_B0_UDB03_D1
#define UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB03_ACTL
#define UART_BUART_sTX_TxShifter_u0__F0_F1_REG CYREG_B0_UDB03_F0_F1
#define UART_BUART_sTX_TxShifter_u0__F0_REG CYREG_B0_UDB03_F0
#define UART_BUART_sTX_TxShifter_u0__F1_REG CYREG_B0_UDB03_F1
#define UART_BUART_sTX_TxSts__0__MASK 0x01u
#define UART_BUART_sTX_TxSts__0__POS 0
#define UART_BUART_sTX_TxSts__1__MASK 0x02u
#define UART_BUART_sTX_TxSts__1__POS 1
#define UART_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB03_04_ACTL
#define UART_BUART_sTX_TxSts__16BIT_STATUS_REG CYREG_B0_UDB03_04_ST
#define UART_BUART_sTX_TxSts__2__MASK 0x04u
#define UART_BUART_sTX_TxSts__2__POS 2
#define UART_BUART_sTX_TxSts__3__MASK 0x08u
#define UART_BUART_sTX_TxSts__3__POS 3
#define UART_BUART_sTX_TxSts__MASK 0x0Fu
#define UART_BUART_sTX_TxSts__MASK_REG CYREG_B0_UDB03_MSK
#define UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG CYREG_B0_UDB03_ACTL
#define UART_BUART_sTX_TxSts__STATUS_REG CYREG_B0_UDB03_ST
#define UART_TXInternalInterrupt__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define UART_TXInternalInterrupt__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define UART_TXInternalInterrupt__INTC_MASK 0x02u
#define UART_TXInternalInterrupt__INTC_NUMBER 1u
#define UART_TXInternalInterrupt__INTC_PRIOR_NUM 7u
#define UART_TXInternalInterrupt__INTC_PRIOR_REG CYREG_NVIC_PRI_1
#define UART_TXInternalInterrupt__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define UART_TXInternalInterrupt__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* DmaI2S */
#define DmaI2S__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define DmaI2S__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define DmaI2S__INTC_MASK 0x01u
#define DmaI2S__INTC_NUMBER 0u
#define DmaI2S__INTC_PRIOR_NUM 7u
#define DmaI2S__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define DmaI2S__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define DmaI2S__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* MISO_1 */
#define MISO_1__0__INTTYPE CYREG_PICU2_INTTYPE3
#define MISO_1__0__MASK 0x08u
#define MISO_1__0__PC CYREG_PRT2_PC3
#define MISO_1__0__PORT 2u
#define MISO_1__0__SHIFT 3u
#define MISO_1__AG CYREG_PRT2_AG
#define MISO_1__AMUX CYREG_PRT2_AMUX
#define MISO_1__BIE CYREG_PRT2_BIE
#define MISO_1__BIT_MASK CYREG_PRT2_BIT_MASK
#define MISO_1__BYP CYREG_PRT2_BYP
#define MISO_1__CTL CYREG_PRT2_CTL
#define MISO_1__DM0 CYREG_PRT2_DM0
#define MISO_1__DM1 CYREG_PRT2_DM1
#define MISO_1__DM2 CYREG_PRT2_DM2
#define MISO_1__DR CYREG_PRT2_DR
#define MISO_1__INP_DIS CYREG_PRT2_INP_DIS
#define MISO_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define MISO_1__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define MISO_1__LCD_EN CYREG_PRT2_LCD_EN
#define MISO_1__MASK 0x08u
#define MISO_1__PORT 2u
#define MISO_1__PRT CYREG_PRT2_PRT
#define MISO_1__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define MISO_1__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define MISO_1__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define MISO_1__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define MISO_1__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define MISO_1__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define MISO_1__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define MISO_1__PS CYREG_PRT2_PS
#define MISO_1__SHIFT 3u
#define MISO_1__SLW CYREG_PRT2_SLW

/* MOSI_1 */
#define MOSI_1__0__INTTYPE CYREG_PICU2_INTTYPE1
#define MOSI_1__0__MASK 0x02u
#define MOSI_1__0__PC CYREG_PRT2_PC1
#define MOSI_1__0__PORT 2u
#define MOSI_1__0__SHIFT 1u
#define MOSI_1__AG CYREG_PRT2_AG
#define MOSI_1__AMUX CYREG_PRT2_AMUX
#define MOSI_1__BIE CYREG_PRT2_BIE
#define MOSI_1__BIT_MASK CYREG_PRT2_BIT_MASK
#define MOSI_1__BYP CYREG_PRT2_BYP
#define MOSI_1__CTL CYREG_PRT2_CTL
#define MOSI_1__DM0 CYREG_PRT2_DM0
#define MOSI_1__DM1 CYREG_PRT2_DM1
#define MOSI_1__DM2 CYREG_PRT2_DM2
#define MOSI_1__DR CYREG_PRT2_DR
#define MOSI_1__INP_DIS CYREG_PRT2_INP_DIS
#define MOSI_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define MOSI_1__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define MOSI_1__LCD_EN CYREG_PRT2_LCD_EN
#define MOSI_1__MASK 0x02u
#define MOSI_1__PORT 2u
#define MOSI_1__PRT CYREG_PRT2_PRT
#define MOSI_1__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define MOSI_1__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define MOSI_1__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define MOSI_1__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define MOSI_1__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define MOSI_1__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define MOSI_1__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define MOSI_1__PS CYREG_PRT2_PS
#define MOSI_1__SHIFT 1u
#define MOSI_1__SLW CYREG_PRT2_SLW

/* SCLK_1 */
#define SCLK_1__0__INTTYPE CYREG_PICU2_INTTYPE0
#define SCLK_1__0__MASK 0x01u
#define SCLK_1__0__PC CYREG_PRT2_PC0
#define SCLK_1__0__PORT 2u
#define SCLK_1__0__SHIFT 0u
#define SCLK_1__AG CYREG_PRT2_AG
#define SCLK_1__AMUX CYREG_PRT2_AMUX
#define SCLK_1__BIE CYREG_PRT2_BIE
#define SCLK_1__BIT_MASK CYREG_PRT2_BIT_MASK
#define SCLK_1__BYP CYREG_PRT2_BYP
#define SCLK_1__CTL CYREG_PRT2_CTL
#define SCLK_1__DM0 CYREG_PRT2_DM0
#define SCLK_1__DM1 CYREG_PRT2_DM1
#define SCLK_1__DM2 CYREG_PRT2_DM2
#define SCLK_1__DR CYREG_PRT2_DR
#define SCLK_1__INP_DIS CYREG_PRT2_INP_DIS
#define SCLK_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define SCLK_1__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define SCLK_1__LCD_EN CYREG_PRT2_LCD_EN
#define SCLK_1__MASK 0x01u
#define SCLK_1__PORT 2u
#define SCLK_1__PRT CYREG_PRT2_PRT
#define SCLK_1__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define SCLK_1__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define SCLK_1__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define SCLK_1__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define SCLK_1__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define SCLK_1__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define SCLK_1__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define SCLK_1__PS CYREG_PRT2_PS
#define SCLK_1__SHIFT 0u
#define SCLK_1__SLW CYREG_PRT2_SLW

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG2_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG2_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG2_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__INDEX 0x02u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x04u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x04u

/* Clock_2 */
#define Clock_2__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define Clock_2__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define Clock_2__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define Clock_2__CFG2_SRC_SEL_MASK 0x07u
#define Clock_2__INDEX 0x01u
#define Clock_2__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_2__PM_ACT_MSK 0x02u
#define Clock_2__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_2__PM_STBY_MSK 0x02u

/* Clock_3 */
#define Clock_3__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Clock_3__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Clock_3__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Clock_3__CFG2_SRC_SEL_MASK 0x07u
#define Clock_3__INDEX 0x00u
#define Clock_3__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_3__PM_ACT_MSK 0x01u
#define Clock_3__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_3__PM_STBY_MSK 0x01u

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "SamplingCircuit"
#define CY_VERSION "PSoC Creator  4.4"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 26u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 26u
#define CYDEV_CHIP_MEMBER_4AA 25u
#define CYDEV_CHIP_MEMBER_4AB 30u
#define CYDEV_CHIP_MEMBER_4AC 14u
#define CYDEV_CHIP_MEMBER_4AD 15u
#define CYDEV_CHIP_MEMBER_4AE 16u
#define CYDEV_CHIP_MEMBER_4D 20u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 27u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 24u
#define CYDEV_CHIP_MEMBER_4I 32u
#define CYDEV_CHIP_MEMBER_4J 21u
#define CYDEV_CHIP_MEMBER_4K 22u
#define CYDEV_CHIP_MEMBER_4L 31u
#define CYDEV_CHIP_MEMBER_4M 29u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 28u
#define CYDEV_CHIP_MEMBER_4Q 17u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 23u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 18u
#define CYDEV_CHIP_MEMBER_4Z 19u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 33u
#define CYDEV_CHIP_MEMBER_FM3 37u
#define CYDEV_CHIP_MEMBER_FM4 38u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000002u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USB_CLK_OSC_LOCKING_ENABLED_AT_PWR_UP 
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYDEV_VDDIO0 3.3
#define CYDEV_VDDIO0_MV 3300
#define CYDEV_VDDIO1 3.3
#define CYDEV_VDDIO1_MV 3300
#define CYDEV_VDDIO2 3.3
#define CYDEV_VDDIO2_MV 3300
#define CYDEV_VDDIO3 3.3
#define CYDEV_VDDIO3_MV 3300
#define CYDEV_VIO0 3.3
#define CYDEV_VIO0_MV 3300
#define CYDEV_VIO1 3.3
#define CYDEV_VIO1_MV 3300
#define CYDEV_VIO2 3.3
#define CYDEV_VIO2_MV 3300
#define CYDEV_VIO3 3.3
#define CYDEV_VIO3_MV 3300
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000001u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
