# Project 3: Ultrasonic Parking Assistant

## Objective
A car parking assistance system that measures the distance between a vehicle and an obstacle using an ultrasonic sensor. The system provides visual and audio alerts based on the distance.

---

## Components Used

- Arduino Uno R3
- HC-SR04 Ultrasonic Sensor
- SSD1306 0.96" I2C OLED Display
- Active Buzzer
- Green LED
- Yellow LED
- Red LED
- 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Circuit Connections

| Component | Arduino Pin |
|-----------|-------------|
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| Green LED | D2 |
| Yellow LED | D3 |
| Red LED | D4 |
| Buzzer | D6 |
| OLED SDA | A4 |
| OLED SCL | A5 |

---

## Working Principle

The HC-SR04 ultrasonic sensor works using the time-of-flight principle.

The sensor sends an ultrasonic pulse and measures the time taken for the echo to return from an obstacle.

Distance is calculated using:

```
Distance = (Time × Speed of Sound) / 2
```

In Arduino:

```
distance = duration * 0.034 / 2
```

where:
- Duration is the echo pulse width in microseconds.
- 0.034 cm/µs is the speed of sound.
- Division by 2 accounts for the outgoing and returning wave.

---

## Distance Alert Zones

| Distance | Zone | Output |
|----------|------|--------|
| > 60 cm | SAFE | Green LED, No beep |
| 30–60 cm | CAUTION | Yellow LED, beep every 800 ms |
| 15–30 cm | CLOSE | Yellow + Red LED, beep every 300 ms |
| < 15 cm | DANGER | Red LED, Continuous alarm |

---

## Noise Reduction

To improve accuracy, the system takes 5 ultrasonic readings and calculates the average distance value.

This reduces sudden fluctuations caused by sensor noise.

---

## OLED Display

The OLED displays:

- Current distance in centimeters
- Current parking zone
- Proximity bar graph

Example:

```
42 cm
Zone: CAUTION
███████
```

---

## Simulation

The project was simulated using Wokwi.

The HC-SR04 distance slider was used to simulate an approaching obstacle.

### SAFE State

![Safe](safe.png)

### CAUTION State

![Caution](caution.png)

### CLOSE State

![Close](close.png)

### DANGER State

![Danger](danger.png)

---

## Author

**Swetha**
