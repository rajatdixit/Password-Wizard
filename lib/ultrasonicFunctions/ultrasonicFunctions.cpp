#include "Arduino.h"
#include "ultrasonicFunctions.h"

#define ECHO A4
#define TRIG A5

//Ultrasonic distance measurement Sub function
int getDistance() 
{
    digitalWrite(TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    return (int)pulseIn(ECHO, HIGH) / 58;
}