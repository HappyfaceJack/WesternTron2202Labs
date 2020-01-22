//There are 2 parts the writer and the receiver

//MASTER WRITER
#include <Servo.h>
int pin[] = {4,5,6,7};
int switch1 = 3, button = 2, state = 1, limit = 13;
long delaytime = 100, buttontime = 0,buttontime1 = 0;
long time1 = 0;
int pot = A0, potval = 0, switchval = 1;
boolean buttonval;
Servo servo1;
int angle = 0;
String sendval;

void setup() {
  for (int i = 0; i < 4; i++){
    pinMode(pin[i] , OUTPUT);
  }
  Serial.begin(9600);
  pinMode (button , INPUT_PULLUP);
  pinMode (switch1 , INPUT);
  servo1.attach(9);
}

void loop() {
  switchval = digitalRead(switch1);
  potval = analogRead(pot);
  buttonval = digitalRead(button);
    
  if (switchval == 0){
    if (state % 2 == 0){
      delaytime = 100 + potval;
    }
    else{
      delaytime = 300 + potval;
    }
  }
  else if(switchval == 1){
    if(buttonval == 0){
      buttontime1++;
      buttontime++;
      if (buttontime1 <= 50){
        buttontime = 0;
      }
    }
    if (buttonval == 1){
      buttontime1 = 0;
    }
    if (state % 2 == 0){
      delaytime = 100 + buttontime;
    }
    else{
      delaytime = 300 + buttontime;
    }
  }
  sendval = (String) delaytime;
  Serial.println(sendval);
}

//READER (Slave)
#include <Servo.h>
int pin[] = {4,5,6,7};
int switch1 = 3, button = 2, state = 1, limit = 13;
long delaytime = 100, buttontime = 0,buttontime1 = 0;
long time1 = 0;
int pot = A0, potval = 0, switchval = 1;
boolean buttonval;
Servo ihatemylife;
int angle =0;

void setup() {
  ihatemylife.attach(9);
  for (int i = 0; i < 4; i++){
    pinMode(pin[i] , OUTPUT);
  }
  Serial.begin(9600);
  pinMode (button , INPUT_PULLUP);
  pinMode (switch1 , INPUT);
}

void loop() {
    if (Serial.available()){
      delaytime = Serial.parseInt();
    }
    
  switch (state){
   case 1:
    ledseq(1,0,0,0);
    servoseq(0);
    break;
   case 2:
    ledseq(1,1,0,0);
    servoseq(30);
    break;
   case 3:
    ledseq(0,1,0,0);
    servoseq(60);
    break;
   case 4:
    ledseq(0,1,1,0);
    servoseq(90);
    break;
   case 5:
    ledseq(0,0,1,0);
    servoseq(120);
    break;
   case 6:
    ledseq(0,0,0,1);
    servoseq(150);
    break;
   case 7:
    ledseq(0,0,0,1);
    servoseq(180);
    break;
   case 8:
    ledseq(0,0,1,1);
    servoseq(150);
    break;
   case 9:
    ledseq(0,0,1,0);
    servoseq(120);
    break;
   case 10:
    ledseq(0,1,1,0);
    servoseq(90);
    break;
   case 11:
    ledseq(0,1,0,0);
    servoseq(60);
    break;
   case 12:
    ledseq(1,1,0,0);
    servoseq(30);
    break;
  }
  if (millis()-time1 >= delaytime){
     state++;
     time1 = millis();
     if (state == limit){
      state = 1;
     }
  }
}

void ledseq(int i, int j, int k, int z){
  digitalWrite(4 , i);
  digitalWrite(5 , j);
  digitalWrite(6 , k);
  digitalWrite(7 , z);
}
void servoseq(int i){
  ihatemylife.write(i);
}
