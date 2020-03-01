#include "Arduino.h"
#include "objectFollower.h"
#include "remoteFunctions.h"
#include "servoFunctions.h"
#include "motorFunctions.h"

bool needToExit4;
unsigned long int tempMotorIncomingValue4;

void objectFollower()
{
    initializeObjectFollower();
    initializeRemote();
    needToExit4 = false;
    while (!needToExit4)
    {
        waitForInput();
        tempMotorIncomingValue4 = inputReceived();

        switch (tempMotorIncomingValue4)
        {
        case Forward:
            startObjectFollow();
            resumeRemote();
            break;

        case Back:
            stopObjectFollow();
            resumeRemote();
            break;

        case ZERO:
            needToExit4 = true;
            break;
        }
    }
}

void initializeObjectFollower()
{
    initializeMotor();
    Serial.println("Motors Initialized..");
    initializeServo();
    Serial.println("Servo Initialized..");
}

void startObjectFollow()
{
    
}

void stopObjectFollow()
{

}