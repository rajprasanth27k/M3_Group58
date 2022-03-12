#ifndef DRIVER_H_
#define DRIVER_H_

#include <stdint.h>

#define LED_GREEN 12  // defining green led pin as 12
#define LED_ORANGE 13 // defining orange led pin as 13
#define LED_RED 14    // defining red led pin as 14
#define LED_BLUE 15   // defining blue led pin as 15
#define user_btn 0    // defining user button pin as 0

void evr_led(void);            //  initialize all the LED's
void led_on(uint8_t led_no);   //  on custom LED
void led_off(uint8_t led_no);  //  off custom LED
void usr_delay(uint32_t time); //  provide some delay
void btn_on(void);             //  initialize the button
int btn_chk(void);             //  check no of button presses

#endif
