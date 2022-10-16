/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STD_TYPES.h"
#include "BIT_Manipulation.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "PORT_interface.h"
#include "SYSTICK_interface.h"
#include "Marron5.h"

void SendAudio(void);

int main(void)
{
	RCC_voidSysClkInit();

	RCC_voidEnablePerClk(RCC_AHB1,AHB1_GPIOA);

	PORT_voidInit();

	STK_voidSetPeriodicInterval(100,SendAudio);
	while(1);
}

void SendAudio(void)
{
	GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN8, GPIO_PIN_HIGH);
	static u16 x = 0;
	GPIO_u8SetGroupChannel(GPIO_PORTA, GPIO_PIN0, 8, Maroon5_raw[x++]);

	if(x == Maroon_raw_len) x = 0;

	GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN8, GPIO_PIN_LOW);
}