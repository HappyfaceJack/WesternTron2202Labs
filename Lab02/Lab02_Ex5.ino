#include <Servo.h>   

Servo servo_test;      
int angle = 0;
const int potentiometer = A0;
const int button = 2;
const int switcher = 3;

void updateState();
long updateCounter();


  int switchstate = 0;
  int buttonState = 0;
  int lastButtonState = 0; 
  long startPressed = 0;    
  long endPressed = 0;      
  int timeHold = 0;        
  int timeReleased = 0;    
  int previousinterval = 0;

unsigned long previousMillis = 0; 
long interval = 100;       
int state = 0;


void setup() {
  for(int i=4;i<=7;i++){
  pinMode(i, OUTPUT);
  }
  pinMode(button, INPUT);
  pinMode(switcher, INPUT);
  servo_test.attach(9);   
  Serial.begin(9600);
}

void loop() {
   buttonState = digitalRead(button);
  switchstate = digitalRead(switcher);

  unsigned long currentMillis = millis();
  
  if (switchstate == 0){
  

  interval = analogRead(potentiometer);
  

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    state ++;

    switch(state){ 
     case 1:
      writeAll(1,0,0,0);
      angle = 1;
      break;
     
     case 2:
      writeAll(1,1,0,0);
      angle = 2;
      break;
      
     case 3:
      writeAll(0,1,0,0);
      angle = 3;
      break;
   
     case 4:
      writeAll(0,1,1,0);
      angle = 4;
      break;   

     case 5:
      writeAll(0,0,1,0);
      angle = 5;
      break;
    
     case 6:
      writeAll(0,0,1,1);
      angle = 6;
      break;
    
    case 7:
      writeAll(0,0,0,1);
      angle = 7;
      break;

    case 8:
      writeAll(0,0,1,1);
      angle = 6;
      break;

    case 9:
      writeAll(0,0,1,0);
      angle = 5;
      break;

    case 10:
      writeAll(0,1,1,0);
      angle = 4;
      break;

    case 11:
      writeAll(0,1,0,0);
      angle = 3;
      break;

     default:
      writeAll(1,1,0,0);
      state = 0;
      angle = 2;
      break;
    }
    angle = map(angle,1,7,0,180);
    Serial.println(angle);
    servo_test.write(angle);  
  }   
 }else{
    
    if (buttonState != lastButtonState) { 
     timeHold =0;
     updateState(); 
    } else if (previousinterval != state) {
     interval = updateCounter();
    }
    lastButtonState = buttonState;

    previousinterval = state;
    
    if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    state ++;

    switch(state){ 
     case 1:
      writeAll(1,0,0,0);
      angle = 1;
      break;
     
     case 2:
      writeAll(1,1,0,0);
      angle = 2;
      break;

     case 3:
      writeAll(0,1,0,0);
      angle = 3;
      break;
      
     case 4:
      writeAll(0,1,1,0);
      angle = 4;
      break;

     case 5:
      writeAll(0,0,1,0);
      angle = 5;
      break;
    
     case 6:
      writeAll(0,0,1,1);
      angle = 6;
      break;
    
    case 7:
      writeAll(0,0,0,1);
      angle = 7;
      break;

    case 8:
      writeAll(0,0,1,1);
      angle = 6;
      break;

    case 9:
      writeAll(0,0,1,0);
      angle = 5;
      break;

    case 10:
      writeAll(0,1,1,0);
      angle = 4;
      break;

    case 11:
      writeAll(0,1,0,0);
      angle = 3;
      break;

     default:
      writeAll(1,1,0,0);
      state = 0;
      angle = 2;
      break;
    }
    angle = map(angle,1,7,0,180);
    Serial.println(angle);
    servo_test.write(angle);   
 }
}
}

void updateState() {
  if (buttonState == 1) {
      startPressed = millis();
      timeReleased = startPressed - endPressed;

  } else {
      endPressed = millis();
      timeHold = endPressed - startPressed;
  }
}
long updateCounter() {
  if (buttonState == 1) {
      timeHold = millis() - startPressed;
      
  return timeHold;
  } else {
      timeReleased = millis() - endPressed;
      return timeHold;
  }
}
void writeAll(int i, int j, int k, int l) {
  digitalWrite(4, i);
  digitalWrite(5, j);
  digitalWrite(6, k);
  digitalWrite(7, l);
}
