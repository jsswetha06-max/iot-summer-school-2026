# Project 2: Gas & Fire Safety Alert System

## Objective
Build a safety alert system that detects gas leaks and fire using an MQ-2 gas sensor and a flame sensor.

## Components Used
- Arduino Uno R3
- MQ-2 Gas Sensor (simulated using a potentiometer)
- Flame Sensor (simulated using a push button)
- Green LED
- Yellow LED
- Red LED
- Piezo Buzzer
- Breadboard
- Jumper Wires

## Working

### SAFE
- Gas level below 30%
- Green LED ON
- Buzzer OFF

### WARNING
- Gas level between 30% and 60%
- Yellow LED ON
- Buzzer beeps once every second

### DANGER
- Gas level above 60% **or** flame detected
- Red LED ON
- Continuous buzzer alarm

## Simulation Notes
- A potentiometer was used to simulate the MQ-2 gas sensor because Tinkercad does not include the actual sensor.
- A push button with `INPUT_PULLUP` was used to simulate the active-low flame sensor.

## MQ-2 Warm-up
The real MQ-2 gas sensor requires approximately 1–2 minutes of warm-up after power-on before providing stable readings.

## Why is the Flame Sensor Active-Low?
The flame sensor outputs **LOW** when a flame is detected and **HIGH** when no flame is detected. This behavior was simulated using Arduino's internal pull-up resistor.

## Screenshots

### Safe State
![Safe](safe.png)

### Warning State
![Warning](warning.png)

### Danger State
![Danger](danger.png)

## Author
**Swetha**
