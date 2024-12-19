#include "LDR.h"
#include "IR.h"
#include "LED.h"
#include "Ultrasonic.h"
#include "Buzzer.h"
#include "DCMotor.h"
#include <stdio.h>
#include <FreeRTOS.h>
#include "task.h"

bool LDR_status;
bool IR_status_left;
bool IR_status_right;
float distance = 500;

void LDRTask( void* pvParameters){
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xPeriod = pdMS_TO_TICKS(500) ; 

    LDR_init(LDR_PIN);

    while(1){
      LDR_status = LDR_is_triggered(LDR_PIN);
      printf("LDR is reading\n");
      vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

void LEDTask( void* pvParameters){
TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xPeriod = pdMS_TO_TICKS(500) ; 

    led_init(LED_PIN);

    while(1){
         if(distance <50){
             if (!LDR_status) {
                printf("Light turned on\n");
                led_On();
             }
        }
        if(LDR_status || distance > 45){
            printf("Light turned off\n");
            led_Off();
        }
      vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

void IRTask( void* pvParameters){
TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xPeriod = pdMS_TO_TICKS(500) ; 

    IR_init(IR_PIN_LEFT);
    IR_init(IR_PIN_RIGHT);

    while(1){
        IR_status_left = IR_is_triggered(IR_PIN_LEFT);
        IR_status_right = IR_is_triggered(IR_PIN_RIGHT);
        printf("IR is reading\n");
      vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

void BuzzerTask( void* pvParameters){
TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xPeriod = pdMS_TO_TICKS(500) ; 

    Buzzer_init();

    while(1){
        if(IR_status_left || IR_status_right){
            Buzzer_On();
            printf("Buzzer turned on\n");

        }
        else{
            Buzzer_Off();
            printf("Buzzer turned off\n");

        }
      vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

void UltrasonicTask( void* pvParameters){
TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xPeriod = pdMS_TO_TICKS(60) ; 

    Ultrasonic_init();

    while(1){
      distance = Ultrasonic_get_distance();
      printf("Ultrasonic is reading: %f\n",distance);
 
      vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}

void DCMotorTask(void* pvParameters) {
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xPeriod = pdMS_TO_TICKS(60);

    motor_init();

    while (1) {
        if (distance < 25) { 
            printf("Car stopped\n");
            motor_control(0, true);
        } else if (distance < 50) {  
            printf("Car slowed down\n");
            motor_control(100, true);
        } else { 
            printf("Car moving\n");
            motor_control(200, true);
        }
        vTaskDelayUntil(&xLastWakeTime, xPeriod);
    }
}


int main(){
    stdio_init_all();
    xTaskCreate(LDRTask, "LDR_Task", 256, NULL, 5, NULL);
    xTaskCreate(LEDTask, "LED_Task", 256, NULL, 5, NULL);
    xTaskCreate(IRTask, "IR_Task", 256, NULL, 6, NULL);
    xTaskCreate(BuzzerTask, "Buzzer_Task", 256, NULL, 5, NULL);
    xTaskCreate(UltrasonicTask, "Ultrasonic_Task", 256, NULL, 6, NULL);
    xTaskCreate(DCMotorTask, "DCMotor_Task", 256, NULL, 2, NULL);
    
    vTaskStartScheduler();
    while(1){ };
}

