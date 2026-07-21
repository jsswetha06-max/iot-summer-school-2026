
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define DHTPIN 4
#define DHTTYPE DHT22

#define RED_LED 25
#define GREEN_LED 26
#define BUZZER 27

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

unsigned long previousRead = 0;
unsigned long previousCSV = 0;
unsigned long previousScreen = 0;
unsigned long buzzerStart = 0;

float temperature = 0;
float humidity = 0;

float maxTemp = -100;
float minTemp = 100;

String status = "COMFORT";

bool buzzerOn = false;
int screen = 0;

void setup() {

  Serial.begin(115200);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BUZZER, LOW);

  Wire.begin(21,22);

  dht.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println("OLED Failed");
    while(true);
  }

  display.clearDisplay();
  display.display();

  Serial.println("Smart Room Climate Monitor Started");
}

void loop() {

  unsigned long currentMillis = millis();

  if(currentMillis - previousRead >= 2000){

    previousRead = currentMillis;

    humidity = dht.readHumidity();
    temperature = dht.readTemperature();

    if(isnan(temperature) || isnan(humidity)){
      Serial.println("Failed to read DHT22!");
      return;
    }

    if(temperature > maxTemp)
      maxTemp = temperature;

    if(temperature < minTemp)
      minTemp = temperature;

    if(temperature < 25 && humidity < 60)
      status = "COOL";
    else if(temperature <= 32 && humidity <= 70)
      status = "COMFORT";
    else if(temperature <= 38 && humidity <= 80)
      status = "HOT";
    else
      status = "DANGER";

    if(temperature > 38 || humidity > 80){

      digitalWrite(RED_LED,HIGH);
      digitalWrite(GREEN_LED,LOW);

      digitalWrite(BUZZER,HIGH);
      buzzerOn = true;
      buzzerStart = currentMillis;

    }else{

      digitalWrite(RED_LED,LOW);
      digitalWrite(GREEN_LED,HIGH);

    }

  }

  if(buzzerOn && currentMillis - buzzerStart >=1000){

    digitalWrite(BUZZER,LOW);
    buzzerOn=false;

  }

  if(currentMillis - previousCSV >=5000){

    previousCSV = currentMillis;

    Serial.print(currentMillis);
    Serial.print(",");

    Serial.print(temperature);
    Serial.print(",");

    Serial.print(humidity);
    Serial.print(",");

    Serial.println(status);

  }

  if(currentMillis - previousScreen >=5000){

    previousScreen = currentMillis;

    screen++;

    if(screen>2)
      screen=0;

  }

  display.clearDisplay();
  display.setTextColor(WHITE);

  if(screen==0){

    display.setTextSize(1);

    display.setCursor(0,0);
    display.print("Temp: ");
    display.print(temperature,1);
    display.println(" C");

    display.setCursor(0,20);
    display.print("Hum : ");
    display.print(humidity,1);
    display.println(" %");

  }

  else if(screen==1){

    display.setTextSize(1);

    display.setCursor(0,0);
    display.println("Comfort Index");

    display.setTextSize(2);

    display.setCursor(0,22);
    display.println(status);

  }

  else{

    display.setTextSize(1);

    display.setCursor(0,0);
    display.print("Max Temp:");
    display.println(maxTemp,1);

    display.setCursor(0,20);
    display.print("Min Temp:");
    display.println(minTemp,1);

  }

  display.display();

}
