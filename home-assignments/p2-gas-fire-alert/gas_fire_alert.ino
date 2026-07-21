#define GAS_SENSOR A0
#define FLAME_SENSOR 7

#define GREEN_LED 10
#define YELLOW_LED 11
#define RED_LED 12

#define BUZZER 9


unsigned long previousMillis = 0;
bool beepState = false;


void setup()
{
  Serial.begin(9600);

  pinMode(FLAME_SENSOR, INPUT_PULLUP);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  Serial.println("Gas & Fire Safety System Started");
  Serial.println("MQ-2 warming up...");
  delay(5000);
}


void loop()
{

  int gasValue = analogRead(GAS_SENSOR);

  int gasPercent = map(gasValue,0,1023,0,100);


  bool flameDetected = (digitalRead(FLAME_SENSOR)==LOW);

  String status;

  if(gasPercent > 60 || flameDetected)
  {

    status="DANGER";

    digitalWrite(GREEN_LED,LOW);
    digitalWrite(YELLOW_LED,LOW);
    digitalWrite(RED_LED,HIGH);

    tone(BUZZER,1000);

  }


  else if(gasPercent > 30)
  {

    status="WARNING";


    digitalWrite(GREEN_LED,LOW);
    digitalWrite(YELLOW_LED,HIGH);
    digitalWrite(RED_LED,LOW);


    unsigned long currentMillis=millis();


    if(currentMillis-previousMillis>=1000)
    {
      previousMillis=currentMillis;

      beepState=!beepState;


      if(beepState)
        tone(BUZZER,800);
      else
        noTone(BUZZER);

    }

  }


  else
  {

    status="SAFE";


    digitalWrite(GREEN_LED,HIGH);
    digitalWrite(YELLOW_LED,LOW);
    digitalWrite(RED_LED,LOW);

    noTone(BUZZER);

  }



  Serial.print("GAS: ");
  Serial.print(gasPercent);
  Serial.print("% | FLAME: ");

  if(flameDetected)
    Serial.print("DETECTED");
  else
    Serial.print("NONE");


  Serial.print(" | STATUS: ");
  Serial.println(status);



  delay(1000);

}
