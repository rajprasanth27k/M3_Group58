#include "driver.h"

const int ini_delay = 100000; // for delay initial values
void usr_delay(uint32_t time) // this is
{							  // for time = 1000 this gives delay of approx 1sec
	for (uint32_t i = 0; i < (time * ini_delay); i++)
	{
	}
}

void btn_on(void)
{
	//(for Gpio A)
	// for clocking and making it input(here) or output
	uint32_t *clkahb1 = (uint32_t *)0x40023830; // 0x40023800 + 0x30(offset) pg.no --> 65 (RCC) , 265 (RCC_AHB1ENR)
	*clkahb1 |= (1 << 0);						// enable GPIOA (GPIOAEN) pg.no 265

	/*This is optional because its input by default*/
	/*------*/
	uint32_t *gpioreg = (uint32_t *)0x40020000; // 0x40020000 pg.no --> 65 (GPIOA)
	*gpioreg &= ~(1 << 0);						// setting it as input
	*gpioreg &= ~(1 << 1);
	/*------*/

	uint32_t *gpiopupd = (uint32_t *)0x4002000C; //(GPIOx_PUPDR) + 0x0C(offset) for Pull up and pull down
	*gpiopupd |= (1 << 1);						 // for setting pull down for A0 page no 282
}

void evr_led(void)
{												//(for Gpio D)
												// for clocking and making it input or output(here)
	uint32_t *clkahb1 = (uint32_t *)0x40023830; // 0x40023800 + 0x30(offset) pg.no --> 65 (RCC) , 265 (RCC_AHB1ENR)
	uint32_t *gpioreg = (uint32_t *)0x40020C00; // 0x40020C00 pg.no --> 65 (GPIOD) (GPIOx_MODER)

	*clkahb1 |= (1 << 3); // enable GPIOD (GPIODEN) pg.no 265
	// configure it as General purpose output mode
	//  see pg.no 281 -> GPIO port mode register, MODERy[1:0] for understanding
	*gpioreg |= (1 << (2 * LED_GREEN));	 // setting MODER12 as an output port
	*gpioreg |= (1 << (2 * LED_ORANGE)); // setting MODER13 as an output port
	*gpioreg |= (1 << (2 * LED_RED));	 // settingMODER14 as an output port
	*gpioreg |= (1 << (2 * LED_BLUE));	 // setting MODER15 as an output port

	led_off(LED_GREEN);
	led_off(LED_ORANGE);
	led_off(LED_RED);
	led_off(LED_BLUE);
}

void led_on(uint8_t led_no)							// here this will on led for given LED pin
{													// for outputting data
	uint32_t *gpiodatareg = (uint32_t *)0x40020C14; //(GPIOx_ODR) + 0x14(offset)
	*gpiodatareg |= (1 << led_no);
}

void led_off(uint8_t led_no)						// here this will off led for given LED pin
{													// for outputting data
	uint32_t *gpiodatareg = (uint32_t *)0x40020C14; //(GPIOx_ODR) + 0x14(offset)
	*gpiodatareg &= ~(1 << led_no);
}

int btn_chk(void) // Done by Nyalam Praveenraj
{				  // for inputting button press data and returns button cnt
	int cnt = 0;
	int hfmilsec = 10000000;					  // for some milli seconds
	uint32_t *gpioadreg = (uint32_t *)0x40020010; //(GPIOx_IDR) + 0x10(offset)
	while (hfmilsec--)
	{
		if ((*gpioadreg) & (1 << user_btn)) // Checking if the switch is pressed or not (Polling)
		{									// check if the button is pressed or not
			usr_delay(150);
			cnt++;
			if (cnt > 4)
				cnt = 0;
		}
	}
	return cnt;
}
