#ifndef Buzzer_H
#define Buzzer_H
#include "pico/stdlib.h"

#ifndef Buzzer_PIN 
#define Buzzer_PIN 13
#endif

void Buzzer_init();
void Buzzer_On();
void Buzzer_Off();

#endif 