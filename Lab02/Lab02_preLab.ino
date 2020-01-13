unsigned long past = 0;
const long delayMs = 100;
int pin[4] = {4, 5, 6, 7};
int a = 1, state;
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
void writeAll(int i, int j, int k, int l) {
  digitalWrite(pin[0], i);
  digitalWrite(pin[1], j);
  digitalWrite(pin[2], k);
  digitalWrite(pin[3], l);
}
void wait() {
  while (millis() < past + delayMs) {
  }
  past = millis();
}
