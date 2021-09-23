#include "Wire.h"

int potPin = A0; // Potenciômetro
int value = 0;
int y = 0;

int valuePrev = 0;

  
// endereco do modulo slave que pode ser um valor de 0 a 255

void setup() {
  pinMode(potPin, INPUT);

  Wire.begin(6);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
  
}

void loop() {
  y = analogRead(potPin)/4;
  value = map(y, 0, 1023, 0, 255);
}

void requestEvent()
{
 	 Wire.write(value);
}
