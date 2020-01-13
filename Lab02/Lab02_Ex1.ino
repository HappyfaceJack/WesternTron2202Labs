/**
The purpose of the code is to have a blinking LED with specific sequence seen in the provided manual.
*/
unsigned long past = 0;
const long delayMs = 300; //a delay which maybe changed to the user's content
int pin[4] = {4, 5, 6, 7}; //pin number maybe changed

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(pin[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(pin[i], HIGH);
    wait();
    digitalWrite(pin[i+1], HIGH);
    wait();
    digitalWrite(pin[i], LOW);
    wait();
  }
  for (int i = 3; i >= 0; i--) {
   digitalWrite(pin[i], HIGH);
    wait();
    digitalWrite(pin[i-1], HIGH);
    wait();
    digitalWrite(pin[i], LOW);
    wait();
  }
}

void wait() {
  while (millis() < past + delayMs) {
  }
  past = millis();
}
