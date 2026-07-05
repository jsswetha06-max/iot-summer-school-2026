/*
 * Author: Swetha
 * Date: 05-07-2026
 * Description:
 * LED blink program with serial blink counter
 * and potentiometer-controlled blink speed.
 */

int blinkCount = 0;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(A0);

  int blinkDelay = map(sensorValue, 0, 1023, 100, 1000);

  digitalWrite(13, HIGH);
  delay(blinkDelay);

  digitalWrite(13, LOW);
  delay(blinkDelay);

  blinkCount++;

  Serial.print("Blink count: ");
  Serial.println(blinkCount);
}
