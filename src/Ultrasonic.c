#include "Ultrasonic.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include <hardware/gpio.h>
#include <hardware/timer.h>

void Ultrasonic_init() {
    gpio_init(TRIGGER_PIN);
    gpio_set_dir(TRIGGER_PIN, GPIO_OUT);
    
    gpio_init(ECHO_PIN);
    gpio_set_dir(ECHO_PIN, GPIO_IN);
}

float Ultrasonic_get_distance() {
    gpio_put(TRIGGER_PIN, 1);
    sleep_us(10);  
    gpio_put(TRIGGER_PIN, 0);
    
    while (gpio_get(ECHO_PIN) == 0);
    uint32_t start_time = time_us_32();
    
    while (gpio_get(ECHO_PIN) == 1);
    uint32_t end_time = time_us_32();
    
    uint32_t pulse_duration = end_time - start_time;
    
   
    float distance = (pulse_duration * 34300.0) / 2000000.0;  
    
    return distance;
}
