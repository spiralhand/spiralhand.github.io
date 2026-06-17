//////////////////////////////////////////////////////////////////////////
//               bsp_usart.c
// 描述:        串口1驱动程序
//
// 履历:      
// -------------------------------
// 【1】创建模块              zx        ANCN          2024年03月29日
#define BSP_USART
#include "Bsp_Usart.h"
/*
Name:void BspUsart1Init()
----------------------
Des:  串口1初始化函数
Ref:
Paras: 
Author: zx
Date:2026年01月22日
*/
void BspUsart1Init(uint32_t u32Baud)
{
    
    LL_USART_InitTypeDef USART_InitStruct = {0};    
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1);    
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    /**USART1 GPIO Configuration
    PA9   ------> USART1_TX
    PA10   ------> USART1_RX
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_9;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = LL_GPIO_PIN_10;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  
    /*使能复用功能*/
    LL_GPIO_SetAFPin_8_15(GPIOA, LL_GPIO_PIN_9, LL_GPIO_AF_7);
    LL_GPIO_SetAFPin_8_15(GPIOA, LL_GPIO_PIN_10, LL_GPIO_AF_7);

    /* USER CODE END USART1_Init 1 */
    USART_InitStruct.BaudRate = u32Baud;
    USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
    USART_InitStruct.Parity = LL_USART_PARITY_NONE;
    USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
    LL_USART_Init(USART1, &USART_InitStruct);
    
    NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),2, 0));
    NVIC_EnableIRQ(USART1_IRQn);
        
    LL_USART_ConfigAsyncMode(USART1);
    LL_USART_EnableIT_RXNE(USART1);
    LL_USART_EnableIT_IDLE(USART1);
    LL_USART_Enable(USART1);
}
/*
Name:void UsartSendData(USART_TypeDef *USARTx,uint8_t u8Data)
----------------------
Des:  串口发送一个字节
Ref:
Paras: 
Author: zx
Date:   2026年01月22日
*/
void UsartSendData(USART_TypeDef *USARTx,uint8_t u8Data)
{          
    while(!LL_USART_IsActiveFlag_TXE(USARTx));
    LL_USART_TransmitData8(USARTx, u8Data);   
}
/*
void Usart_SendBuf(USART_TypeDef *USARTx,uint8_t *u8pBuf,uint16_t u16Len)
----------------------
Des:  串口发送一组数据
Ref:
Paras: 
Author:zx
Date:2026年01月22日
*/
void UsartSendBuf(USART_TypeDef *USARTx,uint8_t *u8pBuf,uint16_t u16Len)
{
    uint8_t u8LoopData = 0;
    for(u8LoopData = 0; u8LoopData < u16Len; u8LoopData++)   
    {
        UsartSendData(USARTx,u8pBuf[u8LoopData]);
    }
    while(!LL_USART_IsActiveFlag_TC(USARTx));
}

/*
Name:USART1_printf (char *fmt, ...)
----------------------
Des:  串口1重定向   
Ref:
Paras: 
Author: zx
Date:2026年01月22日
*/
int fputc(int ch, FILE *f)
{
    /*等待上一个字符发送完成*/
    while ((USART1 -> SR & 0X40) == 0);
    /*将要发送的字符 ch 写入到DR寄存器*/    
    USART1 -> DR = (uint8_t)ch;             
    return ch;
}

