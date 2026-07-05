# LED Blink with Potentiometer Control

## Project Title

LED Blink with Potentiometer-Controlled Speed and Serial Monitoring

---

## Project Overview

This project demonstrates a simple Arduino LED blink program that has been enhanced with serial monitoring and potentiometer-based speed control. The onboard LED blinks continuously while the potentiometer adjusts the blinking interval in real time. The Serial Monitor displays the number of completed blink cycles.

---

## Hardware Required

| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| USB Cable | 1 |
| Breadboard | 1 |
| LED (optional, if not using onboard LED) | 1 |
| 220 Ω Resistor | 1 |
| Potentiometer (10 kΩ) | 1 |
| Jumper Wires | As required |

---

## Circuit Diagram Description

- Connect the LED anode (long leg) to Arduino Digital Pin 13 through a 220 Ω resistor.
- Connect the LED cathode (short leg) to GND.
- Connect one outer pin of the potentiometer to 5V.
- Connect the other outer pin of the potentiometer to GND.
- Connect the middle pin (wiper) of the potentiometer to Analog Pin A0.
- Connect the Arduino to the computer using the USB cable.

---

## How to Upload the Code

1. Connect the Arduino Uno to your computer using a USB cable.
2. Open the Arduino IDE.
3. Open the `led_blink.ino` file.
4. Select **Tools → Board → Arduino Uno**.
5. Select the correct COM Port under **Tools → Port**.
6. Click the **Verify (✓)** button to compile the program.
7. Click the **Upload (→)** button.
8. After uploading, open **Tools → Serial Monitor**.
9. Set the baud rate to **9600**.
10. Rotate the potentiometer to observe changes in the LED blinking speed.

---

## Expected Output

- The LED connected to Pin 13 blinks continuously.
- Rotating the potentiometer increases or decreases the blink speed.
- The Serial Monitor displays:

```
Blink count: 1
Blink count: 2
Blink count: 3
...
```

- The blink count increases after every blink cycle.

---

## Troubleshooting Tips

1. Ensure the correct Arduino board and COM port are selected in the Arduino IDE.
2. Verify that the potentiometer is connected correctly, with its center pin connected to Analog Pin A0.
3. If the LED does not blink, check the wiring and ensure the LED polarity is correct.
4. If no data appears in the Serial Monitor, confirm that the baud rate is set to **9600**.
5. Re-upload the program if the upload process fails or the board is not detected.

---

## Author

**Name:** Swetha

**Project:** IoT Summer School 2026 - Week 1 LED Blink Project
