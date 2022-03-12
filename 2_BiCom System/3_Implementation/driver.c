#include "driver.h"

const int ini_delay = 100000; 
void usr_delay(uint32_t time) 
{							  // for time = 1000 this gives delay of approx 1sec
	for (uint32_t i = 0; i < (time * ini_delay); i++)
	{
	}
}

void btn_on(void)
{
	//(for Gpio A)
	// for clocking and making it input(here) or output
	uint32_t *clkahb1 = (uint32_t *)0x40023830; 
	*clkahb1 |= (1 << 0);					

	
	uint32_t *gpioreg = (uint32_t *)0x40020000; 
	*gpioreg &= ~(1 << 0);						// setting it as input
	*gpioreg &= ~(1 << 1);
	/*------*/

	uint32_t *gpiopupd = (uint32_t *)0x4002000C; //(GPIOx_PUPDR) + 0x0C(offset) 
	*gpiopupd |= (1 << 1);						 
}

void evr_led(void)
{											
												
	uint32_t *clkahb1 = (uint32_t *)0x40023830; 
	uint32_t *gpioreg = (uint32_t *)0x40020C00; 

	*clkahb1 |= (1 << 3); 
	*gpioreg |= (1 << (2 * LED_GREEN));	 
	*gpioreg |= (1 << (2 * LED_ORANGE)); 
	*gpioreg |= (1 << (2 * LED_RED));	 
	*gpioreg |= (1 << (2 * LED_BLUE));	 

	led_off(LED_GREEN);
	led_off(LED_ORANGE);
	led_off(LED_RED);
	led_off(LED_BLUE);
}

void led_on(uint8_t led_no)						
{													
	uint32_t *gpiodatareg = (uint32_t *)0x40020C14; 
	*gpiodatareg |= (1 << led_no);
}

void led_off(uint8_t led_no)					
{													
	uint32_t *gpiodatareg = (uint32_t *)0x40020C14; 
	*gpiodatareg &= ~(1 << led_no);
}

int btn_chk(void) 
{				  
	int cnt = 0;
	int hfmilsec = 10000000;					 
	uint32_t *gpioadreg = (uint32_t *)0x40020010; 
	while (hfmilsec--)
	{
		if ((*gpioadreg) & (1 << user_btn)) 
		{									
			usr_delay(150);
			cnt++;
			if (cnt > 4)
				cnt = 0;
		}
	}
	return cnt;
}
