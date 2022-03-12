/**
 * @file main.c
 * @author Raj prasanth Karunanidhi  
 * 
 * @brief 
 * *       
 * @version 0.1
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "led.h"
#include <stdio.h>

static void Lock_door(void);			   
static void unLock_door(void);		  
static void CLOCK(void);  
static void ANTICLOCK(void); 



int main(void)
{

	GPIO_Inc_IO();
	GPIO_Inc_sw();



	while (1)
	{
		int Signal = Adc();
		volatile int press= key(Signal);

		switch (press)
		{
		case 2:
			  Lock_door();
			  Signal = 0;
			  break;
		case 3:
			unLock_door();
			Signal = 0;
			break;
		case 4:
			CLOCK();
			Signal = 0;
			break;
		case 5:
			ANTICLOCK();
			Signal = 0;
			break;

		default:
			break;
		}


		
	}
}


static void Lock_door(void) 
{
	led_on(LED_ORANGE);
	led_on(LED_GREEN);
	led_on(LED_RED);
	led_on(LED_BLUE);
}

static void ANTICLOCK(void) 
{

	led_on(LED_GREEN);
	my_delay_ms(350);
	led_off(LED_GREEN);
	led_on(LED_ORANGE);
	my_delay_ms(350);
	led_off(LED_ORANGE);
	led_on(LED_RED);
	my_delay_ms(350);
	led_off(LED_RED);
	led_on(LED_BLUE);
	my_delay_ms(350);
	led_off(LED_BLUE);
	led_on(LED_GREEN);
	my_delay_ms(350);
	led_off(LED_GREEN);
}

static void CLOCK(void) 
{

	led_on(LED_GREEN);
	my_delay_ms(400);
	led_off(LED_GREEN);
	led_on(LED_BLUE);
    my_delay_ms(400);
	led_off(LED_BLUE);
	led_on(LED_RED);
	my_delay_ms(350);
	led_off(LED_RED);
	led_on(LED_ORANGE);
	my_delay_ms(350);
	led_off(LED_ORANGE);
	led_on(LED_GREEN);
	my_delay_ms(350);
	led_off(LED_GREEN);
}

static void unLock_door(void) 
{
	led_off(LED_ORANGE);
	led_off(LED_GREEN);
	led_off(LED_RED);
	led_off(LED_BLUE);
}