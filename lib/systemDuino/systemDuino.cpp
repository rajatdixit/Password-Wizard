#include "Arduino.h"
#include "systemDuino.h"

void lockArduino()
{
  int i;
  //LOCK ARDUINO//
  Serial.println("!LOCKED OUT PLEASE WAIT FOR 60 SECONDS!");
  for (i = 60; i > 0; i --)
  {
    Serial.print(i);
    Serial.println(" !");
    delay(1000);
  }
}

void successArduino()
{
  Serial.println("!Success Unlocked!");
  delay(1000);
}