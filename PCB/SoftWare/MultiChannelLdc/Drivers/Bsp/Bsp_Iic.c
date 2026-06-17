//////////////////////////////////////////////////////////////////////////
//               Bsp_Iic.c
// 描述:        Iic驱动程序
//
// 履历:      
// -------------------------------
// 【1】创建模块              zx                 2026年01月15日
// -------------------------------
#define BSP_IIC
#include "Bsp_Iic.h"
volatile static uint8_t u8Ack = 0;         /*应答*/
/*
Name:I2C_delay()
----------------------
Des:   IIC延时函数
Ref:
Paras: 
Author:zx
Date:2026年01月22日
*/
void I2C_delay(void)
{
    uint16_t u16LoopData = 0;
    for(u16LoopData = 0; u16LoopData < 40; u16LoopData++);
}
/*
Name:IIC_Delay(void)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:2026年01月22日
*/
void IIC_Delay(void)
{
    I2C_delay();
}
/*
Name:IIC_Init(void)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:2026年01月22日
*/
void IIC_Init(void)
{     
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    
    /* GPIO Ports Clock Enable */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
    
    /*初始化SDA*/
    GPIO_InitStruct.Pin = LL_GPIO_PIN_6 | LL_GPIO_PIN_8 | LL_GPIO_PIN_10 | LL_GPIO_PIN_12 | LL_GPIO_PIN_14;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    /*初始化SCL*/
    GPIO_InitStruct.Pin = LL_GPIO_PIN_7 | LL_GPIO_PIN_9 | LL_GPIO_PIN_11 | LL_GPIO_PIN_13 | LL_GPIO_PIN_15;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    /*初始化LED灯*/
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
    GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    
    
}
/*
Name:IIC_Start(void)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:2026年01月22日
*/
void IIC_Start(uint8_t u8ID)
{
    if(u8ID == LDC16XX_1)
    {
        SET_I2C_SDA_OUT_1;     
        SET_I2C_SDA_1;            
        SET_I2C_SCL_1;
        IIC_Delay();
        CLR_I2C_SDA_1;
        IIC_Delay();
        CLR_I2C_SCL_1;
    }
    else if(u8ID == LDC16XX_2)
    {
        SET_I2C_SDA_OUT_2;     
        SET_I2C_SDA_2;            
        SET_I2C_SCL_2;
        IIC_Delay();
        CLR_I2C_SDA_2;
        IIC_Delay();
        CLR_I2C_SCL_2;
    }
    else if(u8ID == LDC16XX_3)
    {
        SET_I2C_SDA_OUT_3;     
        SET_I2C_SDA_3;            
        SET_I2C_SCL_3;
        IIC_Delay();
        CLR_I2C_SDA_3;
        IIC_Delay();
        CLR_I2C_SCL_3;
    }
    else if(u8ID == LDC16XX_4)
    {
        SET_I2C_SDA_OUT_4;     
        SET_I2C_SDA_4;            
        SET_I2C_SCL_4;
        IIC_Delay();
        CLR_I2C_SDA_4;
        IIC_Delay();
        CLR_I2C_SCL_4;
    }
    else if(u8ID == LDC16XX_5)
    {
        SET_I2C_SDA_OUT_5;     
        SET_I2C_SDA_5;            
        SET_I2C_SCL_5;
        IIC_Delay();
        CLR_I2C_SDA_5;
        IIC_Delay();
        CLR_I2C_SCL_5;
    }
}      
/*
Name:IIC_Stop(void)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:2026年01月22日
*/
void IIC_Stop(uint8_t u8ID)
{
    if(u8ID == LDC16XX_1)
    {
        SET_I2C_SDA_OUT_1;
        CLR_I2C_SCL_1;
        CLR_I2C_SDA_1;
        IIC_Delay();
        SET_I2C_SCL_1; 
        SET_I2C_SDA_1;
        IIC_Delay();
    }
    else if(u8ID == LDC16XX_2)
    {
        SET_I2C_SDA_OUT_2;
        CLR_I2C_SCL_2;
        CLR_I2C_SDA_2;
        IIC_Delay();
        SET_I2C_SCL_2; 
        SET_I2C_SDA_2;
        IIC_Delay();
    }
    else if(u8ID == LDC16XX_3)
    {
        SET_I2C_SDA_OUT_3;
        CLR_I2C_SCL_3;
        CLR_I2C_SDA_3;
        IIC_Delay();
        SET_I2C_SCL_3; 
        SET_I2C_SDA_3;
        IIC_Delay();
    }
    else if(u8ID == LDC16XX_4)
    {
        SET_I2C_SDA_OUT_4;
        CLR_I2C_SCL_4;
        CLR_I2C_SDA_4;
        IIC_Delay();
        SET_I2C_SCL_4; 
        SET_I2C_SDA_4;
        IIC_Delay();
    }
    else if(u8ID == LDC16XX_5)
    {
        SET_I2C_SDA_OUT_5;
        CLR_I2C_SCL_5;
        CLR_I2C_SDA_5;
        IIC_Delay();
        SET_I2C_SCL_5; 
        SET_I2C_SDA_5;
        IIC_Delay();
    }    
}
/*
Name:IIC_Stop(void)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:2026年01月22日
*/
uint8_t IIC_Wait_Ack(uint8_t u8ID)
{
    uint16_t ucErrTime=0;
    if(u8ID == LDC16XX_1)
    {
        SET_I2C_SDA_IN_1;      
        SET_I2C_SDA_1;IIC_Delay();       
        SET_I2C_SCL_1;IIC_Delay();     
        while(GET_I2C_SDA_1)
        {
            ucErrTime++;
            if(ucErrTime>10)
            {
                IIC_Stop(LDC16XX_1);
                return 1;
            }
        }
        CLR_I2C_SCL_1;
        return 0;
    }
    else if(u8ID == LDC16XX_2)
    {
        SET_I2C_SDA_IN_2;      
        SET_I2C_SDA_2;IIC_Delay();       
        SET_I2C_SCL_2;IIC_Delay();     
        while(GET_I2C_SDA_2)
        {
            ucErrTime++;
            if(ucErrTime>10)
            {
                IIC_Stop(LDC16XX_2);
                return 1;
            }
        }
        CLR_I2C_SCL_2;
        return 0;
    }
    else if(u8ID == LDC16XX_3)
    {
        SET_I2C_SDA_IN_3;      
        SET_I2C_SDA_3;IIC_Delay();       
        SET_I2C_SCL_3;IIC_Delay();     
        while(GET_I2C_SDA_3)
        {
            ucErrTime++;
            if(ucErrTime>10)
            {
                IIC_Stop(LDC16XX_3);
                return 1;
            }
        }
        CLR_I2C_SCL_3;
        return 0;
    }
    else if(u8ID == LDC16XX_4)
    {
        SET_I2C_SDA_IN_4;      
        SET_I2C_SDA_4;IIC_Delay();       
        SET_I2C_SCL_4;IIC_Delay();     
        while(GET_I2C_SDA_4)
        {
            ucErrTime++;
            if(ucErrTime>10)
            {
                IIC_Stop(LDC16XX_4);
                return 1;
            }
        }
        CLR_I2C_SCL_4;
        return 0;
    }
    else if(u8ID == LDC16XX_5)
    {
        SET_I2C_SDA_IN_5;      
        SET_I2C_SDA_5;IIC_Delay();       
        SET_I2C_SCL_5;IIC_Delay();     
        while(GET_I2C_SDA_5)
        {
            ucErrTime++;
            if(ucErrTime>10)
            {
                IIC_Stop(LDC16XX_5);
                return 1;
            }
        }
        CLR_I2C_SCL_5;
        return 0;
    }
    return 1;    
}
/*
Name:IIC_Ack(void)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:2026年01月22日
*/
void IIC_Ack(uint8_t u8ID)
{
    if(u8ID == LDC16XX_1)
    {
        CLR_I2C_SCL_1;
        SET_I2C_SDA_OUT_1;
        CLR_I2C_SDA_1;
        IIC_Delay();
        SET_I2C_SCL_1;
        IIC_Delay();
        CLR_I2C_SCL_1;
    }
    else if(u8ID == LDC16XX_2)
    {
        CLR_I2C_SCL_2;
        SET_I2C_SDA_OUT_2;
        CLR_I2C_SDA_2;
        IIC_Delay();
        SET_I2C_SCL_2;
        IIC_Delay();
        CLR_I2C_SCL_2;
    }
    else if(u8ID == LDC16XX_3)
    {
        CLR_I2C_SCL_3;
        SET_I2C_SDA_OUT_3;
        CLR_I2C_SDA_3;
        IIC_Delay();
        SET_I2C_SCL_3;
        IIC_Delay();
        CLR_I2C_SCL_3;
    }
    else if(u8ID == LDC16XX_4)
    {
        CLR_I2C_SCL_4;
        SET_I2C_SDA_OUT_4;
        CLR_I2C_SDA_4;
        IIC_Delay();
        SET_I2C_SCL_4;
        IIC_Delay();
        CLR_I2C_SCL_4;
    }
    else if(u8ID == LDC16XX_5)
    {
        CLR_I2C_SCL_5;
        SET_I2C_SDA_OUT_5;
        CLR_I2C_SDA_5;
        IIC_Delay();
        SET_I2C_SCL_5;
        IIC_Delay();
        CLR_I2C_SCL_5;
    }
}
/*
Name:IIC_NAck(void)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:2026年01月22日
*/    
void IIC_NAck(uint8_t u8ID)
{
    if(u8ID == LDC16XX_1)
    {
        CLR_I2C_SCL_1;
        SET_I2C_SDA_OUT_1;
        SET_I2C_SDA_1;
        IIC_Delay();
        SET_I2C_SCL_1;
        IIC_Delay();
        CLR_I2C_SCL_1;
    }
    else if(u8ID == LDC16XX_2)
    {
        CLR_I2C_SCL_2;
        SET_I2C_SDA_OUT_2;
        SET_I2C_SDA_2;
        IIC_Delay();
        SET_I2C_SCL_2;
        IIC_Delay();
        CLR_I2C_SCL_2;
    }
    else if(u8ID == LDC16XX_3)
    {
        CLR_I2C_SCL_3;
        SET_I2C_SDA_OUT_3;
        SET_I2C_SDA_3;
        IIC_Delay();
        SET_I2C_SCL_3;
        IIC_Delay();
        CLR_I2C_SCL_3;
    }
    else if(u8ID == LDC16XX_4)
    {
        CLR_I2C_SCL_4;
        SET_I2C_SDA_OUT_4;
        SET_I2C_SDA_4;
        IIC_Delay();
        SET_I2C_SCL_4;
        IIC_Delay();
        CLR_I2C_SCL_4;
    }
    else if(u8ID == LDC16XX_5)
    {
        CLR_I2C_SCL_5;
        SET_I2C_SDA_OUT_5;
        SET_I2C_SDA_5;
        IIC_Delay();
        SET_I2C_SCL_5;
        IIC_Delay();
        CLR_I2C_SCL_5;
    }
}                                          
/*
Name:IIC_Send_Byte(void)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:2026年01月22日
*/          
void IIC_Send_Byte(uint8_t txd,uint8_t u8ID)
{                        
    uint8_t u8LoopData;
    if(u8ID == LDC16XX_1)
    {    
        SET_I2C_SDA_OUT_1;         
        CLR_I2C_SCL_1;
        for(u8LoopData = 0;u8LoopData < 8;u8LoopData++)
        {        
            if((txd << u8LoopData) & 0x80)
            {
                SET_I2C_SDA_1;
            }
            else
            {
                CLR_I2C_SDA_1;
            }
            SET_I2C_SCL_1;
            IIC_Delay(); 
            CLR_I2C_SCL_1;    
            IIC_Delay();
        }
    }
    else if(u8ID == LDC16XX_2)
    {    
        SET_I2C_SDA_OUT_2;         
        CLR_I2C_SCL_2;
        for(u8LoopData = 0;u8LoopData < 8;u8LoopData++)
        {        
            if((txd << u8LoopData) & 0x80)
            {
                SET_I2C_SDA_2;
            }
            else
            {
                CLR_I2C_SDA_2;
            }
            SET_I2C_SCL_2;
            IIC_Delay(); 
            CLR_I2C_SCL_2;    
            IIC_Delay();
        }
    }
    else if(u8ID == LDC16XX_3)
    {    
        SET_I2C_SDA_OUT_3;         
        CLR_I2C_SCL_3;
        for(u8LoopData = 0;u8LoopData < 8;u8LoopData++)
        {        
            if((txd << u8LoopData) & 0x80)
            {
                SET_I2C_SDA_3;
            }
            else
            {
                CLR_I2C_SDA_3;
            }
            SET_I2C_SCL_3;
            IIC_Delay(); 
            CLR_I2C_SCL_3;    
            IIC_Delay();
        }
    }
    else if(u8ID == LDC16XX_4)
    {    
        SET_I2C_SDA_OUT_4;         
        CLR_I2C_SCL_4;
        for(u8LoopData = 0;u8LoopData < 8;u8LoopData++)
        {        
            if((txd << u8LoopData) & 0x80)
            {
                SET_I2C_SDA_4;
            }
            else
            {
                CLR_I2C_SDA_4;
            }
            SET_I2C_SCL_4;
            IIC_Delay(); 
            CLR_I2C_SCL_4;    
            IIC_Delay();
        }
    }
    else if(u8ID == LDC16XX_5)
    {    
        SET_I2C_SDA_OUT_5;         
        CLR_I2C_SCL_5;
        for(u8LoopData = 0;u8LoopData < 8;u8LoopData++)
        {        
            if((txd << u8LoopData) & 0x80)
            {
                SET_I2C_SDA_5;
            }
            else
            {
                CLR_I2C_SDA_5;
            }
            SET_I2C_SCL_5;
            IIC_Delay(); 
            CLR_I2C_SCL_5;    
            IIC_Delay();
        }
    }    
}         
/*
Name:IIC_Read_Byte(void)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:2026年01月22日
*/
uint8_t IIC_Read_Byte(uint8_t u8ack,uint8_t u8ID)
{
    uint8_t u8LoopData = 0;
    uint8_t u8Receive = 0;
    if(u8ID == LDC16XX_1)
    {
        SET_I2C_SDA_IN_1;
        for(u8LoopData = 0;u8LoopData < 8;u8LoopData++ )
        {
            CLR_I2C_SCL_1; 
            IIC_Delay();
            SET_I2C_SCL_1;
            u8Receive <<= 1;
            if(GET_I2C_SDA_1)
            {
                u8Receive++;    
            }
            IIC_Delay();        
        }                 
        if (!u8ack)
        {
            IIC_NAck(LDC16XX_1);
        }
        else
        {
            IIC_Ack(LDC16XX_1);
        }        
        return u8Receive;
    }
    else if(u8ID == LDC16XX_2)
    {
        SET_I2C_SDA_IN_2;
        for(u8LoopData = 0;u8LoopData < 8;u8LoopData++ )
        {
            CLR_I2C_SCL_2; 
            IIC_Delay();
            SET_I2C_SCL_2;
            u8Receive <<= 1;
            if(GET_I2C_SDA_2)
            {
                u8Receive++;    
            }
            IIC_Delay();        
        }                 
        if (!u8ack)
        {
            IIC_NAck(LDC16XX_2);
        }
        else
        {
            IIC_Ack(LDC16XX_2);
        }        
        return u8Receive;
    }
    else if(u8ID == LDC16XX_3)
    {
        SET_I2C_SDA_IN_3;
        for(u8LoopData = 0;u8LoopData < 8;u8LoopData++ )
        {
            CLR_I2C_SCL_3; 
            IIC_Delay();
            SET_I2C_SCL_3;
            u8Receive <<= 1;
            if(GET_I2C_SDA_3)
            {
                u8Receive++;    
            }
            IIC_Delay();        
        }                 
        if (!u8ack)
        {
            IIC_NAck(LDC16XX_3);
        }
        else
        {
            IIC_Ack(LDC16XX_3);
        }        
        return u8Receive;
    }
    else if(u8ID == LDC16XX_4)
    {
        SET_I2C_SDA_IN_4;
        for(u8LoopData = 0;u8LoopData < 8;u8LoopData++ )
        {
            CLR_I2C_SCL_4; 
            IIC_Delay();
            SET_I2C_SCL_4;
            u8Receive <<= 1;
            if(GET_I2C_SDA_4)
            {
                u8Receive++;    
            }
            IIC_Delay();        
        }                 
        if (!u8ack)
        {
            IIC_NAck(LDC16XX_4);
        }
        else
        {
            IIC_Ack(LDC16XX_4);
        }        
        return u8Receive;
    }
    else if(u8ID == LDC16XX_5)
    {
        SET_I2C_SDA_IN_5;
        for(u8LoopData = 0;u8LoopData < 8;u8LoopData++ )
        {
            CLR_I2C_SCL_5; 
            IIC_Delay();
            SET_I2C_SCL_5;
            u8Receive <<= 1;
            if(GET_I2C_SDA_5)
            {
                u8Receive++;    
            }
            IIC_Delay();        
        }                 
        if (!u8ack)
        {
            IIC_NAck(LDC16XX_5);
        }
        else
        {
            IIC_Ack(LDC16XX_5);
        }        
        return u8Receive;
    }
    return 1;
}
/*
Name:smbus_writeWord(void)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:2026年01月22日
*/
uint8_t smbus_writeWord(uint8_t SlaveAddress, uint8_t REG_Address,uint16_t data,uint8_t u8ID)
{
    static uint8_t buffer[2];
    buffer[0] = (data >> 8);
    buffer[1] = (uint8_t)(data & 0x00ff);
    if(u8ID == LDC16XX_1)
    {
        IIC_Start(LDC16XX_1);
        IIC_Send_Byte(SlaveAddress << 1,LDC16XX_1);
        if (IIC_Wait_Ack(LDC16XX_1) == 1)
        {
            return 0;
        }
        IIC_Send_Byte(REG_Address,LDC16XX_1);
        if (IIC_Wait_Ack(LDC16XX_1) == 1)
        {
            return 0;
        }
        IIC_Send_Byte(buffer[0],LDC16XX_1);
        if (IIC_Wait_Ack(LDC16XX_1) == 1)
        {
            return 0;
        }
        
        IIC_Send_Byte(buffer[1],LDC16XX_1);
        if (IIC_Wait_Ack(LDC16XX_1) == 1)
        {
            return 0;
        }
        IIC_Stop(LDC16XX_1);
        return 1;
    }
    else if(u8ID == LDC16XX_2)
    {
        IIC_Start(LDC16XX_2);
        IIC_Send_Byte(SlaveAddress << 1,LDC16XX_2);
        if (IIC_Wait_Ack(LDC16XX_2) == 1)
        {
            return 0;
        }
        IIC_Send_Byte(REG_Address,LDC16XX_2);
        if (IIC_Wait_Ack(LDC16XX_2) == 1)
        {
            return 0;
        }
        IIC_Send_Byte(buffer[0],LDC16XX_2);
        if (IIC_Wait_Ack(LDC16XX_2) == 1)
        {
            return 0;
        }
        
        IIC_Send_Byte(buffer[1],LDC16XX_2);
        if (IIC_Wait_Ack(LDC16XX_2) == 1)
        {
            return 0;
        }
        IIC_Stop(LDC16XX_2);
        return 1;
    }
    else if(u8ID == LDC16XX_3)
    {
        IIC_Start(LDC16XX_3);
        IIC_Send_Byte(SlaveAddress << 1,LDC16XX_3);
        if (IIC_Wait_Ack(LDC16XX_3) == 1)
        {
            return 0;
        }
        IIC_Send_Byte(REG_Address,LDC16XX_3);
        if (IIC_Wait_Ack(LDC16XX_3) == 1)
        {
            return 0;
        }
        IIC_Send_Byte(buffer[0],LDC16XX_3);
        if (IIC_Wait_Ack(LDC16XX_3) == 1)
        {
            return 0;
        }
        
        IIC_Send_Byte(buffer[1],LDC16XX_3);
        if (IIC_Wait_Ack(LDC16XX_3) == 1)
        {
            return 0;
        }
        IIC_Stop(LDC16XX_3);
        return 1;
    }
    else if(u8ID == LDC16XX_4)
    {
        IIC_Start(LDC16XX_4);
        IIC_Send_Byte(SlaveAddress << 1,LDC16XX_4);
        if (IIC_Wait_Ack(LDC16XX_4) == 1)
        {
            return 0;
        }
        IIC_Send_Byte(REG_Address,LDC16XX_4);
        if (IIC_Wait_Ack(LDC16XX_4) == 1)
        {
            return 0;
        }
        IIC_Send_Byte(buffer[0],LDC16XX_4);
        if (IIC_Wait_Ack(LDC16XX_4) == 1)
        {
            return 0;
        }
        
        IIC_Send_Byte(buffer[1],LDC16XX_4);
        if (IIC_Wait_Ack(LDC16XX_4) == 1)
        {
            return 0;
        }
        IIC_Stop(LDC16XX_4);
        return 1;
    }
    else if(u8ID == LDC16XX_5)
    {
        IIC_Start(LDC16XX_5);
        IIC_Send_Byte(SlaveAddress << 1,LDC16XX_5);
        if (IIC_Wait_Ack(LDC16XX_5) == 1)
        {
            return 0;
        }
        IIC_Send_Byte(REG_Address,LDC16XX_5);
        if (IIC_Wait_Ack(LDC16XX_5) == 1)
        {
            return 0;
        }
        IIC_Send_Byte(buffer[0],LDC16XX_5);
        if (IIC_Wait_Ack(LDC16XX_5) == 1)
        {
            return 0;
        }
        
        IIC_Send_Byte(buffer[1],LDC16XX_5);
        if (IIC_Wait_Ack(LDC16XX_5) == 1)
        {
            return 0;
        }
        IIC_Stop(LDC16XX_5);
        return 1;
    }
    return 1;
}
/*
Name:smbus_writeWord(void)
----------------------
Des:  
Ref:   
Paras: 
Author: zx
Date:2026年01月22日
*/
uint8_t smbus_readWord(uint8_t SlaveAddress, uint8_t REG_Address,uint16_t *Read,uint8_t u8ID)
{
    uint8_t Dat_L = 0;
    uint8_t Dat_H = 0;
    if(u8ID == LDC16XX_1)
    {
        IIC_Start(LDC16XX_1);
        IIC_Send_Byte(SlaveAddress << 1,LDC16XX_1);
        if (IIC_Wait_Ack(LDC16XX_1) == 1)
        {
            return 0;
        }
        
        
        IIC_Send_Byte(REG_Address,LDC16XX_1);
        if (IIC_Wait_Ack(LDC16XX_1) == 1)
        {
            return 0;
        }
        
        IIC_Start(LDC16XX_1);
        IIC_Send_Byte((SlaveAddress << 1) + 1,LDC16XX_1);
        if (IIC_Wait_Ack(LDC16XX_1) == 1)
        {
            return 0;
        }
        Dat_H = IIC_Read_Byte(1,LDC16XX_1);   //ack
        Dat_L = IIC_Read_Byte(0,LDC16XX_1);   //Nack
        IIC_Stop(LDC16XX_1);
        *Read = ((Dat_H << 8) | Dat_L);
        return 1;
    }
    else if(u8ID == LDC16XX_2)
    {
        IIC_Start(LDC16XX_2);
        IIC_Send_Byte(SlaveAddress << 1,LDC16XX_2);
        if (IIC_Wait_Ack(LDC16XX_2) == 1)
        {
            return 0;
        }
        
        
        IIC_Send_Byte(REG_Address,LDC16XX_2);
        if (IIC_Wait_Ack(LDC16XX_2) == 1)
        {
            return 0;
        }
        
        IIC_Start(LDC16XX_2);
        IIC_Send_Byte((SlaveAddress << 1) + 1,LDC16XX_2);
        if (IIC_Wait_Ack(LDC16XX_2) == 1)
        {
            return 0;
        }
        Dat_H = IIC_Read_Byte(1,LDC16XX_2);   //ack
        Dat_L = IIC_Read_Byte(0,LDC16XX_2);   //Nack
        IIC_Stop(LDC16XX_2);
        *Read = ((Dat_H << 8) | Dat_L);
        return 1;
    }
    else if(u8ID == LDC16XX_3)
    {
        IIC_Start(LDC16XX_3);
        IIC_Send_Byte(SlaveAddress << 1,LDC16XX_3);
        if (IIC_Wait_Ack(LDC16XX_3) == 1)
        {
            return 0;
        }
        
        
        IIC_Send_Byte(REG_Address,LDC16XX_3);
        if (IIC_Wait_Ack(LDC16XX_3) == 1)
        {
            return 0;
        }
        
        IIC_Start(LDC16XX_3);
        IIC_Send_Byte((SlaveAddress << 1) + 1,LDC16XX_3);
        if (IIC_Wait_Ack(LDC16XX_3) == 1)
        {
            return 0;
        }
        Dat_H = IIC_Read_Byte(1,LDC16XX_3);   //ack
        Dat_L = IIC_Read_Byte(0,LDC16XX_3);   //Nack
        IIC_Stop(LDC16XX_3);
        *Read = ((Dat_H << 8) | Dat_L);
        return 1;
    }
    else if(u8ID == LDC16XX_4)
    {
        IIC_Start(LDC16XX_4);
        IIC_Send_Byte(SlaveAddress << 1,LDC16XX_4);
        if (IIC_Wait_Ack(LDC16XX_4) == 1)
        {
            return 0;
        }
        
        
        IIC_Send_Byte(REG_Address,LDC16XX_4);
        if (IIC_Wait_Ack(LDC16XX_4) == 1)
        {
            return 0;
        }
        
        IIC_Start(LDC16XX_4);
        IIC_Send_Byte((SlaveAddress << 1) + 1,LDC16XX_4);
        if (IIC_Wait_Ack(LDC16XX_4) == 1)
        {
            return 0;
        }
        Dat_H = IIC_Read_Byte(1,LDC16XX_4);   //ack
        Dat_L = IIC_Read_Byte(0,LDC16XX_4);   //Nack
        IIC_Stop(LDC16XX_4);
        *Read = ((Dat_H << 8) | Dat_L);
        return 1;
    }
    else if(u8ID == LDC16XX_5)
    {
        IIC_Start(LDC16XX_5);
        IIC_Send_Byte(SlaveAddress << 1,LDC16XX_5);
        if (IIC_Wait_Ack(LDC16XX_5) == 1)
        {
            return 0;
        }
        
        
        IIC_Send_Byte(REG_Address,LDC16XX_5);
        if (IIC_Wait_Ack(LDC16XX_5) == 1)
        {
            return 0;
        }
        
        IIC_Start(LDC16XX_5);
        IIC_Send_Byte((SlaveAddress << 1) + 1,LDC16XX_5);
        if (IIC_Wait_Ack(LDC16XX_5) == 1)
        {
            return 0;
        }
        Dat_H = IIC_Read_Byte(1,LDC16XX_5);   //ack
        Dat_L = IIC_Read_Byte(0,LDC16XX_5);   //Nack
        IIC_Stop(LDC16XX_5);
        *Read = ((Dat_H << 8) | Dat_L);
        return 1;
    }
    return 1;
}















