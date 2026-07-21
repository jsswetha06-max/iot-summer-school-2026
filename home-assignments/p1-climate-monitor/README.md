# Smart Room Climate Monitor

## Components
- ESP32 Dev Board
- DHT11
- SSD1306 OLED
- Active Buzzer
- Red LED
- Green LED
- Breadboard
- Jumper Wires

## Wiring
- DHT11 DATA → GPIO4
- OLED SDA → GPIO21
- OLED SCL → GPIO22
- Red LED → GPIO25
- Green LED → GPIO26
- Buzzer → GPIO27

## Libraries
- DHTesp
- Adafruit GFX
- Adafruit SSD1306

## Features
- Temperature monitoring
- Humidity monitoring
- OLED display
- Comfort index
- Red/Green LED indication
- Buzzer alert
- CSV logging every 5 seconds
- Max/Min temperature tracker

## Expected Output
The OLED continuously displays temperature and humidity. If temperature exceeds 38°C or humidity exceeds 80%, the red LED turns on, the buzzer sounds for one second, and the status changes to DANGER. Sensor readings are logged to the Serial Monitor every five seconds in CSV format.


