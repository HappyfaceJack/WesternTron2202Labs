/**
The circuit relies on both button and potentiometer to alter the delay.
*/
unsigned long past = 0, initial = 0, released = 0, delayMs = 100;
int pin[4] = {4, 5, 6, 7};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(pin[i], OUTPUT);
  }
  pinMode(A0, INPUT);
  for (int i = 2; i <= 3; i++) {
    pinMode(i, INPUT);
  }
  Serial.begin(13000);
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

  if (digitalRead(3) == LOW) {
    delayMs = analogRead(A0);
    
    //Serial.println(delayMs); Showing the delay on Serial
    while (millis() < past + delayMs) {
    }
    
    past = millis();
    
  } else {
    if (digitalRead(2) == LOW) {
      initial = millis();

    } else {
      released = millis();
    }
    if (released > initial) {
      delayMs = released - initial;
    }
    
    //Serial.println(delayMs); Showing the delay on Serial
    while (millis() < past + delayMs) {
    }
    
    past = initial;
  }
}
