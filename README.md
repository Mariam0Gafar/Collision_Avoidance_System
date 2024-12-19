# Smart Car System

## Abstract

The project presents an intelligent car system designed to enhance vehicle safety through real-time environmental sensing. Utilizing sensors and adaptive control mechanisms, the car detects obstacles in its path and responds by slowing down, stopping, or alerting the driver through visual and auditory cues. The system is also capable of detecting ambient light conditions to activate headlights automatically when required.

---

## Introduction

Modern automotive safety systems often rely on sensors to provide awareness and trigger safety mechanisms. In this project, we aim to create a smart car system that can:

1. Detect obstacles at various distances.
2. Adjust the car's speed or stop based on proximity.
3. Alert the driver in case of obstacles on both sides.
4. Activate the headlights when driving in low-light conditions.

The system combines proximity sensors, light sensors, and an embedded microcontroller to dynamically control the car’s behavior.

---

## Methodology

### 1. System Components

- **Microcontroller:** Raspberry Pico
- **Proximity Sensors:**
  - Ultrasonic sensors to detect obstacles at varying distances.
  - Infrared sensors to detect obstacles from both sides of the car.
- **Light Sensor:** LDR (Light Dependent Resistor) to detect ambient light levels.
- **Actuators:**
  - Motors for car movement.
  - Front LEDs for lighting control.
  - Buzzer for auditory alerts.

### 2. Sensor Setup and Control Logic

- **Obstacle Detection:** Using ultrasonic sensors, the car detects obstacles ahead, and based on distance thresholds (<45 cm, <15 cm), it responds by either slowing down or stopping.
- **Buzzer Alert:** If objects are detected on both sides using infrared sensors, a buzzer is triggered.
- **Light Sensing:** The LDR senses darkness; when the environment is below a certain threshold, the front LEDs are turned on.

### 3. Algorithm

- **Distance-based Responses:**
  - If an obstacle is <45 cm, the car slows down.
  - If an obstacle is <15 cm, the car stops completely.
- **Buzzer Activation:** If obstacles are detected on both sides (left and right) within a certain distance, the buzzer activates for driver alert.
- **Automatic Headlights:** If the ambient light is low and an obstacle is detected in front, the headlights turn on automatically.

---

## Results

### Testing and Performance

- **Obstacle Detection:** The system successfully detects obstacles within the defined distance ranges (<45 cm and <15 cm) and responds as expected by slowing down or stopping the car.
- **Buzzer Alert:** The buzzer reliably activates when obstacles are detected on both sides of the car.
- **Automatic Headlights:** The LDR accurately detects low-light conditions, turning the LEDs on when needed.

### Photos

---

## Conclusion

This project successfully demonstrates how embedded systems can be used to enhance vehicle safety and driving experience. The smart car system detects obstacles, adjusts the car's behavior based on proximity, alerts the driver in critical situations, and ensures proper lighting in dark conditions. Future improvements can focus on integrating more sensors (e.g., camera, radar) for enhanced object detection and implementing more complex control algorithms for smoother transitions.



