#ifndef Led_H
#define Led_H
#include "pico/stdlib.h"

#ifndef LED_PIN 
#define LED_PIN 6
#endif

void led_init();
void led_On();
void led_Off();

#endif 