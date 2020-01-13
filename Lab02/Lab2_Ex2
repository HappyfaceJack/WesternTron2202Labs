/**
 * Utilizing a potentiometer to control the delay of the LEDs
 */
unsigned long past = 0;
int pin[4] = {4, 5, 6, 7};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(pin[i], OUTPUT);
  }
  //LED pin number may differ
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {

  for (int i = 0; i < 4; i++) {
    digitalWrite(pin[i], HIGH);
    wait();
    digitalWrite(pin[i + 1], HIGH);
    wait();
    digitalWrite(pin[i], LOW);
    wait();
  }
  
  for (int i = 3; i >= 0; i--) {
    digitalWrite(pin[i], HIGH);
    wait();
    digitalWrite(pin[i - 1], HIGH);
    wait();
    digitalWrite(pin[i], LOW);
    wait();
  }
}

void wait() {
  //reading the potentiometer
  long delayMs = analogRead(A0);
  Serial.println(delayMs);
  while (millis() < past + delayMs) {
  }
  past = millis();
}
