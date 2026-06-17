//////////////////////////////////////////////////////////////////////////
//               App_Ldc16xx.h
// 描述:        Ldc16xx驱动程序
//
// 履历:      
// -------------------------------
// 【1】创建模块              zx                 2026年01月15日
// -------------------------------
#ifndef __HH_APP_LDC16XX_H_HH__
#define __HH_APP_LDC16XX_H_HH__

#ifdef APP_LDC16XX
#define APP_LDC16XX_EX
#else
#define APP_LDC16XX_EX extern
#endif
#include "include.h"

typedef enum
{
    LDC16XX_1 = 1,
    LDC16XX_2,
    LDC16XX_3,
    LDC16XX_4,
    LDC16XX_5,
}tEnumLdc16xx;


// LDC 指令集
#define LDC13xx16xx_CMD_DATA_MSB_CH0	        0x00
#define LDC13xx16xx_CMD_DATA_LSB_CH0	        0x01
#define LDC13xx16xx_CMD_DATA_MSB_CH1	        0x02
#define LDC13xx16xx_CMD_DATA_LSB_CH1	        0x03
#define LDC13xx16xx_CMD_DATA_MSB_CH2	        0x04
#define LDC13xx16xx_CMD_DATA_LSB_CH2	        0x05
#define LDC13xx16xx_CMD_DATA_MSB_CH3	        0x06
#define LDC13xx16xx_CMD_DATA_LSB_CH3	        0x07
#define LDC13xx16xx_CMD_REF_COUNT_CH0	        0x08
#define LDC13xx16xx_CMD_REF_COUNT_CH1	        0x09
#define LDC13xx16xx_CMD_REF_COUNT_CH2	        0x0A
#define LDC13xx16xx_CMD_REF_COUNT_CH3	        0x0B
#define LDC13xx16xx_CMD_OFFSET_CH0	            0x0C
#define LDC13xx16xx_CMD_OFFSET_CH1	            0x0D
#define LDC13xx16xx_CMD_OFFSET_CH2	            0x0E
#define LDC13xx16xx_CMD_OFFSET_CH3	            0x0F
#define LDC13xx16xx_CMD_SETTLE_COUNT_CH0	    0x10
#define LDC13xx16xx_CMD_SETTLE_COUNT_CH1	    0x11
#define LDC13xx16xx_CMD_SETTLE_COUNT_CH2	    0x12
#define LDC13xx16xx_CMD_SETTLE_COUNT_CH3	    0x13
#define LDC13xx16xx_CMD_CLOCK_DIVIDERS_CH0 	    0x14
#define LDC13xx16xx_CMD_CLOCK_DIVIDERS_CH1 	    0x15
#define LDC13xx16xx_CMD_CLOCK_DIVIDERS_CH2 	    0x16
#define LDC13xx16xx_CMD_CLOCK_DIVIDERS_CH3 	    0x17
#define LDC13xx16xx_CMD_STATUS 	                0x18
#define LDC13xx16xx_CMD_ERROR_CONFIG 	        0x19
#define LDC13xx16xx_CMD_CONFIG 	                0x1A
#define LDC13xx16xx_CMD_MUX_CONFIG 	            0x1B
#define LDC13xx16xx_CMD_RESET_DEVICE 	        0x1C
#define LDC13xx16xx_CMD_SYSTEM_CLOCK_CONFIG	    0x1D
#define LDC13xx16xx_CMD_DRIVE_CURRENT_CH0	    0x1E
#define LDC13xx16xx_CMD_DRIVE_CURRENT_CH1 	    0x1F
#define LDC13xx16xx_CMD_DRIVE_CURRENT_CH2 	    0x20
#define LDC13xx16xx_CMD_DRIVE_CURRENT_CH3	    0x21
#define LDC13xx16xx_CMD_MANUFACTID	            0x7E
#define LDC13xx16xx_CMD_DEVID	                0x7F


/** @name - Defaults Settings - */
//@{
#define EVM_MIN_I2CADDR                         0x2A
#define EVM_MAX_I2CADDR                         0x2B
#define EVM_DEFAULT_I2CADDR EVM_MIN_I2CADDR
#define EVM_DEFAULTS_SIZE                       24 // 13 registers, 0x08 - 0x14
//@}

uint8_t LDC1614_init(uint8_t u8ID);
uint32_t LDC_get_channel_result(uint8_t channel,uint8_t u8ID);

#endif

