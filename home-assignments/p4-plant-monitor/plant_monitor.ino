#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


#define SOIL_PIN     34
#define DHT_PIN      4
#define DHT_TYPE     DHT22

#define RELAY_PIN    26
#define GREEN_LED    18
#define RED_LED      19
#define BUZZER       23
#define BUTTON_PIN   15



DHT dht(DHT_PIN, DHT_TYPE);

const int DRY_VALUE = 3200;
const int WET_VALUE = 1200;

bool pumpOn = false;
bool manualMode = false;

unsigned long manualStart = 0;
unsigned long lastUpdate = 0;

int moisturePercent = 0;
float temperature = 0;
float humidity = 0;



int readSoilMoisture()
{
  int raw = analogRead(SOIL_PIN);

  int percent = map(raw,
                    DRY_VALUE,
                    WET_VALUE,
                    0,
                    100);

  percent = constrain(percent,0,100);

  return percent;
}



void updateOLED()
{
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0,0);

  display.print("Soil: ");
  display.print(moisturePercent);
  display.println("%");

  display.print("Temp: ");
  display.print(temperature);
  display.println(" C");

  display.print("Hum : ");
  display.print(humidity);
  display.println("%");

  display.print("Status: ");

  if(moisturePercent < 30)
    display.println("DRY");
  else if(moisturePercent <= 70)
    display.println("OPTIMAL");
  else
    display.println("WET");

 

  int width = map(moisturePercent,
                  0,
                  100,
                  0,
                  120);

  display.drawRect(4,54,120,8,SSD1306_WHITE);
  display.fillRect(4,54,width,8,SSD1306_WHITE);

  display.display();
}


void printSerial()
{
  Serial.print("Moisture: ");
  Serial.print(moisturePercent);
  Serial.print("%");

  Serial.print(" | Temp: ");
  Serial.print(temperature);

  Serial.print(" C");

  Serial.print(" | Humidity: ");
  Serial.print(humidity);

  Serial.print("%");

  Serial.print(" | Pump: ");

  if(pumpOn)
    Serial.println("ON");
  else
    Serial.println("OFF");
}


void setup() {

  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  
  digitalWrite(RELAY_PIN, HIGH);

  dht.begin();

  Wire.begin(21, 22);
  delay(100);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED initialization failed!");
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.display();

}



void loop() {

  if (millis() - lastUpdate >= 1000) {

    lastUpdate = millis();

    moisturePercent = readSoilMoisture();

    temperature = dht.readTemperature();
    humidity = dht.readHumidity();


    if (isnan(temperature)) temperature = 0;
    if (isnan(humidity)) humidity = 0;

  
    if (digitalRead(BUTTON_PIN) == LOW && !manualMode) {
      manualMode = true;
      manualStart = millis();

      pumpOn = true;
      digitalWrite(RELAY_PIN, LOW);   
    }

    
    if (manualMode && millis() - manualStart >= 5000) {
      manualMode = false;
      
      if (moisturePercent > 40) {
        pumpOn = false;
      } else if (moisturePercent < 30) {
        pumpOn = true;
      }
    
       digitalWrite(RELAY_PIN, pumpOn ? LOW : HIGH);
    }


    if (!manualMode) {

  
      if (!pumpOn && moisturePercent < 30) {
        pumpOn = true;
      }

      if (pumpOn && moisturePercent > 40) {
        pumpOn = false;
      }

      digitalWrite(RELAY_PIN, pumpOn ? LOW : HIGH);
    }


    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);

    if (moisturePercent < 30) {
      digitalWrite(RED_LED, HIGH);
    }
    else {
      digitalWrite(GREEN_LED, HIGH);
    }

    
    if (pumpOn)
      tone(BUZZER, 1000);
    else
      noTone(BUZZER);

    updateOLED();
    printSerial();
  }
}
