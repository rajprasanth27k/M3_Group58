#ifndef DRIVER_H_
#define DRIVER_H_

#include <stdint.h>

#define LED_GREEN 12  // here we are defining green led pin as 12
#define LED_ORANGE 13 // here we are defining orange led pin as 13
#define LED_RED 14    // here we are defining red led pin as 14
#define LED_BLUE 15   // here we are defining blue led pin as 15
#define user_btn 0    // here we are defining user button pin as 0

void evr_led(void);            // This will initialize all the LED's
void led_on(uint8_t led_no);   // This is to on custom LED
void led_off(uint8_t led_no);  // This is to off custom LED
void usr_delay(uint32_t time); // This is to provide some delay
void btn_on(void);             // This will initialize the button
int btn_chk(void);             // This will check no of button presses

#endif
