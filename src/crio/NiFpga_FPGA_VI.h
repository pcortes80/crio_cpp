/*
 * Generated with the FPGA Interface C API Generator 18.0.0
 * for NI-RIO 18.0.0 or later.
 */

#ifndef __NiFpga_FPGA_VI_h__
#define __NiFpga_FPGA_VI_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1800
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_FPGA_VI_Bitfile;
 */
#define NiFpga_FPGA_VI_Bitfile "NiFpga_FPGA_VI.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_FPGA_VI_Signature = "079F0E6D7579DDE40D9F6C7C99D67270";

typedef enum
{
   NiFpga_FPGA_VI_IndicatorBool_UserSwitch0 = 0x18006,
   NiFpga_FPGA_VI_IndicatorBool_UserSwitch1 = 0x1800A,
   NiFpga_FPGA_VI_IndicatorBool_UserSwitch2 = 0x18022,
   NiFpga_FPGA_VI_IndicatorBool_UserSwitch3 = 0x18026,
} NiFpga_FPGA_VI_IndicatorBool;

typedef enum
{
   NiFpga_FPGA_VI_IndicatorU8_UserSwitch30 = 0x1800E,
} NiFpga_FPGA_VI_IndicatorU8;

typedef enum
{
   NiFpga_FPGA_VI_ControlBool_UserLED0 = 0x18012,
   NiFpga_FPGA_VI_ControlBool_UserLED1 = 0x18016,
   NiFpga_FPGA_VI_ControlBool_UserLED2 = 0x1801A,
   NiFpga_FPGA_VI_ControlBool_UserLED3 = 0x1801E,
} NiFpga_FPGA_VI_ControlBool;

typedef enum
{
   NiFpga_FPGA_VI_ControlU32_WaitmSec = 0x18000,
} NiFpga_FPGA_VI_ControlU32;

typedef enum
{
   NiFpga_FPGA_VI_IndicatorArrayBool_UserSwitch30_array = 0x1802A,
} NiFpga_FPGA_VI_IndicatorArrayBool;

typedef enum
{
   NiFpga_FPGA_VI_IndicatorArrayBoolSize_UserSwitch30_array = 8,
} NiFpga_FPGA_VI_IndicatorArrayBoolSize;

typedef enum
{
   NiFpga_FPGA_VI_TargetToHostFifoBool_SW0_FIFO = 2,
   NiFpga_FPGA_VI_TargetToHostFifoBool_SW1_FIFO = 1,
} NiFpga_FPGA_VI_TargetToHostFifoBool;

typedef enum
{
   NiFpga_FPGA_VI_TargetToHostFifoU8_U8_FIFO = 0,
} NiFpga_FPGA_VI_TargetToHostFifoU8;

#endif
