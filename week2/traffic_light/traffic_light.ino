// Traffic Light System with Pedestrian Button

// LED pins
const int RED = 2;
const int YELLOW = 3;
const int GREEN = 4;

// Pedestrian button
const int BUTTON = 7;

// Timing (in ms)
const unsigned long RED_TIME = 5000;
const unsigned long YELLOW_TIME = 2000;
const unsigned long GREEN_TIME = 4000;
const unsigned long PED_TIME = 8000;

// State variables
enum State {RED_STATE, YELLOW_STATE, GREEN_STATE, PED_RED};
State currentState = RED_STATE;

unsigned long lastChange = 0;
unsigned long pedStart = 0;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP); // button pressed = LOW

  Serial.begin(9600);

  lastChange = millis();
  setLights(RED_STATE);
}

void loop() {
  unsigned long now = millis();

  // Check pedestrian button (active LOW)
  if (digitalRead(BUTTON) == LOW && currentState != PED_RED) {
    currentState = PED_RED;
    pedStart = now;
    setLights(PED_RED);

    Serial.print("[");
    Serial.print(now);
    Serial.println(" ms] Pedestrian button pressed → RED ON");
  }

  // Pedestrian mode handling
  if (currentState == PED_RED) {
    if (now - pedStart >= PED_TIME) {
      currentState = RED_STATE;
      lastChange = now;
    }
    return;
  }

  // Normal traffic cycle
  switch (currentState) {

    case RED_STATE:
      if (now - lastChange >= RED_TIME) {
        currentState = YELLOW_STATE;
        lastChange = now;
        setLights(YELLOW_STATE);
      }
      break;

    case YELLOW_STATE:
      if (now - lastChange >= YELLOW_TIME) {
        currentState = GREEN_STATE;
        lastChange = now;
        setLights(GREEN_STATE);
      }
      break;

    case GREEN_STATE:
      if (now - lastChange >= GREEN_TIME) {
        currentState = RED_STATE;
        lastChange = now;
        setLights(RED_STATE);
      }
      break;
  }
}

// Function to control LEDs + Serial output
void setLights(State state) {
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  unsigned long t = millis();

  switch (state) {
    case RED_STATE:
    case PED_RED:
      digitalWrite(RED, HIGH);
      Serial.print("[");
      Serial.print(t);
      Serial.println(" ms] State: RED");
      break;

    case YELLOW_STATE:
      digitalWrite(YELLOW, HIGH);
      Serial.print("[");
      Serial.print(t);
      Serial.println(" ms] State: YELLOW");
      break;

    case GREEN_STATE:
      digitalWrite(GREEN, HIGH);
      Serial.print("[");
      Serial.print(t);
      Serial.println(" ms] State: GREEN");
      break;
  }
}
