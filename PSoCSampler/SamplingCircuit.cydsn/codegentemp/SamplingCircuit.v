// ======================================================================
// SamplingCircuit.v generated from TopDesign.cysch
// 05/07/2024 at 17:44
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_PSOC5LP 2
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 3
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_TMA4 4
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 5
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC6ABLE2 6
`define CYDEV_CHIP_REV_PSOC6ABLE2_ES 17
`define CYDEV_CHIP_REV_PSOC6ABLE2_PRODUCTION 33
`define CYDEV_CHIP_REV_PSOC6ABLE2_NO_UDB 33
`define CYDEV_CHIP_DIE_VOLANS 7
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 8
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 9
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 10
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 11
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 2
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 2
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4X 7
`define CYDEV_CHIP_REVISION_4X_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 8
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 9
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 10
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 11
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 12
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4W 13
`define CYDEV_CHIP_REVISION_4W_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AC 14
`define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AD 15
`define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AE 16
`define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 17
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Y 18
`define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Z 19
`define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 20
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 21
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 22
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 23
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 24
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AA 25
`define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 26
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 27
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 28
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 29
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AB 30
`define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 31
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 32
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 33
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 37
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 38
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 2
`define CYDEV_CHIP_REVISION_USED 0
// Component: bI2S_v2_70
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\bI2S_v2_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\bI2S_v2_70\bI2S_v2_70.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\bI2S_v2_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\bI2S_v2_70\bI2S_v2_70.v"
`endif

// I2S_v2_70(ClipPresent=false, ClockSyncMode=true, CommonClipThresholds=false, DataBits=32, Direction=1, EnableClipDetect=false, EnableRxByteSwap=false, EnableTxByteSwap=false, InterruptSource=0, NegThresholds=-1, NumRxChannels=0, NumRxLines=1, NumTxChannels=0, NumTxLines=1, PosThresholds=0u, RxDataInterleaved=true, RxDataInterleaving=1, RxDMA_present=1, RxDmaPresent=true, RxInterruptSource=0, RxStsReg0Present=true, RxStsReg1Present=false, RxStsReg2Present=false, StaticBitResolution=true, TermVisibility_clip=false, TermVisibility_clock=true, TermVisibility_rx_dma0=true, TermVisibility_rx_dma1=false, TermVisibility_rx_interrupt=true, TermVisibility_sck=true, TermVisibility_sdi=true, TermVisibility_sdo=false, TermVisibility_tx_dma0=false, TermVisibility_tx_dma1=false, TermVisibility_tx_interrupt=false, TermVisibility_ws=true, TxDataInterleaved=true, TxDataInterleaving=1, TxDMA_present=1, TxDmaPresent=false, TxInterruptSource=0, TxStsReg0Present=false, TxStsReg1Present=false, TxStsReg2Present=false, WordSelect=64, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=I2S_v2_70, CY_CONFIG_TITLE=I2Sthree, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2Sthree, CY_INSTANCE_SHORT_NAME=I2Sthree, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=I2Sthree, )
module I2S_v2_70_0 (
    clip,
    clock,
    rx_dma0,
    rx_dma1,
    rx_interrupt,
    sck,
    sdi,
    sdo,
    tx_dma0,
    tx_dma1,
    tx_interrupt,
    ws);
    output     [4:0] clip;
    input       clock;
    output     [4:0] rx_dma0;
    output     [4:0] rx_dma1;
    output      rx_interrupt;
    output      sck;
    input      [4:0] sdi;
    output     [4:0] sdo;
    output     [4:0] tx_dma0;
    output     [4:0] tx_dma1;
    output      tx_interrupt;
    output      ws;


          wire [4:0] tx_line;
          wire [4:0] tx_drq1;
          wire [4:0] rx_drq1;
          wire [4:0] tx_drq0;
          wire [4:0] rx_drq0;
          wire [4:0] rx_line;
          wire [4:0] clip_detect;

    bI2S_v2_70 bI2S (
        .clip(clip_detect[4:0]),
        .clock(clock),
        .rx_dma0(rx_drq0[4:0]),
        .rx_dma1(rx_drq1[4:0]),
        .rx_interrupt(rx_interrupt),
        .sck(sck),
        .sdi(rx_line[4:0]),
        .sdo(tx_line[4:0]),
        .tx_dma0(tx_drq0[4:0]),
        .tx_dma1(tx_drq1[4:0]),
        .tx_interrupt(tx_interrupt),
        .ws(ws));
    defparam bI2S.ClockSyncMode = 1;
    defparam bI2S.DataBits = 32;
    defparam bI2S.Direction = 1;
    defparam bI2S.EnableClipDetect = 0;
    defparam bI2S.EnableRxByteSwap = 0;
    defparam bI2S.EnableTxByteSwap = 0;
    defparam bI2S.NumRxChannels = 0;
    defparam bI2S.NumTxChannels = 0;
    defparam bI2S.RxDataInterleaving = 1;
    defparam bI2S.StaticBitResolution = 1;
    defparam bI2S.TxDataInterleaving = 1;
    defparam bI2S.WordSelect = 64;


    assign clip = clip_detect[4:0];

    assign rx_dma0 = rx_drq0[4:0];

    assign rx_dma1 = rx_drq1[4:0];

    assign rx_line[4:0] = sdi;

    assign sdo = tx_line[4:0];

    assign tx_dma0 = tx_drq0[4:0];

    assign tx_dma1 = tx_drq1[4:0];


endmodule

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: B_SPI_Master_v2_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_SPI_Master_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_SPI_Master_v2_50\B_SPI_Master_v2_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_SPI_Master_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\B_SPI_Master_v2_50\B_SPI_Master_v2_50.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.4\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// SPI_Master_v2_50(BidirectMode=false, ClockInternal=false, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DesiredBitRate=1000, HighSpeedMode=true, InternalClockUsed=0, InternalInterruptEnabled=0, InternalRxInterruptEnabled=0, InternalTxInterruptEnabled=0, InterruptOnByteComplete=false, InterruptOnRXFull=false, InterruptOnRXNotEmpty=false, InterruptOnRXOverrun=false, InterruptOnSPIDone=false, InterruptOnSPIIdle=false, InterruptOnTXEmpty=true, InterruptOnTXNotFull=false, IntOnByteComp=0, IntOnRXFull=0, IntOnRXNotEmpty=0, IntOnRXOver=0, IntOnSPIDone=0, IntOnSPIIdle=0, IntOnTXEmpty=1, IntOnTXNotFull=0, Mode=1, ModeUseZero=1, NumberOfDataBits=8, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, RxBufferSize=4, ShiftDir=0, TxBufferSize=4, UseInternalInterrupt=false, UseRxInternalInterrupt=false, UseTxInternalInterrupt=false, VerilogSectionReplacementString=sR8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=SPI_Master_v2_50, CY_CONFIG_TITLE=SPIM, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SPIM, CY_INSTANCE_SHORT_NAME=SPIM, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=50, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=SPIM, )
module SPI_Master_v2_50_1 (
    clock,
    miso,
    mosi,
    reset,
    rx_interrupt,
    sclk,
    sdat,
    ss,
    tx_interrupt);
    input       clock;
    input       miso;
    output      mosi;
    input       reset;
    output      rx_interrupt;
    output      sclk;
    inout       sdat;
    output      ss;
    output      tx_interrupt;

    parameter BidirectMode = 0;
    parameter HighSpeedMode = 1;
    parameter NumberOfDataBits = 8;
    parameter ShiftDir = 0;

          wire  Net_289;
          wire  Net_257;
          wire  Net_288;
          wire  Net_294;
          wire  Net_161;
          wire  Net_244;
          wire  Net_273;
          wire  Net_276;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_276 = clock;

    B_SPI_Master_v2_50 BSPIM (
        .clock(Net_276),
        .miso(Net_244),
        .mosi(mosi),
        .reset(Net_273),
        .rx_interpt(rx_interrupt),
        .sclk(sclk),
        .ss(ss),
        .tx_enable(Net_294),
        .tx_interpt(tx_interrupt));
    defparam BSPIM.BidirectMode = 0;
    defparam BSPIM.HighSpeedMode = 1;
    defparam BSPIM.ModeCPHA = 0;
    defparam BSPIM.ModePOL = 0;
    defparam BSPIM.NumberOfDataBits = 8;
    defparam BSPIM.ShiftDir = 0;

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_244 = miso;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_273 = Net_289;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_289));



endmodule

// I2S_v2_70(ClipPresent=false, ClockSyncMode=true, CommonClipThresholds=false, DataBits=32, Direction=1, EnableClipDetect=false, EnableRxByteSwap=false, EnableTxByteSwap=false, InterruptSource=0, NegThresholds=-1, NumRxChannels=0, NumRxLines=1, NumTxChannels=0, NumTxLines=1, PosThresholds=0u, RxDataInterleaved=true, RxDataInterleaving=1, RxDMA_present=1, RxDmaPresent=true, RxInterruptSource=0, RxStsReg0Present=true, RxStsReg1Present=false, RxStsReg2Present=false, StaticBitResolution=true, TermVisibility_clip=false, TermVisibility_clock=true, TermVisibility_rx_dma0=true, TermVisibility_rx_dma1=false, TermVisibility_rx_interrupt=true, TermVisibility_sck=true, TermVisibility_sdi=true, TermVisibility_sdo=false, TermVisibility_tx_dma0=false, TermVisibility_tx_dma1=false, TermVisibility_tx_interrupt=false, TermVisibility_ws=true, TxDataInterleaved=true, TxDataInterleaving=1, TxDMA_present=1, TxDmaPresent=false, TxInterruptSource=0, TxStsReg0Present=false, TxStsReg1Present=false, TxStsReg2Present=false, WordSelect=64, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=I2S_v2_70, CY_CONFIG_TITLE=I2Sone, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2Sone, CY_INSTANCE_SHORT_NAME=I2Sone, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=I2Sone, )
module I2S_v2_70_2 (
    clip,
    clock,
    rx_dma0,
    rx_dma1,
    rx_interrupt,
    sck,
    sdi,
    sdo,
    tx_dma0,
    tx_dma1,
    tx_interrupt,
    ws);
    output     [4:0] clip;
    input       clock;
    output     [4:0] rx_dma0;
    output     [4:0] rx_dma1;
    output      rx_interrupt;
    output      sck;
    input      [4:0] sdi;
    output     [4:0] sdo;
    output     [4:0] tx_dma0;
    output     [4:0] tx_dma1;
    output      tx_interrupt;
    output      ws;


          wire [4:0] tx_line;
          wire [4:0] tx_drq1;
          wire [4:0] rx_drq1;
          wire [4:0] tx_drq0;
          wire [4:0] rx_drq0;
          wire [4:0] rx_line;
          wire [4:0] clip_detect;

    bI2S_v2_70 bI2S (
        .clip(clip_detect[4:0]),
        .clock(clock),
        .rx_dma0(rx_drq0[4:0]),
        .rx_dma1(rx_drq1[4:0]),
        .rx_interrupt(rx_interrupt),
        .sck(sck),
        .sdi(rx_line[4:0]),
        .sdo(tx_line[4:0]),
        .tx_dma0(tx_drq0[4:0]),
        .tx_dma1(tx_drq1[4:0]),
        .tx_interrupt(tx_interrupt),
        .ws(ws));
    defparam bI2S.ClockSyncMode = 1;
    defparam bI2S.DataBits = 32;
    defparam bI2S.Direction = 1;
    defparam bI2S.EnableClipDetect = 0;
    defparam bI2S.EnableRxByteSwap = 0;
    defparam bI2S.EnableTxByteSwap = 0;
    defparam bI2S.NumRxChannels = 0;
    defparam bI2S.NumTxChannels = 0;
    defparam bI2S.RxDataInterleaving = 1;
    defparam bI2S.StaticBitResolution = 1;
    defparam bI2S.TxDataInterleaving = 1;
    defparam bI2S.WordSelect = 64;


    assign clip = clip_detect[4:0];

    assign rx_dma0 = rx_drq0[4:0];

    assign rx_dma1 = rx_drq1[4:0];

    assign rx_line[4:0] = sdi;

    assign sdo = tx_line[4:0];

    assign tx_dma0 = tx_drq0[4:0];

    assign tx_dma1 = tx_drq1[4:0];


endmodule

// I2S_v2_70(ClipPresent=false, ClockSyncMode=true, CommonClipThresholds=false, DataBits=32, Direction=1, EnableClipDetect=false, EnableRxByteSwap=false, EnableTxByteSwap=false, InterruptSource=0, NegThresholds=-1, NumRxChannels=0, NumRxLines=1, NumTxChannels=0, NumTxLines=1, PosThresholds=0u, RxDataInterleaved=true, RxDataInterleaving=1, RxDMA_present=1, RxDmaPresent=true, RxInterruptSource=0, RxStsReg0Present=true, RxStsReg1Present=false, RxStsReg2Present=false, StaticBitResolution=true, TermVisibility_clip=false, TermVisibility_clock=true, TermVisibility_rx_dma0=true, TermVisibility_rx_dma1=false, TermVisibility_rx_interrupt=true, TermVisibility_sck=true, TermVisibility_sdi=true, TermVisibility_sdo=false, TermVisibility_tx_dma0=false, TermVisibility_tx_dma1=false, TermVisibility_tx_interrupt=false, TermVisibility_ws=true, TxDataInterleaved=true, TxDataInterleaving=1, TxDMA_present=1, TxDmaPresent=false, TxInterruptSource=0, TxStsReg0Present=false, TxStsReg1Present=false, TxStsReg2Present=false, WordSelect=64, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=I2S_v2_70, CY_CONFIG_TITLE=I2Stwo, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2Stwo, CY_INSTANCE_SHORT_NAME=I2Stwo, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=I2Stwo, )
module I2S_v2_70_3 (
    clip,
    clock,
    rx_dma0,
    rx_dma1,
    rx_interrupt,
    sck,
    sdi,
    sdo,
    tx_dma0,
    tx_dma1,
    tx_interrupt,
    ws);
    output     [4:0] clip;
    input       clock;
    output     [4:0] rx_dma0;
    output     [4:0] rx_dma1;
    output      rx_interrupt;
    output      sck;
    input      [4:0] sdi;
    output     [4:0] sdo;
    output     [4:0] tx_dma0;
    output     [4:0] tx_dma1;
    output      tx_interrupt;
    output      ws;


          wire [4:0] tx_line;
          wire [4:0] tx_drq1;
          wire [4:0] rx_drq1;
          wire [4:0] tx_drq0;
          wire [4:0] rx_drq0;
          wire [4:0] rx_line;
          wire [4:0] clip_detect;

    bI2S_v2_70 bI2S (
        .clip(clip_detect[4:0]),
        .clock(clock),
        .rx_dma0(rx_drq0[4:0]),
        .rx_dma1(rx_drq1[4:0]),
        .rx_interrupt(rx_interrupt),
        .sck(sck),
        .sdi(rx_line[4:0]),
        .sdo(tx_line[4:0]),
        .tx_dma0(tx_drq0[4:0]),
        .tx_dma1(tx_drq1[4:0]),
        .tx_interrupt(tx_interrupt),
        .ws(ws));
    defparam bI2S.ClockSyncMode = 1;
    defparam bI2S.DataBits = 32;
    defparam bI2S.Direction = 1;
    defparam bI2S.EnableClipDetect = 0;
    defparam bI2S.EnableRxByteSwap = 0;
    defparam bI2S.EnableTxByteSwap = 0;
    defparam bI2S.NumRxChannels = 0;
    defparam bI2S.NumTxChannels = 0;
    defparam bI2S.RxDataInterleaving = 1;
    defparam bI2S.StaticBitResolution = 1;
    defparam bI2S.TxDataInterleaving = 1;
    defparam bI2S.WordSelect = 64;


    assign clip = clip_detect[4:0];

    assign rx_dma0 = rx_drq0[4:0];

    assign rx_dma1 = rx_drq1[4:0];

    assign rx_line[4:0] = sdi;

    assign sdo = tx_line[4:0];

    assign tx_dma0 = tx_drq0[4:0];

    assign tx_dma1 = tx_drq1[4:0];


endmodule

// I2S_v2_70(ClipPresent=false, ClockSyncMode=true, CommonClipThresholds=false, DataBits=32, Direction=1, EnableClipDetect=false, EnableRxByteSwap=false, EnableTxByteSwap=false, InterruptSource=0, NegThresholds=-1, NumRxChannels=0, NumRxLines=1, NumTxChannels=0, NumTxLines=1, PosThresholds=0u, RxDataInterleaved=true, RxDataInterleaving=1, RxDMA_present=1, RxDmaPresent=true, RxInterruptSource=0, RxStsReg0Present=true, RxStsReg1Present=false, RxStsReg2Present=false, StaticBitResolution=true, TermVisibility_clip=false, TermVisibility_clock=true, TermVisibility_rx_dma0=true, TermVisibility_rx_dma1=false, TermVisibility_rx_interrupt=true, TermVisibility_sck=true, TermVisibility_sdi=true, TermVisibility_sdo=false, TermVisibility_tx_dma0=false, TermVisibility_tx_dma1=false, TermVisibility_tx_interrupt=false, TermVisibility_ws=true, TxDataInterleaved=true, TxDataInterleaving=1, TxDMA_present=1, TxDmaPresent=false, TxInterruptSource=0, TxStsReg0Present=false, TxStsReg1Present=false, TxStsReg2Present=false, WordSelect=64, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=I2S_v2_70, CY_CONFIG_TITLE=I2Sfour, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2Sfour, CY_INSTANCE_SHORT_NAME=I2Sfour, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=I2Sfour, )
module I2S_v2_70_4 (
    clip,
    clock,
    rx_dma0,
    rx_dma1,
    rx_interrupt,
    sck,
    sdi,
    sdo,
    tx_dma0,
    tx_dma1,
    tx_interrupt,
    ws);
    output     [4:0] clip;
    input       clock;
    output     [4:0] rx_dma0;
    output     [4:0] rx_dma1;
    output      rx_interrupt;
    output      sck;
    input      [4:0] sdi;
    output     [4:0] sdo;
    output     [4:0] tx_dma0;
    output     [4:0] tx_dma1;
    output      tx_interrupt;
    output      ws;


          wire [4:0] tx_line;
          wire [4:0] tx_drq1;
          wire [4:0] rx_drq1;
          wire [4:0] tx_drq0;
          wire [4:0] rx_drq0;
          wire [4:0] rx_line;
          wire [4:0] clip_detect;

    bI2S_v2_70 bI2S (
        .clip(clip_detect[4:0]),
        .clock(clock),
        .rx_dma0(rx_drq0[4:0]),
        .rx_dma1(rx_drq1[4:0]),
        .rx_interrupt(rx_interrupt),
        .sck(sck),
        .sdi(rx_line[4:0]),
        .sdo(tx_line[4:0]),
        .tx_dma0(tx_drq0[4:0]),
        .tx_dma1(tx_drq1[4:0]),
        .tx_interrupt(tx_interrupt),
        .ws(ws));
    defparam bI2S.ClockSyncMode = 1;
    defparam bI2S.DataBits = 32;
    defparam bI2S.Direction = 1;
    defparam bI2S.EnableClipDetect = 0;
    defparam bI2S.EnableRxByteSwap = 0;
    defparam bI2S.EnableTxByteSwap = 0;
    defparam bI2S.NumRxChannels = 0;
    defparam bI2S.NumTxChannels = 0;
    defparam bI2S.RxDataInterleaving = 1;
    defparam bI2S.StaticBitResolution = 1;
    defparam bI2S.TxDataInterleaving = 1;
    defparam bI2S.WordSelect = 64;


    assign clip = clip_detect[4:0];

    assign rx_dma0 = rx_drq0[4:0];

    assign rx_dma1 = rx_drq1[4:0];

    assign rx_line[4:0] = sdi;

    assign sdo = tx_line[4:0];

    assign tx_dma0 = tx_drq0[4:0];

    assign tx_dma1 = tx_drq1[4:0];


endmodule

// I2S_v2_70(ClipPresent=false, ClockSyncMode=true, CommonClipThresholds=false, DataBits=32, Direction=1, EnableClipDetect=false, EnableRxByteSwap=false, EnableTxByteSwap=false, InterruptSource=0, NegThresholds=-1, NumRxChannels=0, NumRxLines=1, NumTxChannels=0, NumTxLines=1, PosThresholds=0u, RxDataInterleaved=true, RxDataInterleaving=1, RxDMA_present=1, RxDmaPresent=true, RxInterruptSource=0, RxStsReg0Present=true, RxStsReg1Present=false, RxStsReg2Present=false, StaticBitResolution=true, TermVisibility_clip=false, TermVisibility_clock=true, TermVisibility_rx_dma0=true, TermVisibility_rx_dma1=false, TermVisibility_rx_interrupt=true, TermVisibility_sck=true, TermVisibility_sdi=true, TermVisibility_sdo=false, TermVisibility_tx_dma0=false, TermVisibility_tx_dma1=false, TermVisibility_tx_interrupt=false, TermVisibility_ws=true, TxDataInterleaved=true, TxDataInterleaving=1, TxDMA_present=1, TxDmaPresent=false, TxInterruptSource=0, TxStsReg0Present=false, TxStsReg1Present=false, TxStsReg2Present=false, WordSelect=64, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=I2S_v2_70, CY_CONFIG_TITLE=I2Ssix, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2Ssix, CY_INSTANCE_SHORT_NAME=I2Ssix, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=I2Ssix, )
module I2S_v2_70_5 (
    clip,
    clock,
    rx_dma0,
    rx_dma1,
    rx_interrupt,
    sck,
    sdi,
    sdo,
    tx_dma0,
    tx_dma1,
    tx_interrupt,
    ws);
    output     [4:0] clip;
    input       clock;
    output     [4:0] rx_dma0;
    output     [4:0] rx_dma1;
    output      rx_interrupt;
    output      sck;
    input      [4:0] sdi;
    output     [4:0] sdo;
    output     [4:0] tx_dma0;
    output     [4:0] tx_dma1;
    output      tx_interrupt;
    output      ws;


          wire [4:0] tx_line;
          wire [4:0] tx_drq1;
          wire [4:0] rx_drq1;
          wire [4:0] tx_drq0;
          wire [4:0] rx_drq0;
          wire [4:0] rx_line;
          wire [4:0] clip_detect;

    bI2S_v2_70 bI2S (
        .clip(clip_detect[4:0]),
        .clock(clock),
        .rx_dma0(rx_drq0[4:0]),
        .rx_dma1(rx_drq1[4:0]),
        .rx_interrupt(rx_interrupt),
        .sck(sck),
        .sdi(rx_line[4:0]),
        .sdo(tx_line[4:0]),
        .tx_dma0(tx_drq0[4:0]),
        .tx_dma1(tx_drq1[4:0]),
        .tx_interrupt(tx_interrupt),
        .ws(ws));
    defparam bI2S.ClockSyncMode = 1;
    defparam bI2S.DataBits = 32;
    defparam bI2S.Direction = 1;
    defparam bI2S.EnableClipDetect = 0;
    defparam bI2S.EnableRxByteSwap = 0;
    defparam bI2S.EnableTxByteSwap = 0;
    defparam bI2S.NumRxChannels = 0;
    defparam bI2S.NumTxChannels = 0;
    defparam bI2S.RxDataInterleaving = 1;
    defparam bI2S.StaticBitResolution = 1;
    defparam bI2S.TxDataInterleaving = 1;
    defparam bI2S.WordSelect = 64;


    assign clip = clip_detect[4:0];

    assign rx_dma0 = rx_drq0[4:0];

    assign rx_dma1 = rx_drq1[4:0];

    assign rx_line[4:0] = sdi;

    assign sdo = tx_line[4:0];

    assign tx_dma0 = tx_drq0[4:0];

    assign tx_dma1 = tx_drq1[4:0];


endmodule

// I2S_v2_70(ClipPresent=false, ClockSyncMode=true, CommonClipThresholds=false, DataBits=32, Direction=1, EnableClipDetect=false, EnableRxByteSwap=false, EnableTxByteSwap=false, InterruptSource=0, NegThresholds=-1, NumRxChannels=0, NumRxLines=1, NumTxChannels=0, NumTxLines=1, PosThresholds=0u, RxDataInterleaved=true, RxDataInterleaving=1, RxDMA_present=1, RxDmaPresent=true, RxInterruptSource=0, RxStsReg0Present=true, RxStsReg1Present=false, RxStsReg2Present=false, StaticBitResolution=true, TermVisibility_clip=false, TermVisibility_clock=true, TermVisibility_rx_dma0=true, TermVisibility_rx_dma1=false, TermVisibility_rx_interrupt=true, TermVisibility_sck=true, TermVisibility_sdi=true, TermVisibility_sdo=false, TermVisibility_tx_dma0=false, TermVisibility_tx_dma1=false, TermVisibility_tx_interrupt=false, TermVisibility_ws=true, TxDataInterleaved=true, TxDataInterleaving=1, TxDMA_present=1, TxDmaPresent=false, TxInterruptSource=0, TxStsReg0Present=false, TxStsReg1Present=false, TxStsReg2Present=false, WordSelect=64, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=I2S_v2_70, CY_CONFIG_TITLE=I2Sfive, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2Sfive, CY_INSTANCE_SHORT_NAME=I2Sfive, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=I2Sfive, )
module I2S_v2_70_6 (
    clip,
    clock,
    rx_dma0,
    rx_dma1,
    rx_interrupt,
    sck,
    sdi,
    sdo,
    tx_dma0,
    tx_dma1,
    tx_interrupt,
    ws);
    output     [4:0] clip;
    input       clock;
    output     [4:0] rx_dma0;
    output     [4:0] rx_dma1;
    output      rx_interrupt;
    output      sck;
    input      [4:0] sdi;
    output     [4:0] sdo;
    output     [4:0] tx_dma0;
    output     [4:0] tx_dma1;
    output      tx_interrupt;
    output      ws;


          wire [4:0] tx_line;
          wire [4:0] tx_drq1;
          wire [4:0] rx_drq1;
          wire [4:0] tx_drq0;
          wire [4:0] rx_drq0;
          wire [4:0] rx_line;
          wire [4:0] clip_detect;

    bI2S_v2_70 bI2S (
        .clip(clip_detect[4:0]),
        .clock(clock),
        .rx_dma0(rx_drq0[4:0]),
        .rx_dma1(rx_drq1[4:0]),
        .rx_interrupt(rx_interrupt),
        .sck(sck),
        .sdi(rx_line[4:0]),
        .sdo(tx_line[4:0]),
        .tx_dma0(tx_drq0[4:0]),
        .tx_dma1(tx_drq1[4:0]),
        .tx_interrupt(tx_interrupt),
        .ws(ws));
    defparam bI2S.ClockSyncMode = 1;
    defparam bI2S.DataBits = 32;
    defparam bI2S.Direction = 1;
    defparam bI2S.EnableClipDetect = 0;
    defparam bI2S.EnableRxByteSwap = 0;
    defparam bI2S.EnableTxByteSwap = 0;
    defparam bI2S.NumRxChannels = 0;
    defparam bI2S.NumTxChannels = 0;
    defparam bI2S.RxDataInterleaving = 1;
    defparam bI2S.StaticBitResolution = 1;
    defparam bI2S.TxDataInterleaving = 1;
    defparam bI2S.WordSelect = 64;


    assign clip = clip_detect[4:0];

    assign rx_dma0 = rx_drq0[4:0];

    assign rx_dma1 = rx_drq1[4:0];

    assign rx_line[4:0] = sdi;

    assign sdo = tx_line[4:0];

    assign tx_dma0 = tx_drq0[4:0];

    assign tx_dma1 = tx_drq1[4:0];


endmodule

// I2S_v2_70(ClipPresent=false, ClockSyncMode=true, CommonClipThresholds=false, DataBits=32, Direction=1, EnableClipDetect=false, EnableRxByteSwap=false, EnableTxByteSwap=false, InterruptSource=0, NegThresholds=-1, NumRxChannels=0, NumRxLines=1, NumTxChannels=0, NumTxLines=1, PosThresholds=0u, RxDataInterleaved=true, RxDataInterleaving=1, RxDMA_present=1, RxDmaPresent=true, RxInterruptSource=0, RxStsReg0Present=true, RxStsReg1Present=false, RxStsReg2Present=false, StaticBitResolution=true, TermVisibility_clip=false, TermVisibility_clock=true, TermVisibility_rx_dma0=true, TermVisibility_rx_dma1=false, TermVisibility_rx_interrupt=true, TermVisibility_sck=true, TermVisibility_sdi=true, TermVisibility_sdo=false, TermVisibility_tx_dma0=false, TermVisibility_tx_dma1=false, TermVisibility_tx_interrupt=false, TermVisibility_ws=true, TxDataInterleaved=true, TxDataInterleaving=1, TxDMA_present=1, TxDmaPresent=false, TxInterruptSource=0, TxStsReg0Present=false, TxStsReg1Present=false, TxStsReg2Present=false, WordSelect=64, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=I2S_v2_70, CY_CONFIG_TITLE=I2Sseven, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2Sseven, CY_INSTANCE_SHORT_NAME=I2Sseven, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=I2Sseven, )
module I2S_v2_70_7 (
    clip,
    clock,
    rx_dma0,
    rx_dma1,
    rx_interrupt,
    sck,
    sdi,
    sdo,
    tx_dma0,
    tx_dma1,
    tx_interrupt,
    ws);
    output     [4:0] clip;
    input       clock;
    output     [4:0] rx_dma0;
    output     [4:0] rx_dma1;
    output      rx_interrupt;
    output      sck;
    input      [4:0] sdi;
    output     [4:0] sdo;
    output     [4:0] tx_dma0;
    output     [4:0] tx_dma1;
    output      tx_interrupt;
    output      ws;


          wire [4:0] tx_line;
          wire [4:0] tx_drq1;
          wire [4:0] rx_drq1;
          wire [4:0] tx_drq0;
          wire [4:0] rx_drq0;
          wire [4:0] rx_line;
          wire [4:0] clip_detect;

    bI2S_v2_70 bI2S (
        .clip(clip_detect[4:0]),
        .clock(clock),
        .rx_dma0(rx_drq0[4:0]),
        .rx_dma1(rx_drq1[4:0]),
        .rx_interrupt(rx_interrupt),
        .sck(sck),
        .sdi(rx_line[4:0]),
        .sdo(tx_line[4:0]),
        .tx_dma0(tx_drq0[4:0]),
        .tx_dma1(tx_drq1[4:0]),
        .tx_interrupt(tx_interrupt),
        .ws(ws));
    defparam bI2S.ClockSyncMode = 1;
    defparam bI2S.DataBits = 32;
    defparam bI2S.Direction = 1;
    defparam bI2S.EnableClipDetect = 0;
    defparam bI2S.EnableRxByteSwap = 0;
    defparam bI2S.EnableTxByteSwap = 0;
    defparam bI2S.NumRxChannels = 0;
    defparam bI2S.NumTxChannels = 0;
    defparam bI2S.RxDataInterleaving = 1;
    defparam bI2S.StaticBitResolution = 1;
    defparam bI2S.TxDataInterleaving = 1;
    defparam bI2S.WordSelect = 64;


    assign clip = clip_detect[4:0];

    assign rx_dma0 = rx_drq0[4:0];

    assign rx_dma1 = rx_drq1[4:0];

    assign rx_line[4:0] = sdi;

    assign sdo = tx_line[4:0];

    assign tx_dma0 = tx_drq0[4:0];

    assign tx_dma1 = tx_drq1[4:0];


endmodule

// I2S_v2_70(ClipPresent=false, ClockSyncMode=true, CommonClipThresholds=false, DataBits=32, Direction=1, EnableClipDetect=false, EnableRxByteSwap=false, EnableTxByteSwap=false, InterruptSource=0, NegThresholds=-1, NumRxChannels=0, NumRxLines=1, NumTxChannels=0, NumTxLines=1, PosThresholds=0u, RxDataInterleaved=true, RxDataInterleaving=1, RxDMA_present=1, RxDmaPresent=true, RxInterruptSource=0, RxStsReg0Present=true, RxStsReg1Present=false, RxStsReg2Present=false, StaticBitResolution=true, TermVisibility_clip=false, TermVisibility_clock=true, TermVisibility_rx_dma0=true, TermVisibility_rx_dma1=false, TermVisibility_rx_interrupt=true, TermVisibility_sck=true, TermVisibility_sdi=true, TermVisibility_sdo=false, TermVisibility_tx_dma0=false, TermVisibility_tx_dma1=false, TermVisibility_tx_interrupt=false, TermVisibility_ws=true, TxDataInterleaved=true, TxDataInterleaving=1, TxDMA_present=1, TxDmaPresent=false, TxInterruptSource=0, TxStsReg0Present=false, TxStsReg1Present=false, TxStsReg2Present=false, WordSelect=64, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=I2S_v2_70, CY_CONFIG_TITLE=I2Seight, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2Seight, CY_INSTANCE_SHORT_NAME=I2Seight, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.4, INSTANCE_NAME=I2Seight, )
module I2S_v2_70_8 (
    clip,
    clock,
    rx_dma0,
    rx_dma1,
    rx_interrupt,
    sck,
    sdi,
    sdo,
    tx_dma0,
    tx_dma1,
    tx_interrupt,
    ws);
    output     [4:0] clip;
    input       clock;
    output     [4:0] rx_dma0;
    output     [4:0] rx_dma1;
    output      rx_interrupt;
    output      sck;
    input      [4:0] sdi;
    output     [4:0] sdo;
    output     [4:0] tx_dma0;
    output     [4:0] tx_dma1;
    output      tx_interrupt;
    output      ws;


          wire [4:0] tx_line;
          wire [4:0] tx_drq1;
          wire [4:0] rx_drq1;
          wire [4:0] tx_drq0;
          wire [4:0] rx_drq0;
          wire [4:0] rx_line;
          wire [4:0] clip_detect;

    bI2S_v2_70 bI2S (
        .clip(clip_detect[4:0]),
        .clock(clock),
        .rx_dma0(rx_drq0[4:0]),
        .rx_dma1(rx_drq1[4:0]),
        .rx_interrupt(rx_interrupt),
        .sck(sck),
        .sdi(rx_line[4:0]),
        .sdo(tx_line[4:0]),
        .tx_dma0(tx_drq0[4:0]),
        .tx_dma1(tx_drq1[4:0]),
        .tx_interrupt(tx_interrupt),
        .ws(ws));
    defparam bI2S.ClockSyncMode = 1;
    defparam bI2S.DataBits = 32;
    defparam bI2S.Direction = 1;
    defparam bI2S.EnableClipDetect = 0;
    defparam bI2S.EnableRxByteSwap = 0;
    defparam bI2S.EnableTxByteSwap = 0;
    defparam bI2S.NumRxChannels = 0;
    defparam bI2S.NumTxChannels = 0;
    defparam bI2S.RxDataInterleaving = 1;
    defparam bI2S.StaticBitResolution = 1;
    defparam bI2S.TxDataInterleaving = 1;
    defparam bI2S.WordSelect = 64;


    assign clip = clip_detect[4:0];

    assign rx_dma0 = rx_drq0[4:0];

    assign rx_dma1 = rx_drq1[4:0];

    assign rx_line[4:0] = sdi;

    assign sdo = tx_line[4:0];

    assign tx_dma0 = tx_drq0[4:0];

    assign tx_dma1 = tx_drq1[4:0];


endmodule

// top
module top ;

          wire  Net_748;
          wire  Net_749;
          wire  Net_727;
          wire  Net_724;
          wire [0:0] Net_723;
          wire [0:0] Net_722;
          wire [0:0] Net_721;
          wire  Net_719;
          wire  Net_718;
          wire [0:0] Net_717;
          wire [0:0] Net_714;
          wire  Net_713;
          wire  Net_710;
          wire [0:0] Net_709;
          wire [0:0] Net_708;
          wire [0:0] Net_707;
          wire  Net_705;
          wire  Net_704;
          wire [0:0] Net_703;
          wire [0:0] Net_700;
          wire  Net_699;
          wire  Net_696;
          wire [0:0] Net_695;
          wire [0:0] Net_694;
          wire [0:0] Net_693;
          wire  Net_691;
          wire  Net_690;
          wire [0:0] Net_689;
          wire [0:0] Net_686;
          wire  Net_685;
          wire  Net_682;
          wire [0:0] Net_681;
          wire [0:0] Net_680;
          wire [0:0] Net_679;
          wire  Net_677;
          wire  Net_676;
          wire [0:0] Net_675;
          wire [0:0] Net_672;
          wire  Net_670;
          wire  Net_667;
          wire [0:0] Net_666;
          wire [0:0] Net_665;
          wire [0:0] Net_664;
          wire  Net_662;
          wire  Net_661;
          wire [0:0] Net_660;
          wire [0:0] Net_657;
          wire  Net_634;
          wire [0:0] Net_633;
          wire [0:0] Net_632;
          wire [0:0] Net_631;
          wire  Net_73;
          wire  Net_630;
          wire [0:0] Net_629;
          wire [0:0] Net_628;
          wire  Net_635;
          wire  Net_656;
          wire  Net_643;
          wire [0:0] Net_642;
          wire [0:0] Net_641;
          wire [0:0] Net_640;
          wire  Net_638;
          wire [0:0] Net_637;
          wire [0:0] Net_636;
          wire  Net_644;
          wire  Net_539;
          wire  Net_523;
          wire  Net_266;
          wire  Net_265;
          wire  Net_654;
          wire [0:0] Net_653;
          wire [0:0] Net_652;
          wire [0:0] Net_651;
          wire  Net_650;
          wire  Net_649;
          wire [0:0] Net_648;
          wire [0:0] Net_646;
          wire  Net_655;
          wire  Net_747;
          wire  Net_726;
          wire [0:0] Net_716;
          wire  Net_720;
          wire  Net_742;
          wire  Net_684;
          wire [0:0] Net_674;
          wire  Net_27;
          wire  Net_74;
          wire [0:0] Net_26;
          wire  Net_639;
          wire  Net_725;
          wire  Net_712;
          wire  Net_711;
          wire  Net_683;
          wire  Net_698;
          wire  Net_697;
          wire  Net_575;
          wire  Net_739;
          wire  Net_669;
          wire [0:0] Net_659;
          wire  Net_668;
          wire  Net_626;
          wire [0:0] Net_616;
          wire  Net_625;
          wire  Net_678;
          wire  Net_563;
          wire [0:0] Net_688;
          wire  Net_692;
          wire [0:0] Net_702;
          wire  Net_7;
          wire [0:0] Net_559;
          wire  Net_663;
          wire  Net_620;
          wire  Net_743;
          wire  Net_535;
          wire  Net_23;
          wire  Net_263;
          wire  Net_268;
          wire  Net_262;

	wire [0:0] tmpOE__I2S_SDI_three_net;
	wire [0:0] tmpIO_0__I2S_SDI_three_net;
	wire [0:0] tmpINTERRUPT_0__I2S_SDI_three_net;
	electrical [0:0] tmpSIOVREF__I2S_SDI_three_net;

	cy_psoc3_pins_v1_10
		#(.id("dff2777f-f70b-45c8-842a-e5b7b01e006a"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_SDI_three
		 (.oe(tmpOE__I2S_SDI_three_net),
		  .y({1'b0}),
		  .fb({Net_620}),
		  .io({tmpIO_0__I2S_SDI_three_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_SDI_three_net),
		  .interrupt({tmpINTERRUPT_0__I2S_SDI_three_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_SDI_three_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		DmaI2S_three
		 (.int_signal(Net_626));


	wire [0:0] tmpOE__I2S_three_ws_net;
	wire [0:0] tmpFB_0__I2S_three_ws_net;
	wire [0:0] tmpIO_0__I2S_three_ws_net;
	wire [0:0] tmpINTERRUPT_0__I2S_three_ws_net;
	electrical [0:0] tmpSIOVREF__I2S_three_ws_net;

	cy_psoc3_pins_v1_10
		#(.id("e31cfed1-cd9e-4edf-94c6-8a910c18788c"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("SCK"),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_three_ws
		 (.oe(tmpOE__I2S_three_ws_net),
		  .y({Net_625}),
		  .fb({tmpFB_0__I2S_three_ws_net[0:0]}),
		  .io({tmpIO_0__I2S_three_ws_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_three_ws_net),
		  .interrupt({tmpINTERRUPT_0__I2S_three_ws_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_three_ws_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_dma_v1_0
		#(.drq_type(2'b10))
		I2S_DMA_three
		 (.drq(Net_616[0:0]),
		  .nrq(Net_626),
		  .trq(1'b0));


	wire [0:0] tmpOE__cs_net;
	wire [0:0] tmpFB_0__cs_net;
	wire [0:0] tmpIO_0__cs_net;
	wire [0:0] tmpINTERRUPT_0__cs_net;
	electrical [0:0] tmpSIOVREF__cs_net;

	cy_psoc3_pins_v1_10
		#(.id("c9dfadb1-3745-4d35-a111-644d68e6e801"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		cs
		 (.oe(tmpOE__cs_net),
		  .y({Net_268}),
		  .fb({tmpFB_0__cs_net[0:0]}),
		  .io({tmpIO_0__cs_net[0:0]}),
		  .siovref(tmpSIOVREF__cs_net),
		  .interrupt({tmpINTERRUPT_0__cs_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__cs_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    I2S_v2_70_0 I2Sthree (
        .clip(Net_646[0:0]),
        .clock(Net_743),
        .rx_dma0(Net_616[0:0]),
        .rx_dma1(Net_648[0:0]),
        .rx_interrupt(Net_649),
        .sck(Net_650),
        .sdi(Net_620),
        .sdo(Net_651[0:0]),
        .tx_dma0(Net_652[0:0]),
        .tx_dma1(Net_653[0:0]),
        .tx_interrupt(Net_654),
        .ws(Net_625));

	wire [0:0] tmpOE__MOSI_1_net;
	wire [0:0] tmpFB_0__MOSI_1_net;
	wire [0:0] tmpIO_0__MOSI_1_net;
	wire [0:0] tmpINTERRUPT_0__MOSI_1_net;
	electrical [0:0] tmpSIOVREF__MOSI_1_net;

	cy_psoc3_pins_v1_10
		#(.id("ed092b9b-d398-4703-be89-cebf998501f6"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		MOSI_1
		 (.oe(tmpOE__MOSI_1_net),
		  .y({Net_23}),
		  .fb({tmpFB_0__MOSI_1_net[0:0]}),
		  .io({tmpIO_0__MOSI_1_net[0:0]}),
		  .siovref(tmpSIOVREF__MOSI_1_net),
		  .interrupt({tmpINTERRUPT_0__MOSI_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MOSI_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__MISO_1_net;
	wire [0:0] tmpIO_0__MISO_1_net;
	wire [0:0] tmpINTERRUPT_0__MISO_1_net;
	electrical [0:0] tmpSIOVREF__MISO_1_net;

	cy_psoc3_pins_v1_10
		#(.id("1449133b-4c77-4d7a-8df0-b1dbbb870e4e"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		MISO_1
		 (.oe(tmpOE__MISO_1_net),
		  .y({1'b0}),
		  .fb({Net_262}),
		  .io({tmpIO_0__MISO_1_net[0:0]}),
		  .siovref(tmpSIOVREF__MISO_1_net),
		  .interrupt({tmpINTERRUPT_0__MISO_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MISO_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SCLK_1_net;
	wire [0:0] tmpFB_0__SCLK_1_net;
	wire [0:0] tmpIO_0__SCLK_1_net;
	wire [0:0] tmpINTERRUPT_0__SCLK_1_net;
	electrical [0:0] tmpSIOVREF__SCLK_1_net;

	cy_psoc3_pins_v1_10
		#(.id("83b2fde2-60ad-45b6-9e5c-cb3baa6e3f9a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SCLK_1
		 (.oe(tmpOE__SCLK_1_net),
		  .y({Net_263}),
		  .fb({tmpFB_0__SCLK_1_net[0:0]}),
		  .io({tmpIO_0__SCLK_1_net[0:0]}),
		  .siovref(tmpSIOVREF__SCLK_1_net),
		  .interrupt({tmpINTERRUPT_0__SCLK_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SCLK_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    SPI_Master_v2_50_1 SPIM (
        .clock(Net_535),
        .miso(Net_262),
        .mosi(Net_23),
        .reset(1'b0),
        .rx_interrupt(Net_266),
        .sclk(Net_263),
        .sdat(Net_523),
        .ss(Net_268),
        .tx_interrupt(Net_747));
    defparam SPIM.BidirectMode = 0;
    defparam SPIM.HighSpeedMode = 1;
    defparam SPIM.NumberOfDataBits = 8;
    defparam SPIM.ShiftDir = 0;


	cy_clock_v1_0
		#(.id("14a7d33b-114a-4ae7-af00-523846f53f1c"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(0),
		  .period("62500000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_3
		 (.clock_out(Net_535));



	cy_dma_v1_0
		#(.drq_type(2'b10))
		I2S_DMA_one
		 (.drq(Net_559[0:0]),
		  .nrq(Net_575),
		  .trq(1'b0));


	wire [0:0] tmpOE__I2S_two_ws_net;
	wire [0:0] tmpFB_0__I2S_two_ws_net;
	wire [0:0] tmpIO_0__I2S_two_ws_net;
	wire [0:0] tmpINTERRUPT_0__I2S_two_ws_net;
	electrical [0:0] tmpSIOVREF__I2S_two_ws_net;

	cy_psoc3_pins_v1_10
		#(.id("ae5a546c-8c7d-4b97-8760-01809a895766"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("SCK"),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_two_ws
		 (.oe(tmpOE__I2S_two_ws_net),
		  .y({Net_74}),
		  .fb({tmpFB_0__I2S_two_ws_net[0:0]}),
		  .io({tmpIO_0__I2S_two_ws_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_two_ws_net),
		  .interrupt({tmpINTERRUPT_0__I2S_two_ws_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_two_ws_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__I2S_SDI_one_net;
	wire [0:0] tmpIO_0__I2S_SDI_one_net;
	wire [0:0] tmpINTERRUPT_0__I2S_SDI_one_net;
	electrical [0:0] tmpSIOVREF__I2S_SDI_one_net;

	cy_psoc3_pins_v1_10
		#(.id("42f2adb9-d50a-424b-9642-35c0f04307a5"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_SDI_one
		 (.oe(tmpOE__I2S_SDI_one_net),
		  .y({1'b0}),
		  .fb({Net_563}),
		  .io({tmpIO_0__I2S_SDI_one_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_SDI_one_net),
		  .interrupt({tmpINTERRUPT_0__I2S_SDI_one_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_SDI_one_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    I2S_v2_70_2 I2Sone (
        .clip(Net_636[0:0]),
        .clock(Net_743),
        .rx_dma0(Net_559[0:0]),
        .rx_dma1(Net_637[0:0]),
        .rx_interrupt(Net_638),
        .sck(Net_639),
        .sdi(Net_563),
        .sdo(Net_640[0:0]),
        .tx_dma0(Net_641[0:0]),
        .tx_dma1(Net_642[0:0]),
        .tx_interrupt(Net_643),
        .ws(Net_739));


	cy_isr_v1_0
		#(.int_type(2'b10))
		DmaI2S_one
		 (.int_signal(Net_575));



	cy_clock_v1_0
		#(.id("6bdb3b93-50cf-4737-bfeb-6bbfc96aeee4"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("162760416.666667"),
		  .is_direct(0),
		  .is_digital(1))
		I2S_Clock
		 (.clock_out(Net_743));



	cy_isr_v1_0
		#(.int_type(2'b10))
		DmaI2S_two
		 (.int_signal(Net_27));


	wire [1:0] tmpOE__I2S_one_net;
	wire [1:0] tmpFB_1__I2S_one_net;
	wire [1:0] tmpIO_1__I2S_one_net;
	wire [0:0] tmpINTERRUPT_0__I2S_one_net;
	electrical [0:0] tmpSIOVREF__I2S_one_net;

	cy_psoc3_pins_v1_10
		#(.id("c8e19693-67d9-4f29-a02f-cee5400c223a"),
		  .drive_mode(6'b110_110),
		  .ibuf_enabled(2'b1_1),
		  .init_dr_st(2'b1_1),
		  .input_clk_en(0),
		  .input_sync(2'b1_1),
		  .input_sync_mode(2'b0_0),
		  .intr_mode(4'b00_00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(","),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(2'b0_0),
		  .oe_reset(0),
		  .oe_sync(2'b0_0),
		  .output_clk_en(0),
		  .output_clock_mode(2'b0_0),
		  .output_conn(2'b1_1),
		  .output_mode(2'b0_0),
		  .output_reset(0),
		  .output_sync(2'b0_0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("SCK,WS"),
		  .pin_mode("OO"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(2'b1_1),
		  .sio_ibuf(""),
		  .sio_info(4'b00_00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(2'b0_0),
		  .spanning(0),
		  .use_annotation(2'b0_0),
		  .vtrip(4'b10_10),
		  .width(2),
		  .ovt_hyst_trim(2'b0_0),
		  .ovt_needed(2'b0_0),
		  .ovt_slew_control(4'b00_00),
		  .input_buffer_sel(4'b00_00))
		I2S_one
		 (.oe(tmpOE__I2S_one_net),
		  .y({Net_739, Net_639}),
		  .fb({tmpFB_1__I2S_one_net[1:0]}),
		  .io({tmpIO_1__I2S_one_net[1:0]}),
		  .siovref(tmpSIOVREF__I2S_one_net),
		  .interrupt({tmpINTERRUPT_0__I2S_one_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_one_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{2'b11} : {2'b11};


	cy_dma_v1_0
		#(.drq_type(2'b10))
		I2S_DMA_two
		 (.drq(Net_26[0:0]),
		  .nrq(Net_27),
		  .trq(1'b0));


	wire [0:0] tmpOE__I2S_SDI_two_net;
	wire [0:0] tmpIO_0__I2S_SDI_two_net;
	wire [0:0] tmpINTERRUPT_0__I2S_SDI_two_net;
	electrical [0:0] tmpSIOVREF__I2S_SDI_two_net;

	cy_psoc3_pins_v1_10
		#(.id("1425177d-0d0e-4468-8bcc-e638e5509a9b"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_SDI_two
		 (.oe(tmpOE__I2S_SDI_two_net),
		  .y({1'b0}),
		  .fb({Net_7}),
		  .io({tmpIO_0__I2S_SDI_two_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_SDI_two_net),
		  .interrupt({tmpINTERRUPT_0__I2S_SDI_two_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_SDI_two_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    I2S_v2_70_3 I2Stwo (
        .clip(Net_628[0:0]),
        .clock(Net_743),
        .rx_dma0(Net_26[0:0]),
        .rx_dma1(Net_629[0:0]),
        .rx_interrupt(Net_630),
        .sck(Net_73),
        .sdi(Net_7),
        .sdo(Net_631[0:0]),
        .tx_dma0(Net_632[0:0]),
        .tx_dma1(Net_633[0:0]),
        .tx_interrupt(Net_634),
        .ws(Net_74));

    I2S_v2_70_4 I2Sfour (
        .clip(Net_657[0:0]),
        .clock(Net_743),
        .rx_dma0(Net_659[0:0]),
        .rx_dma1(Net_660[0:0]),
        .rx_interrupt(Net_661),
        .sck(Net_662),
        .sdi(Net_663),
        .sdo(Net_664[0:0]),
        .tx_dma0(Net_665[0:0]),
        .tx_dma1(Net_666[0:0]),
        .tx_interrupt(Net_667),
        .ws(Net_668));


	cy_dma_v1_0
		#(.drq_type(2'b10))
		I2S_DMA_four
		 (.drq(Net_659[0:0]),
		  .nrq(Net_669),
		  .trq(1'b0));


	wire [0:0] tmpOE__I2S_four_ws_net;
	wire [0:0] tmpFB_0__I2S_four_ws_net;
	wire [0:0] tmpIO_0__I2S_four_ws_net;
	wire [0:0] tmpINTERRUPT_0__I2S_four_ws_net;
	electrical [0:0] tmpSIOVREF__I2S_four_ws_net;

	cy_psoc3_pins_v1_10
		#(.id("9676033d-f291-4956-b324-1e7555bb09da"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("SCK"),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_four_ws
		 (.oe(tmpOE__I2S_four_ws_net),
		  .y({Net_668}),
		  .fb({tmpFB_0__I2S_four_ws_net[0:0]}),
		  .io({tmpIO_0__I2S_four_ws_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_four_ws_net),
		  .interrupt({tmpINTERRUPT_0__I2S_four_ws_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_four_ws_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		DmaI2S_four
		 (.int_signal(Net_669));


	wire [0:0] tmpOE__I2S_SDI_four_net;
	wire [0:0] tmpIO_0__I2S_SDI_four_net;
	wire [0:0] tmpINTERRUPT_0__I2S_SDI_four_net;
	electrical [0:0] tmpSIOVREF__I2S_SDI_four_net;

	cy_psoc3_pins_v1_10
		#(.id("bcc9fdb1-6b82-439b-869e-f565d2571f8f"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_SDI_four
		 (.oe(tmpOE__I2S_SDI_four_net),
		  .y({1'b0}),
		  .fb({Net_663}),
		  .io({tmpIO_0__I2S_SDI_four_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_SDI_four_net),
		  .interrupt({tmpINTERRUPT_0__I2S_SDI_four_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_SDI_four_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    I2S_v2_70_5 I2Ssix (
        .clip(Net_672[0:0]),
        .clock(Net_743),
        .rx_dma0(Net_674[0:0]),
        .rx_dma1(Net_675[0:0]),
        .rx_interrupt(Net_676),
        .sck(Net_677),
        .sdi(Net_678),
        .sdo(Net_679[0:0]),
        .tx_dma0(Net_680[0:0]),
        .tx_dma1(Net_681[0:0]),
        .tx_interrupt(Net_682),
        .ws(Net_683));

	wire [0:0] tmpOE__I2S_SDI_six_net;
	wire [0:0] tmpIO_0__I2S_SDI_six_net;
	wire [0:0] tmpINTERRUPT_0__I2S_SDI_six_net;
	electrical [0:0] tmpSIOVREF__I2S_SDI_six_net;

	cy_psoc3_pins_v1_10
		#(.id("a123c721-44b4-46fa-a966-afc23b66322d"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_SDI_six
		 (.oe(tmpOE__I2S_SDI_six_net),
		  .y({1'b0}),
		  .fb({Net_678}),
		  .io({tmpIO_0__I2S_SDI_six_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_SDI_six_net),
		  .interrupt({tmpINTERRUPT_0__I2S_SDI_six_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_SDI_six_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_dma_v1_0
		#(.drq_type(2'b10))
		I2S_DMA_six
		 (.drq(Net_674[0:0]),
		  .nrq(Net_684),
		  .trq(1'b0));


	wire [0:0] tmpOE__I2S_six_ws_net;
	wire [0:0] tmpFB_0__I2S_six_ws_net;
	wire [0:0] tmpIO_0__I2S_six_ws_net;
	wire [0:0] tmpINTERRUPT_0__I2S_six_ws_net;
	electrical [0:0] tmpSIOVREF__I2S_six_ws_net;

	cy_psoc3_pins_v1_10
		#(.id("33a8c524-ff44-47f3-a961-44ba9e6b55f9"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("SCK"),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_six_ws
		 (.oe(tmpOE__I2S_six_ws_net),
		  .y({Net_683}),
		  .fb({tmpFB_0__I2S_six_ws_net[0:0]}),
		  .io({tmpIO_0__I2S_six_ws_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_six_ws_net),
		  .interrupt({tmpINTERRUPT_0__I2S_six_ws_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_six_ws_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		DmaI2S_six
		 (.int_signal(Net_684));


    I2S_v2_70_6 I2Sfive (
        .clip(Net_686[0:0]),
        .clock(Net_743),
        .rx_dma0(Net_688[0:0]),
        .rx_dma1(Net_689[0:0]),
        .rx_interrupt(Net_690),
        .sck(Net_691),
        .sdi(Net_692),
        .sdo(Net_693[0:0]),
        .tx_dma0(Net_694[0:0]),
        .tx_dma1(Net_695[0:0]),
        .tx_interrupt(Net_696),
        .ws(Net_697));


	cy_dma_v1_0
		#(.drq_type(2'b10))
		I2S_DMA_five
		 (.drq(Net_688[0:0]),
		  .nrq(Net_698),
		  .trq(1'b0));


	wire [0:0] tmpOE__I2S_five_ws_net;
	wire [0:0] tmpFB_0__I2S_five_ws_net;
	wire [0:0] tmpIO_0__I2S_five_ws_net;
	wire [0:0] tmpINTERRUPT_0__I2S_five_ws_net;
	electrical [0:0] tmpSIOVREF__I2S_five_ws_net;

	cy_psoc3_pins_v1_10
		#(.id("2e8ddec0-af05-49d6-82ff-62ffbd1da6f4"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("SCK"),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_five_ws
		 (.oe(tmpOE__I2S_five_ws_net),
		  .y({Net_697}),
		  .fb({tmpFB_0__I2S_five_ws_net[0:0]}),
		  .io({tmpIO_0__I2S_five_ws_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_five_ws_net),
		  .interrupt({tmpINTERRUPT_0__I2S_five_ws_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_five_ws_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		DmaI2S_five
		 (.int_signal(Net_698));


    I2S_v2_70_7 I2Sseven (
        .clip(Net_700[0:0]),
        .clock(Net_743),
        .rx_dma0(Net_702[0:0]),
        .rx_dma1(Net_703[0:0]),
        .rx_interrupt(Net_704),
        .sck(Net_705),
        .sdi(Net_742),
        .sdo(Net_707[0:0]),
        .tx_dma0(Net_708[0:0]),
        .tx_dma1(Net_709[0:0]),
        .tx_interrupt(Net_710),
        .ws(Net_711));


	cy_dma_v1_0
		#(.drq_type(2'b10))
		I2S_DMA_seven
		 (.drq(Net_702[0:0]),
		  .nrq(Net_712),
		  .trq(1'b0));


	wire [0:0] tmpOE__I2S_seven_ws_net;
	wire [0:0] tmpFB_0__I2S_seven_ws_net;
	wire [0:0] tmpIO_0__I2S_seven_ws_net;
	wire [0:0] tmpINTERRUPT_0__I2S_seven_ws_net;
	electrical [0:0] tmpSIOVREF__I2S_seven_ws_net;

	cy_psoc3_pins_v1_10
		#(.id("e0aa78e9-dbf5-43bc-9f70-687b69edca90"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("SCK"),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_seven_ws
		 (.oe(tmpOE__I2S_seven_ws_net),
		  .y({Net_711}),
		  .fb({tmpFB_0__I2S_seven_ws_net[0:0]}),
		  .io({tmpIO_0__I2S_seven_ws_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_seven_ws_net),
		  .interrupt({tmpINTERRUPT_0__I2S_seven_ws_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_seven_ws_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		DmaI2S_seven
		 (.int_signal(Net_712));


    I2S_v2_70_8 I2Seight (
        .clip(Net_714[0:0]),
        .clock(Net_743),
        .rx_dma0(Net_716[0:0]),
        .rx_dma1(Net_717[0:0]),
        .rx_interrupt(Net_718),
        .sck(Net_719),
        .sdi(Net_720),
        .sdo(Net_721[0:0]),
        .tx_dma0(Net_722[0:0]),
        .tx_dma1(Net_723[0:0]),
        .tx_interrupt(Net_724),
        .ws(Net_725));


	cy_dma_v1_0
		#(.drq_type(2'b10))
		I2S_DMA_eight
		 (.drq(Net_716[0:0]),
		  .nrq(Net_726),
		  .trq(1'b0));


	wire [0:0] tmpOE__I2S_eight_ws_net;
	wire [0:0] tmpFB_0__I2S_eight_ws_net;
	wire [0:0] tmpIO_0__I2S_eight_ws_net;
	wire [0:0] tmpINTERRUPT_0__I2S_eight_ws_net;
	electrical [0:0] tmpSIOVREF__I2S_eight_ws_net;

	cy_psoc3_pins_v1_10
		#(.id("94882658-57f3-436e-8612-e3be6245144e"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("SCK"),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_eight_ws
		 (.oe(tmpOE__I2S_eight_ws_net),
		  .y({Net_725}),
		  .fb({tmpFB_0__I2S_eight_ws_net[0:0]}),
		  .io({tmpIO_0__I2S_eight_ws_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_eight_ws_net),
		  .interrupt({tmpINTERRUPT_0__I2S_eight_ws_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_eight_ws_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b10))
		DmaI2S_eight
		 (.int_signal(Net_726));


	wire [0:0] tmpOE__I2S_SDI_five_net;
	wire [0:0] tmpIO_0__I2S_SDI_five_net;
	wire [0:0] tmpINTERRUPT_0__I2S_SDI_five_net;
	electrical [0:0] tmpSIOVREF__I2S_SDI_five_net;

	cy_psoc3_pins_v1_10
		#(.id("b67fce7b-30f7-414e-b6bf-286666ba08d7"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_SDI_five
		 (.oe(tmpOE__I2S_SDI_five_net),
		  .y({1'b0}),
		  .fb({Net_692}),
		  .io({tmpIO_0__I2S_SDI_five_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_SDI_five_net),
		  .interrupt({tmpINTERRUPT_0__I2S_SDI_five_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_SDI_five_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__I2S_SDI_seven_net;
	wire [0:0] tmpIO_0__I2S_SDI_seven_net;
	wire [0:0] tmpINTERRUPT_0__I2S_SDI_seven_net;
	electrical [0:0] tmpSIOVREF__I2S_SDI_seven_net;

	cy_psoc3_pins_v1_10
		#(.id("51953730-74a4-4766-a8b6-97d18ec9d7d8"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_SDI_seven
		 (.oe(tmpOE__I2S_SDI_seven_net),
		  .y({1'b0}),
		  .fb({Net_742}),
		  .io({tmpIO_0__I2S_SDI_seven_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_SDI_seven_net),
		  .interrupt({tmpINTERRUPT_0__I2S_SDI_seven_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_SDI_seven_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__I2S_SDI_eight_net;
	wire [0:0] tmpIO_0__I2S_SDI_eight_net;
	wire [0:0] tmpINTERRUPT_0__I2S_SDI_eight_net;
	electrical [0:0] tmpSIOVREF__I2S_SDI_eight_net;

	cy_psoc3_pins_v1_10
		#(.id("60032d31-c774-4ae0-88ec-d8f0867a6cfa"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I2S_SDI_eight
		 (.oe(tmpOE__I2S_SDI_eight_net),
		  .y({1'b0}),
		  .fb({Net_720}),
		  .io({tmpIO_0__I2S_SDI_eight_net[0:0]}),
		  .siovref(tmpSIOVREF__I2S_SDI_eight_net),
		  .interrupt({tmpINTERRUPT_0__I2S_SDI_eight_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I2S_SDI_eight_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_dma_v1_0
		#(.drq_type(2'b10))
		DMA_TX
		 (.drq(Net_747),
		  .nrq(Net_749),
		  .trq(1'b0));




endmodule

