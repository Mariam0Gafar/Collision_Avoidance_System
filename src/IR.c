#include "IR.h"

void IR_init(uint sensor_pin) {
    gpio_init(sensor_pin);
    gpio_set_dir(sensor_pin, GPIO_IN);
}
bool IR_is_triggered(uint sensor_pin) {
return !gpio_get(sensor_pin); 
}


