
#include "Wire.h"

int pinMotor = 5; 


void setup() {
  Wire.begin(7);
  Wire.onReceive(receiveEvent);
  pinMode(pinMotor, OUTPUT);
  Serial.begin(9600);
}

void loop() {  
  delay(100);
}


void receiveEvent(int howMany) {
  if (Wire.available()) {
    int pot = Wire.read();
    analogWrite(pinMotor, pot);
  }
}

