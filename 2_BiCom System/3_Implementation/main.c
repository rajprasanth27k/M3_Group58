#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "driver.h"
#include <stdio.h>

static void wind_stat(void); // here this function will Turn on all the LED's at once
static void alrm_stat(void); // here this function will Turn off all the LED's at once
static void door_stat(void); // here this function will on and off LED's with a certain delay (in anti-clockwise)
static void bat_info(void);	 // here this function will on and off LED's with a certain delay (in clockwise)

static void wind_stat(void) // This function is done by Mantra G with help of Nyalam Praveenraj
{
	led_on(LED_ORANGE);
	led_on(LED_GREEN);
	led_on(LED_RED);
	led_on(LED_BLUE);
}

static void alrm_stat(void) // This function is done by Mantra G with help of Nyalam Praveenraj
{
	led_off(LED_ORANGE);
	led_off(LED_GREEN);
	led_off(LED_RED);
	led_off(LED_BLUE);
}
static void bat_info(void) // This function is done by bashaboina Naresh with help of Nyalam Praveenraj
{

	led_on(LED_GREEN);
	usr_delay(350);
	led_off(LED_GREEN);
	led_on(LED_ORANGE);
	usr_delay(350);
	led_off(LED_ORANGE);
	led_on(LED_RED);
	usr_delay(350);
	led_off(LED_RED);
	led_on(LED_BLUE);
	usr_delay(350);
	led_off(LED_BLUE);
	led_on(LED_GREEN);
	usr_delay(350);
	led_off(LED_GREEN);
}

static void door_stat(void) // This function is done by Varun S with help of Nyalam Praveenraj
{

	led_on(LED_GREEN);
	usr_delay(350);
	led_off(LED_GREEN);
	led_on(LED_BLUE);
	usr_delay(350);
	led_off(LED_BLUE);
	led_on(LED_RED);
	usr_delay(350);
	led_off(LED_RED);
	led_on(LED_ORANGE);
	usr_delay(350);
	led_off(LED_ORANGE);
	led_on(LED_GREEN);
	usr_delay(350);
	led_off(LED_GREEN);
}

int main(void)
{ // main function is done by bashaboina Naresh, Varun S, Mantra G with help of Nyalam Praveenraj

	evr_led();
	btn_on();

	while (1)
	{
		volatile int btncnt = btn_chk();
		if (btncnt == 1)
		{ // comparing the no of cnts of button
			wind_stat();
			btncnt = 0;
		}
		else if (btncnt == 2)
		{ // comparing the no of cnts of button
			alrm_stat();
			btncnt = 0;
		}
		else if (btncnt == 3)
		{ // comparing the no of cnts of button
			bat_info();

			btncnt = 0;
		}
		else if (btncnt == 4)
		{ // comparing the no of cnts of button
			door_stat();
			btncnt = 0;
		}
	}
}
