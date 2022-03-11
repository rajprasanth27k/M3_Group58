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

static void lock(void);			   
static void unlock(void);		  
static void approach_light(void);  
static void alarm_actOrDact(void); 

static void lock(void) 
{
	led_on(LED_ORANGE);
	led_on(LED_GREEN);
	led_on(LED_RED);
	led_on(LED_BLUE);
}

static void alarm_actOrDact(void) 
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

static void approach_light(void) 
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

static void unlock(void) 
{
	led_off(LED_ORANGE);
	led_off(LED_GREEN);
	led_off(LED_RED);
	led_off(LED_BLUE);
}

int main(void)
{

	GPIO_Inc_IO();
	GPIO_Inc_sw();



	while (1)
	{
		int btncnt = btn_press();
		volatile int press= key(btncnt);
		if (press== 1244)
		{ 
			lock();
			btncnt = 0;
		}
		else if (press == 1843)
		{
			unlock();
			btncnt = 0;
		}
		else if (press == 6789)
		{ 
			alarm_actOrDact();

			btncnt = 0;
		}
		else if (press == 5478)
		{
			approach_light();
			btncnt = 0;
		}
	}
}
