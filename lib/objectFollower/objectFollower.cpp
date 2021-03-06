#include "Arduino.h"
#include "objectFollower.h"
#include "remoteFunctions.h"
#include "servoFunctions.h"
#include "motorFunctions.h"
#include "ultrasonicFunctions.h"

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
    initializeUltrasonic();
    Serial.println("Ultrasonic Initialized");
}

void startObjectFollow()
{
    defaultServo(); //default servo at 90 deg (straight)
    disableServo();

    while (getDistance() > 2)
    {
        if (getDistance() > 15)
        {
            motorStop();
        }
        else
        {
            goForward();
            motorStop();
        }
    }
    stopObjectFollow();
}

void stopObjectFollow()
{
    Serial.println("Object Following Stopped");
    Serial.println("Press 0 to exit");
}