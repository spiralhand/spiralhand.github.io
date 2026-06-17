//////////////////////////////////////////////////////////////////////////
//               Bsp_Usart.h
// 描述:        串口驱动程序
//
// 履历:      
// -------------------------------
// 【1】创建模块              zx                  2026年01月14日
#ifndef __HH_BSP_USART_H_HH__
#define __HH_BSP_USART_H_HH__

#ifdef BSP_USART
#define BSP_USART_EX
#else
#define BSP_USART_EX extern
#endif
#include "include.h"

#define RX_LENGTH          (100)
#define CMD_BUFFER_LEN     (200)

#define USART1_BAUD        (9600)


typedef struct
{      
      uint8_t u8RxBuf[RX_LENGTH];
      uint8_t u8FinishFlag;
      uint8_t u8Count;
}tUsart;
BSP_USART_EX tUsart gtUsart1;

void BspUsart1Init(uint32_t u32Baud);

void UsartSendData(USART_TypeDef *USARTx,uint8_t u8Data);
void UsartSendBuf(USART_TypeDef *USARTx,uint8_t *u8pBuf,uint16_t u16Len);
void USART1_printf (char *fmt, ...);
#endif



