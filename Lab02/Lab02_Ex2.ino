unsigned long past = 0;
long delayMs = 100,vdelay=0;
int pin[4] = {4, 5, 6, 7};
int state=1;
int size=sizeof(pin);
void setup() {
  for (int i = 0; i < size; i++) {
    pinMode(pin[i], OUTPUT);
  }
 pinMode(A0,INPUT);
}

void loop() {
  delayMs =analogRead(A0);
  if(state%2!=0){
  delayMs*=3;
  } else {
  delayMs*=1;
  }
  if (millis() - past >= delayMs) {
    past = millis();
    if (state == 16) {
      state = 1;
    }
    switch (state) {
      case 1:
        writeAll(1, 0, 0, 0);
        break;
      case 2:
        writeAll(1, 1, 0, 0);
        break;
      case 3:
        writeAll(0, 1, 0, 0);
        break;
      case 4:
        writeAll(0, 1, 1, 0);
        break;
      case 5:
        writeAll(0, 0, 1, 0);
        break;
      case 6:
        writeAll(0, 0, 1, 1);
        break;
      case 7:
        writeAll(0, 0, 0, 1);
        break;
      case 8:
        writeAll(0, 0, 1, 1);
        break;
      case 9:
        writeAll(0, 0, 1, 0);
        break;
      case 10:
        writeAll(0, 1, 1, 0);
        break;
      case 11:
        writeAll(0, 1, 0, 0);
        break;
      case 12:
        writeAll(1, 1, 0, 0);
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
