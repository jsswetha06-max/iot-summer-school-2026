/*
 * Digital Piano using Passive Buzzer
 * Author: Swetha
 */

const int buzzer = 8;

const int btnDo = 2;
const int btnRe = 3;
const int btnMi = 4;
const int btnFa = 5;
const int modeBtn = 6;

bool majorScale = true;
bool lastModeState = HIGH;

int majorNotes[4] = {262, 294, 330, 349};
int minorNotes[4] = {262, 294, 311, 349};

void setup() {

  pinMode(btnDo, INPUT_PULLUP);
  pinMode(btnRe, INPUT_PULLUP);
  pinMode(btnMi, INPUT_PULLUP);
  pinMode(btnFa, INPUT_PULLUP);
  pinMode(modeBtn, INPUT_PULLUP);

}

void loop() {

  bool currentMode = digitalRead(modeBtn);

  if (lastModeState == HIGH && currentMode == LOW) {
    majorScale = !majorScale;
    delay(200);
  }

  lastModeState = currentMode;

  bool b1 = digitalRead(btnDo) == LOW;
  bool b2 = digitalRead(btnRe) == LOW;
  bool b3 = digitalRead(btnMi) == LOW;
  bool b4 = digitalRead(btnFa) == LOW;

  int pressed = b1 + b2 + b3 + b4;

  if (pressed >= 2) {

    tone(buzzer, 392);

  }
  else if (b1) {

    tone(buzzer, majorScale ? majorNotes[0] : minorNotes[0]);

  }
  else if (b2) {

    tone(buzzer, majorScale ? majorNotes[1] : minorNotes[1]);

  }
  else if (b3) {

    tone(buzzer, majorScale ? majorNotes[2] : minorNotes[2]);

  }
  else if (b4) {

    tone(buzzer, majorScale ? majorNotes[3] : minorNotes[3]);

  }
  else {

    noTone(buzzer);

  }
}
