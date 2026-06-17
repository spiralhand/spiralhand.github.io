//////////////////////////////////////////////////////////////////////////
//               Bsp_SysClock.c
// 描述:        系统时钟驱动程序
//
// 履历:      
// -------------------------------
// 【1】创建模块              zx               2026年01月14日
// -------------------------------
#ifndef __HH_BSP_SYSCLOCK_H_HH__
#define __HH_BSP_SYSCLOCK_H_HH__	

#ifdef BSP_SYSCLOCK
#define BSP_SYSCLOCK_EX
#else
#define BSP_SYSCLOCK_EX extern
#endif
#include "include.h"
void BspSysClockInit(void);
void Error_Handler(void);
#endif

