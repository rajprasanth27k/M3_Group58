
#ifndef LED_FUNTION
#define LED_FUNTION
#include <stdint.h>
 #define LED_GREEN 12  
#define LED_ORANGE 13 
#define LED_RED 14    
#define LED_BLUE 15   
#define user_btn 0   


void GPIO_Inc_sw(void);
void GPIO_Inc_IO(void);
void led_init_all(void);     
void led_on(uint8_t led_no);  
void led_off(uint8_t led_no); 
void my_delay_ms(uint32_t time); 
void button_init(void);  
int btn_press(void);     
int key(int data);

#endif
