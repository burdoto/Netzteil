// automatically generated by arduino-cmake
#line 1 "C:/Users/burdo/OneDrive/dev/arduino/Netzteil/netzteil.ino"
#include <I2C.h>
#include <II2C.h>
#include <MPU6050.h>
#include <MultiFuncShield.h>

#line 8 "C:/Users/burdo/OneDrive/dev/arduino/Netzteil/cmake-build-debug/Netzteil_netzteil.ino.cpp"
#include "Arduino.h"

//=== START Forward: C:/Users/burdo/OneDrive/dev/arduino/Netzteil/netzteil.ino
 void setup() ;
 void setup() ;
 void loop() ;
 void loop() ;
//=== END Forward: C:/Users/burdo/OneDrive/dev/arduino/Netzteil/netzteil.ino
#line 4 "C:/Users/burdo/OneDrive/dev/arduino/Netzteil/netzteil.ino"


MultiFuncShield* shield = new MultiFuncShield();

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    shield->write(420);

  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(500);                      // wait for a second
}
