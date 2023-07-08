#include <Wire.h>
#include <TimerOne.h>
#include <I2C.h>
#include <II2C.h>
#include <MPU6050.h>
#include <MultiFuncShield.h>

//LEDs an den digitalen PINs 10,11,12,13
const byte LED[] = {13,12,11,10};
int state = 1;
long last = 0;
byte mode = 0;

const byte BTN[] = {1,2,3};

#define ON LOW
#define OFF HIGH

void setup(){
  Serial.begin(9600);

  pinMode(BTN[0], INPUT); // button 1
  pinMode(BTN[1], INPUT); // button 2
  pinMode(BTN[2], INPUT); // button 3
  
  pinMode(LED[0], OUTPUT); //LED1 am digitalen PIN 13
  pinMode(LED[1], OUTPUT); //LED2 am digitalen PIN 12
  pinMode(LED[2], OUTPUT); //LED3 am digitalen PIN 11
  pinMode(LED[3], OUTPUT); //LED4 am digitalen PIN 10
  
  setLEDs();
}
 
void loop(){
  for (int i = 0; i < 3; i++) {
    if (analogRead(BTN[i]) == HIGH) {
      mode = i;
    }
  }
  
  if (millis() - last < analogRead(0) * 3) {
    return;
  }

  switch (mode) {
    case 0: // binärer zähler
      state = state + 1;
      break;
    default: // lauflicht
      state = state << 1;
      break;
  }
    
  if (!setLEDs()) {
    state = 1;
    setLEDs();
  }
  
  last = millis();
}

bool setLEDs(){
  Serial.print("setting state: 0b");
  Serial.println(state, BIN);

  MFS.write(state);
  digitalWrite(LED[0], (state & 0b1000) != 0 ? ON : OFF);
  digitalWrite(LED[1], (state & 0b0100) != 0 ? ON : OFF);
  digitalWrite(LED[2], (state & 0b0010) != 0 ? ON : OFF);
  digitalWrite(LED[3], (state & 0b0001) != 0 ? ON : OFF);

  switch (mode) {
    case 0:
      return state <= 0xF;
    default:
      return state <= 0x8;
  }
}
