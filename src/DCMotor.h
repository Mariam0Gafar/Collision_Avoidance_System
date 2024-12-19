#ifndef DC_Motor_H
#define DC_Motor_H

#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define MOTOR_PWM_PIN 10
#define MOTOR_DIR_PIN1 11
#define MOTOR_DIR_PIN2 12

void motor_init();
void motor_control(uint16_t speed, bool forward);

#endif


