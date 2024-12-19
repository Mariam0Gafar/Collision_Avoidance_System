#ifndef IR_H
#define IR_H
#include "pico/stdlib.h"

#ifndef IR_PIN_LEFT 
#define IR_PIN_LEFT 5
#endif

#ifndef IR_PIN_RIGHT 
#define IR_PIN_RIGHT 28
#endif

void IR_init(uint sensor_pin);
bool IR_is_triggered(uint sensor_pin);
#endif 