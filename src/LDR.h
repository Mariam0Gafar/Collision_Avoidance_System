#ifndef LDR_H
#define LDR_H
#include "pico/stdlib.h"

#ifndef LDR_PIN 
#define LDR_PIN 3
#endif

void LDR_init(uint sensor_pin);
bool LDR_is_triggered(uint sensor_pin);
#endif 