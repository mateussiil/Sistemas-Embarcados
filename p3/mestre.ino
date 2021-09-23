
#include "Wire.h"
  
#define escravo1 6
#define escravo2 7

int potValue = 0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  Wire.requestFrom(escravo1, 1);
  
  while (Wire.available())
  { 
    potValue = Wire.read(); 
  }
      
  Wire.beginTransmission(escravo2); 
  Wire.write(potValue);               
  Wire.endTransmission();   
  
}

