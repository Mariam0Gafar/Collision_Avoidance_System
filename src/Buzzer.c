#include "Buzzer.h"

void Buzzer_init() {
    gpio_init(Buzzer_PIN);
    gpio_set_dir(Buzzer_PIN, GPIO_OUT);
}
void Buzzer_On(){
    gpio_put(Buzzer_PIN,true);
}
void Buzzer_Off(){
    gpio_put(Buzzer_PIN,false);
}


