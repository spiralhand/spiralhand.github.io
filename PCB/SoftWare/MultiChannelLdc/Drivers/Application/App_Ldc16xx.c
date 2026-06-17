//////////////////////////////////////////////////////////////////////////
//               App_Ldc16xx.c
// 描述:        Ldc16xx驱动程序
//
// 履历:      
// -------------------------------
// 【1】创建模块              zx                 2026年01月15日
// -------------------------------
#define APP_LDC16XX
#include "App_Ldc16xx.h"
/*
Name:LDC1614_init(void)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:   2026年01月22日
*/
uint8_t LDC1614_init(uint8_t u8ID) 
{
    uint16_t DEVICE_ID;
    uint8_t default_addr;
    uint8_t retVal = 1; 
    IIC_Init();
    /*确定LDC地址*/
    default_addr = EVM_DEFAULT_I2CADDR;
    /*软件复位*/
    smbus_writeWord(default_addr,LDC13xx16xx_CMD_RESET_DEVICE,0x8000,u8ID);
    /*读取ID判断LDC是否正常*/
    LL_mDelay(10);
    smbus_readWord(default_addr,LDC13xx16xx_CMD_DEVID,&DEVICE_ID,u8ID);
    if(DEVICE_ID == 0x3055)
        {
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_REF_COUNT_CH0,0xFFFF,u8ID); // 4 clock periods
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_REF_COUNT_CH1,0xFFFF,u8ID);
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_REF_COUNT_CH2,0xFFFF,u8ID);
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_REF_COUNT_CH3,0xFFFF,u8ID);
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_OFFSET_CH0,0x0000,u8ID);    
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_OFFSET_CH1,0x0000,u8ID);
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_OFFSET_CH2,0x0000,u8ID);
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_OFFSET_CH3,0x0000,u8ID);
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_SETTLE_COUNT_CH0,0x0400,u8ID); // 1 clock period
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_SETTLE_COUNT_CH1,0x0400,u8ID);
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_SETTLE_COUNT_CH2,0x0400,u8ID);
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_SETTLE_COUNT_CH3,0x0400,u8ID);
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_CLOCK_DIVIDERS_CH0,0x0000,u8ID); // bypass dividers
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_CLOCK_DIVIDERS_CH1,0x0000,u8ID);
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_CLOCK_DIVIDERS_CH2,0x0000,u8ID);
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_CLOCK_DIVIDERS_CH3,0x0000,u8ID);
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_STATUS,0x0001,u8ID); // report only DRDYs to INT
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_CONFIG,0x0200,u8ID); // CLKIN pin


            #if defined(HOST_DEVICE_LDC1612) || defined (HOST_DEVICE_LDC1312)
                     retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_MUX_CONFIG,0x820F,u8ID);//MS, changed to seq ch0 n ch1 // ch0, ch1
            #elif defined(HOST_DEVICE_LDC1614) || defined (HOST_DEVICE_LDC1314)
                     retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_MUX_CONFIG,0xC20F,u8ID); // ch0, ch1,ch2,ch3-> Wipro for 4 ch
            #endif
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_SYSTEM_CLOCK_CONFIG,0x0200,u8ID); // default, divide by 2
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_DRIVE_CURRENT_CH0,0x0000,u8ID); //
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_DRIVE_CURRENT_CH1,0x0000,u8ID); //
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_DRIVE_CURRENT_CH2,0x0000,u8ID); //
            retVal &= smbus_writeWord(default_addr,LDC13xx16xx_CMD_DRIVE_CURRENT_CH3,0x0000,u8ID); //
            return 0;
    }
        return 1;
}
/*
Name:LDC_get_channel_result(uint8_t channel)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:   2026年01月22日
*/
uint32_t LDC_get_channel_result(uint8_t channel,uint8_t u8ID) 
{
    uint32_t result = 0;
    uint16_t default_addr = 0;
    static uint16_t u16Ldc16xxData[8];
    
    default_addr = EVM_DEFAULT_I2CADDR;
    switch(channel)
    {
        case 0:
        {
            smbus_readWord(default_addr,LDC13xx16xx_CMD_DATA_MSB_CH0,&u16Ldc16xxData[0],u8ID);
            smbus_readWord(default_addr,LDC13xx16xx_CMD_DATA_LSB_CH0,&u16Ldc16xxData[1],u8ID);
            result = u16Ldc16xxData[0]&0x0FFF;
            result = (result << 16) | u16Ldc16xxData[1];
            break;
        }
        case 1:
        {
            smbus_readWord(default_addr,LDC13xx16xx_CMD_DATA_MSB_CH1,&u16Ldc16xxData[2],u8ID);
            smbus_readWord(default_addr,LDC13xx16xx_CMD_DATA_LSB_CH1,&u16Ldc16xxData[3],u8ID);
            result = u16Ldc16xxData[2]&0x0FFF;
            result = (result << 16) | u16Ldc16xxData[3];
            break;
        }
        case 2:
        {
            smbus_readWord(default_addr,LDC13xx16xx_CMD_DATA_MSB_CH2,&u16Ldc16xxData[4],u8ID);
            smbus_readWord(default_addr,LDC13xx16xx_CMD_DATA_LSB_CH2,&u16Ldc16xxData[5],u8ID);
            result = u16Ldc16xxData[4]&0x0FFF;
            result = (result << 16) | u16Ldc16xxData[5];
            break;
        }
        case 3:
        {
            smbus_readWord(default_addr,LDC13xx16xx_CMD_DATA_MSB_CH3,&u16Ldc16xxData[6],u8ID);
            smbus_readWord(default_addr,LDC13xx16xx_CMD_DATA_LSB_CH3,&u16Ldc16xxData[7],u8ID);
            result = u16Ldc16xxData[6]&0x0FFF;
            result = (result << 16)| u16Ldc16xxData[7];
            break;
        }
        default:break;
    }
    result = result & 0x0FFFFFFF;
    return result;
}























