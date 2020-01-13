/**
The purpose of the code is to have a blinking LED with specific sequence seen in the provided manual.
*/

unsigned long past = 0;
const long delayMs = 100;
int pin[4] = {4, 5, 6, 7}; //The pin numbers maybe changed to suitable numbers according to the wiring

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(pin[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(pin[i], HIGH);
    wait();
  }
  for (int i = 0; i < 4; i++) {
    digitalWrite(pin[i], LOW);
    wait();
  }
  for (int i = 3; i >= 0; i--) {
    digitalWrite(pin[i], HIGH);
    wait();
  }
  for (int i = 3; i >= 0; i--) {
    digitalWrite(pin[i], LOW);
    wait();
  }
}

void wait() {//a substitute to the delay(), where it is a constraint in the lab
  while (millis() < past + delayMs) {
  }
  past = millis();
}
