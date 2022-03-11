/**
 * @file led.c
 * @author Raj prasanth Karunanidhi  
 * @brief 
 * @version 0.1
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include "led.h"

const int for_delay = 100000; 
const int encrypt1 = 1;		 
const int encrypt2 = 2;		  
const int encrypt3 = 3;		  
const int encrypt4 = 4;		  
int un_used_var;



void GPIO_Inc_IO(void){

    uint32_t *pRccAhb1enr = (uint32_t *)0x40023830;	  
	uint32_t *pGpiodModeReg = (uint32_t *)0x40020C00; 

	*pRccAhb1enr |= (1 << 3); 
	*pGpiodModeReg |= (1 << (2 * LED_GREEN));  
	*pGpiodModeReg |= (1 << (2 * LED_ORANGE)); 
	*pGpiodModeReg |= (1 << (2 * LED_RED));	   
	*pGpiodModeReg |= (1 << (2 * LED_BLUE));  

	led_off(LED_GREEN);
	led_off(LED_ORANGE);
	led_off(LED_RED);
	led_off(LED_BLUE);

     





}

void GPIO_Inc_sw(void)
{

	uint32_t *pRccAhb1enr = (uint32_t *)0x40023830; 
	*pRccAhb1enr |= (1 << 0);						
	uint32_t *pGpiodModeReg = (uint32_t *)0x40020000; 
	*pGpiodModeReg &= ~(1 << 0);					 
	*pGpiodModeReg &= ~(1 << 1);
	uint32_t *pGpioPuPdReg = (uint32_t *)0x4002000C; 
	*pGpioPuPdReg |= (1 << 1);		

}

void my_delay_ms(uint32_t time) 
{								
	for (uint32_t i = 0; i < (time * for_delay); i++)
	{
		un_used_var++;
	}
}

void button_init(void)
{
	
	uint32_t *pRccAhb1enr = (uint32_t *)0x40023830; 
	*pRccAhb1enr |= (1 << 0);						
	
	uint32_t *pGpiodModeReg = (uint32_t *)0x40020000; 
	*pGpiodModeReg &= ~(1 << 0);					 
	*pGpiodModeReg &= ~(1 << 1);


	uint32_t *pGpioPuPdReg = (uint32_t *)0x4002000C; 
	*pGpioPuPdReg |= (1 << 1);						
}

void led_init_all(void)
{													  
	uint32_t *pRccAhb1enr = (uint32_t *)0x40023830;	  
	uint32_t *pGpiodModeReg = (uint32_t *)0x40020C00; 

	*pRccAhb1enr |= (1 << 3); 
	*pGpiodModeReg |= (1 << (2 * LED_GREEN));  
	*pGpiodModeReg |= (1 << (2 * LED_ORANGE)); 
	*pGpiodModeReg |= (1 << (2 * LED_RED));	   
	*pGpiodModeReg |= (1 << (2 * LED_BLUE));  

	led_off(LED_GREEN);
	led_off(LED_ORANGE);
	led_off(LED_RED);
	led_off(LED_BLUE);
}

void led_on(uint8_t led_no)							
{												
	uint32_t *pGpiodDataReg = (uint32_t *)0x40020C14; 
	*pGpiodDataReg |= (1 << led_no);
}

void led_off(uint8_t led_no)						  
{													  
	uint32_t *pGpiodDataReg = (uint32_t *)0x40020C14; 
	*pGpiodDataReg &= ~(1 << led_no);
}

int btn_press(void) 
{ 
	int count = 0;
	int hfmilsec = 10000000;					
	uint32_t *pGpioaDataReg = (uint32_t *)0x40020010; 
	while (hfmilsec--)
	{
		if ((*pGpioaDataReg) & (1 << user_btn))
		{										
			count++;
			if (count > 4)
				count = 0;
		}
	}
	return count;
}

int key(int data)
{

	if (data == encrypt1)
	{ int dta = 1000 + 244;
		return dta;
	}
	else if (data == encrypt2)
	{int dta = 1000 + 843;
		return dta;
	}
	else if (data == encrypt3)
	{int dta = 6000 + 789;
		return dta;
	}
	else if (data == encrypt4)
	{int dta = 5000 + 478;
		return dta;
	}
	return 0;
}
