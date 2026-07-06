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

  if (digitalRead(btnDo) == LOW)
    tone(buzzer, 262);

  else if (digitalRead(btnRe) == LOW)
    tone(buzzer, 294);

  else if (digitalRead(btnMi) == LOW)
    tone(buzzer, 330);

  else if (digitalRead(btnFa) == LOW)
    tone(buzzer, 349);

  else
    noTone(buzzer);
}
