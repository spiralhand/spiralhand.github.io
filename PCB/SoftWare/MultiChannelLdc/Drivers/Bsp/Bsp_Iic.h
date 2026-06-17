//////////////////////////////////////////////////////////////////////////
//               Bsp_Iic.c
// 描述:        Iic驱动程序
//
// 履历:      
// -------------------------------
// 【1】创建模块              zx               2026年01月15日
// -------------------------------
#ifndef __HH_BSP_IIC_H_HH__
#define __HH_BSP_IIC_H_HH__

#ifdef BSP_IIC
#define BSP_IIC_EX
#else
#define BSP_IIC_EX extern
#endif
#include "include.h"

/***************************************
 * HOST_DEVICE_LDC1612,HOST_DEVICE_LDC1312
 * HOST_DEVICE_LDC1614,HOST_DEVICE_LDC1314
 ***************************************/
 
#define HOST_DEVICE_LDC1614    //选择芯片型号



/*引脚宏定义*/
/*LDC16XX_1*/
#define SET_I2C_SCL_1               (LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_9))
#define CLR_I2C_SCL_1               (LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_9))

#define SET_I2C_SDA_OUT_1           (LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_8,LL_GPIO_MODE_OUTPUT))            
#define SET_I2C_SDA_IN_1            (LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_8,LL_GPIO_MODE_INPUT))

#define SET_I2C_SDA_1               (LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_8))
#define CLR_I2C_SDA_1               (LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_8))

#define GET_I2C_SDA_1               (LL_GPIO_ReadInputPort(GPIOB) & 0x0100)

/*LDC16XX_2*/
#define SET_I2C_SCL_2               (LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_7))
#define CLR_I2C_SCL_2               (LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_7))

#define SET_I2C_SDA_OUT_2           (LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_6,LL_GPIO_MODE_OUTPUT))            
#define SET_I2C_SDA_IN_2            (LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_6,LL_GPIO_MODE_INPUT))

#define SET_I2C_SDA_2               (LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_6))
#define CLR_I2C_SDA_2               (LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_6))

#define GET_I2C_SDA_2               (LL_GPIO_ReadInputPort(GPIOB) & 0x0040)

/*LDC16XX_3*/
#define SET_I2C_SCL_3               (LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_15))
#define CLR_I2C_SCL_3               (LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_15))

#define SET_I2C_SDA_OUT_3           (LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_14,LL_GPIO_MODE_OUTPUT))            
#define SET_I2C_SDA_IN_3            (LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_14,LL_GPIO_MODE_INPUT))

#define SET_I2C_SDA_3               (LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_14))
#define CLR_I2C_SDA_3               (LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_14))

#define GET_I2C_SDA_3               (LL_GPIO_ReadInputPort(GPIOB) & 0x4000)

/*LDC16XX_4*/
#define SET_I2C_SCL_4               (LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_13))
#define CLR_I2C_SCL_4               (LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_13))

#define SET_I2C_SDA_OUT_4           (LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_12,LL_GPIO_MODE_OUTPUT))            
#define SET_I2C_SDA_IN_4            (LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_12,LL_GPIO_MODE_INPUT))

#define SET_I2C_SDA_4               (LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_12))
#define CLR_I2C_SDA_4               (LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_12))

#define GET_I2C_SDA_4               (LL_GPIO_ReadInputPort(GPIOB) & 0x1000)

/*LDC16XX_5*/
#define SET_I2C_SCL_5               (LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_11))
#define CLR_I2C_SCL_5               (LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_11))

#define SET_I2C_SDA_OUT_5           (LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_10,LL_GPIO_MODE_OUTPUT))            
#define SET_I2C_SDA_IN_5            (LL_GPIO_SetPinMode(GPIOB,LL_GPIO_PIN_10,LL_GPIO_MODE_INPUT))

#define SET_I2C_SDA_5               (LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_10))
#define CLR_I2C_SDA_5               (LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_10))

#define GET_I2C_SDA_5               (LL_GPIO_ReadInputPort(GPIOB) & 0x0400)


void IIC_Init(void);
uint8_t smbus_writeWord(uint8_t SlaveAddress, uint8_t REG_Address,uint16_t data,uint8_t u8ID);
uint8_t smbus_readWord(uint8_t SlaveAddress, uint8_t REG_Address,uint16_t *Read,uint8_t u8ID);

#endif

