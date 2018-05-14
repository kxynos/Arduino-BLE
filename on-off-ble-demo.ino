/*
Modified version of this example https://github.com/hammadtq/Evothings-Demo-Apps/blob/master/hm10-arduino-ble/arduino-sketch/sketch_hm10/sketch_hm10.ino
Modified by Konstantinos Xynos (2018)

This allows for a HM-10 Bluetooth LE (BLE) module plugged into pins 7 and 8 (see below) to turn on and off the built-in light

The built-in light is off by default. 

Get an app that supports BLE and send one or zero to turn on or off the light. 

Tested on: Adruino UNO

*/
#include <SoftwareSerial.h>
//#define LED_PIN 2

#define LED_PIN LED_BUILTIN

SoftwareSerial mySerial(7, 8); // RX, TX  
// Connect HM10      Arduino Uno
//     Pin 1/TXD          Pin 7
//     Pin 2/RXD          Pin 8

void setup() {  
  Serial.begin(9600);
  // If the baudrate of the HM-10 module has been updated,
  // you may need to change 9600 by another value
  // Once you have found the correct baudrate,
  // you can update it using AT+BAUDx command 
  // e.g. AT+BAUD0 for 9600 bauds
  mySerial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {  
  int c;
  
  if (mySerial.available()) {
    c = mySerial.read();  
    
    Serial.println("Got input:");
// debug string to see value in serial
//    Serial.print(c);
    //1 = 49
    //0 = 48
    
    if (c != 48)
    {
      // Non-zero input means "turn on LED".
      Serial.println("  on");
      digitalWrite(LED_PIN, HIGH);
    }
    else
    {
      // Input value zero means "turn off LED".
      Serial.println("  off");
      digitalWrite(LED_PIN, LOW);
    }  
  }
}
