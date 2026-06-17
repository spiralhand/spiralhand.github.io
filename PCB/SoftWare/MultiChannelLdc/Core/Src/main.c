/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "include.h"
uint32_t Channel_value[20];
// base_epoch is an OFFSET such that: epoch_seconds = base_epoch + (HAL_GetTick()/1000)
double base_epoch = 0.0;
uint8_t time_synced = 0;

// Sampling period (ms). Lower value -> higher data rate over UART.
// 50ms ~= 20Hz is safe for 115200 baud with 20 channels.
#ifndef SAMPLE_PERIOD_MS
#define SAMPLE_PERIOD_MS 50
#endif

extern volatile uint8_t g_usart1_rx_ready;
extern volatile uint16_t g_usart1_rx_len;
extern char g_usart1_rx_buf[128];

static uint8_t fetch_usart1_line(char *out, uint16_t out_sz)
{
    if (!g_usart1_rx_ready)
        return 0;

    // Copy-and-clear atomically (IRQ-safe)
    __disable_irq();
    uint16_t n = g_usart1_rx_len;
    if (n >= (out_sz - 1))
        n = (out_sz - 1);
    memcpy(out, g_usart1_rx_buf, n);
    out[n] = '\0';
    g_usart1_rx_len = 0;
    g_usart1_rx_ready = 0;
    __enable_irq();
    return 1;
}

static void handle_usart1_command(void)
{
    char line[128];
    if (!fetch_usart1_line(line, sizeof(line)))
        return;

    // Accept "PING" or "PING,..."
    if (strncmp(line, "PING", 4) == 0)
    {
        printf("PONG,%lu\r\n", (unsigned long)HAL_GetTick());
        return;
    }

    // Accept "SETBASE,<epoch_seconds>" where epoch_seconds is Unix epoch seconds (float)
    if (strncmp(line, "SETBASE", 7) == 0)
    {
        char *comma = strchr(line, ',');
        if (comma != NULL)
        {
            double epoch_now = atof(comma + 1);
            uint32_t tick = HAL_GetTick();
            // Convert absolute epoch to internal offset: base_epoch + tick/1000 = epoch_now
            base_epoch = epoch_now - ((double)tick) / 1000.0;
            time_synced = 1;
            printf("SYNCED,%.9f\r\n", base_epoch);
        }
        return;
    }
}

int main(void)
{
    HAL_Init();
    /*配置系统时钟*/
    BspSysClockInit();
    /*初始化串口*/
    BspUsart1Init(115200);
    /*初始化LDC芯片*/
    for(uint8_t u8LoopData = 1; u8LoopData < 6; u8LoopData++)
    {
        if(LDC1614_init(u8LoopData) == 0)
        {
            printf("LDC %d 初始化成功\r\n",u8LoopData);
        }
        else
        {
            printf("LDC %d 初始化失败\r\n",u8LoopData);
        }
        LL_mDelay(500);
    }
    while (1)
    {
        // Handle commands promptly (even if sensor read/print is slow)
        handle_usart1_command();

        /*读二十个通道值*/
        Channel_value[0] = LDC_get_channel_result(3,LDC16XX_1);
        Channel_value[1] = LDC_get_channel_result(2,LDC16XX_1);
        Channel_value[2] = LDC_get_channel_result(1,LDC16XX_1);
        Channel_value[3] = LDC_get_channel_result(0,LDC16XX_1);
        
        Channel_value[4] = LDC_get_channel_result(3,LDC16XX_2);
        Channel_value[5] = LDC_get_channel_result(2,LDC16XX_2);
        Channel_value[6] = LDC_get_channel_result(1,LDC16XX_2);
        Channel_value[7] = LDC_get_channel_result(0,LDC16XX_2);
        
        Channel_value[8] = LDC_get_channel_result(3,LDC16XX_3);
        Channel_value[9] = LDC_get_channel_result(2,LDC16XX_3);
        Channel_value[10] = LDC_get_channel_result(1,LDC16XX_3);
        Channel_value[11] = LDC_get_channel_result(0,LDC16XX_3);
        
        Channel_value[12] = LDC_get_channel_result(3,LDC16XX_4);
        Channel_value[13] = LDC_get_channel_result(2,LDC16XX_4);
        Channel_value[14] = LDC_get_channel_result(1,LDC16XX_4);
        Channel_value[15] = LDC_get_channel_result(0,LDC16XX_4);
        
        Channel_value[16] = LDC_get_channel_result(3,LDC16XX_5);
        Channel_value[17] = LDC_get_channel_result(2,LDC16XX_5);
        Channel_value[18] = LDC_get_channel_result(1,LDC16XX_5);
        Channel_value[19] = LDC_get_channel_result(0,LDC16XX_5);
        
        /* 输出 CSV 行: ms_since_boot,ch0,ch1,...,ch19 */
        /* 输出 CSV 行
           如果已同步：打印 epoch 秒（浮点）作为第一列（与主机/相机时间基一致）
           否则打印 MCU 毫秒自启动（整数）作为第一列。 */
        uint32_t tick = HAL_GetTick();
        if (time_synced)
        {
            double t_epoch = base_epoch + ((double)tick) / 1000.0;
            printf("%.9f", t_epoch);
        }
        else
        {
            printf("%lu", (unsigned long)tick);
        }
        for(uint8_t idx = 0; idx < 20; idx++)
        {
            printf(",%lu", (unsigned long)Channel_value[idx]);
        }
        printf("\r\n");

        // Wait until next sample, but keep servicing commands for tight sync.
        // Use small slices so SETBASE/PING responds quickly.
        uint32_t wait_ms = SAMPLE_PERIOD_MS;
        while (wait_ms > 0)
        {
            uint32_t step = (wait_ms > 5) ? 5 : wait_ms;
            LL_mDelay(step);
            wait_ms -= step;
            handle_usart1_command();
        }
        LL_GPIO_TogglePin(GPIOC, LL_GPIO_PIN_13);
    }
}
