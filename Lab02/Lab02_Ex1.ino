unsigned long past = 0;
long delayMs = 100;
int pin[4] = {4, 5, 6, 7};
int state=1;
void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(pin[i], OUTPUT);
  }
 pinMode(A0,INPUT);
}

void loop() {
  if (millis() - past >= delayMs) {
    past = millis();
    if (state == 16) {
      state = 1;
    }
    switch (state) {
      case 1:
        writeAll(0, 0, 0, 0);
        break;
      case 2:
        writeAll(1, 0, 0, 0);
        break;
      case 3:
        writeAll(1, 1, 0, 0);
        break;
      case 4:
        writeAll(1, 1, 1, 0);
        break;
      case 5:
        writeAll(1, 1, 1, 1);
        break;
      case 6:
        writeAll(0, 1, 1, 1);
        break;
      case 7:
        writeAll(0, 0, 1, 1);
        break;
      case 8:
        writeAll(0, 0, 0, 1);
        break;
      case 9:
        writeAll(0, 0, 0, 0);
        break;
      case 10:
        writeAll(0, 0, 0, 1);
        break;
      case 11:
        writeAll(0, 0, 1, 1);
        break;
      case 12:
        writeAll(0, 1, 1, 1);
        break;
      case 13:
        writeAll(1, 1, 1, 1);
        break;
      case 14:
        writeAll(1, 1, 1, 0);
        break;
      case 15:
        writeAll(1, 1, 0, 0);
        break;
      case 16:
        writeAll(1, 0, 0, 0);
        break;
    }
    state++;
  }
}

void writeAll(int i, int j, int k, int l) {
  digitalWrite(4, i);
  digitalWrite(5, j);
  digitalWrite(6, k);
  digitalWrite(7, l);
}
