const int buzzer = 8;

const int btnDo = 2;
const int btnRe = 3;
const int btnMi = 4;
const int btnFa = 5;

void setup() {
  pinMode(btnDo, INPUT_PULLUP);
  pinMode(btnRe, INPUT_PULLUP);
  pinMode(btnMi, INPUT_PULLUP);
  pinMode(btnFa, INPUT_PULLUP);
}

void loop() {

  bool b1 = digitalRead(btnDo) == LOW;
  bool b2 = digitalRead(btnRe) == LOW;
  bool b3 = digitalRead(btnMi) == LOW;
  bool b4 = digitalRead(btnFa) == LOW;

  int pressed = b1 + b2 + b3 + b4;

  if (pressed >= 2) {

    tone(buzzer, 392);

  }
  else if (b1) {

    tone(buzzer, 262);

  }
  else if (b2) {

    tone(buzzer, 294);

  }
  else if (b3) {

    tone(buzzer, 330);

  }
  else if (b4) {

    tone(buzzer, 349);

  }
  else {

    noTone(buzzer);

  }

  delay(20);
}
