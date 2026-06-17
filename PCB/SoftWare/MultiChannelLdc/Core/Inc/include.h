
#ifndef __INCLUDES_H__
#define __INCLUDES_H__
#define OS

#ifdef MAIN
    #define MAIN_EX
#else
    #define MAIN_EX extern
#endif

/*库级*/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "main.h"

/*bsp板级驱动*/
#include "Bsp_SysClock.h"
#include "Bsp_Usart.h"
#include "Bsp_Iic.h"





/*APP应用*/
#include "stm32f4xx_it.h"
#include "App_Ldc16xx.h"




/*逻辑程序*/



typedef enum
{
    false = 0,
    true = 1,
}tEnum, *tpEnum;
typedef union
{
    uint16_t    u16word;
    uint8_t     u8byte[2];
}tUnionUword;
extern tUnionUword gtUnionUword;
typedef union
{
    float          fp32;
    uint8_t        u8byte[4];
}tUnionFp32;
MAIN_EX tUnionFp32 gtUnionFp32;


#endif









