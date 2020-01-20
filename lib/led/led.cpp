#include "Arduino.h"
#include "led.h"

void initializeLED()
{
  pinMode(LED_PIN, OUTPUT); 
}

void blinkLED (int numberOfTimes, int delayTime)
{
  int i;
  for (i = 0; i < numberOfTimes; i++)
  {
    Serial.print("LED Flashing..");
    Serial.print(" ");
    Serial.println(i);
    digitalWrite(LED_PIN, HIGH);
    delay(delayTime);
    digitalWrite(LED_PIN, LOW);
    delay(delayTime);
  }
}