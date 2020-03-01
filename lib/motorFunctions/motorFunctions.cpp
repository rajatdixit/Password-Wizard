#include "Arduino.h"
#include "motorFunctions.h"
#include "remoteFunctions.h"

long unsigned int tempMotorIncomingValue;
int motorDelay = 100;
int carSpeed = 125; //till 255
bool needToExit;

void initializeMotor()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    analogWrite(ENA, carSpeed);
    analogWrite(ENB, carSpeed);
}

void moveCarMode()
{
    initializeRemote();
    needToExit = false;
    while (!needToExit)
    {
        waitForInput();
        tempMotorIncomingValue = inputReceived();
    
        switch (tempMotorIncomingValue)
        {
            case Forward:
            goForward();
            resumeRemote();
            break;

            case Back:
            goBackward();
            resumeRemote();
            break;

            case Right:
            goRight();
            resumeRemote();
            break;

            case Left:
            goLeft();
            resumeRemote();
            break;

            default:
            motorStop();
            resumeRemote();
            break;

            case ZERO: //exit case
            needToExit = true;
            motorStop();
            break;
        }
    } 
}

void goForward()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);  //go forward
    delay(motorDelay);
}

void goBackward()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);   //go back
    delay(motorDelay);
}

void goRight()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW); 
    delay(motorDelay);
}

void goLeft()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(motorDelay);
}

void motorStop()
{
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);  //stop
    delay(motorDelay);
}