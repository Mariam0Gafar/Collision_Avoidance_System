#include "LED.h"


void led_init(){
 gpio_init(LED_PIN);
 gpio_set_dir(LED_PIN, GPIO_OUT);
}
void led_On(){
    gpio_put(LED_PIN,true);
}
void led_Off(){
    gpio_put(LED_PIN,false);
}