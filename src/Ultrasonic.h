#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "pico/stdlib.h"

#ifndef TRIGGER_PIN
#define TRIGGER_PIN 15  
#endif

#ifndef ECHO_PIN
#define ECHO_PIN 14     
#endif

void Ultrasonic_init();
float Ultrasonic_get_distance();

#endif 
