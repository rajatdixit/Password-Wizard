//-----------------------Includes-------------------------------------//
#include "Arduino.h"
#include "lineFollowing.h"
#include "remoteFunctions.h"
#include "motorFunctions.h"
//-----------------------Variable Definitions-------------------------//
#define SENSOR_LEFT 2
#define SENSOR_RIGHT 10
#define SENSOR_MIDDLE 4
bool needToExit3;
unsigned long int tempMotorIncomingValue3;
//-----------------------Functions------------------------------------//

void lineFollow()
{
    initializeRemote();
    needToExit3 = false;
    while (!needToExit3)
    {
        waitForInput();
        tempMotorIncomingValue3 = inputReceived();

        switch (tempMotorIncomingValue3)
        {
        case Forward:
            startLineFollow();
            resumeRemote();
            break;

        case Back:
            stopLineFollow();
            resumeRemote();
            break;

        case ZERO:
            needToExit3 = true;
            break;
        }
    }
}

void initializeLineFollow()
{
    initializeMotor();
    Serial.println("Motors Initialized..");
    initializeLineFollowSensors();
    Serial.println("Sensors Initialized..");
    Serial.println("! Please make sure to tune sensors manually before Line Following !");
}

void initializeLineFollowSensors()
{
    pinMode(SENSOR_LEFT, INPUT);
    pinMode(SENSOR_MIDDLE, INPUT);
    pinMode(SENSOR_RIGHT, INPUT);
}

bool readLeft()
{
    if (digitalRead(SENSOR_LEFT) == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool readMiddle()
{
    if (digitalRead(SENSOR_MIDDLE) == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool readRight()
{
    if (digitalRead(SENSOR_RIGHT) == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void startLineFollow()
{
    while (!(readLeft() == 1 && readMiddle() == 1 && readRight() == 1))
    {
        if (readLeft() == 1)
        {
            if (readMiddle() == 1)
            {
                if (readRight() == 1)
                {
                    motorStop();
                    Serial.println("Motors Stopped");
                }
                else
                {
                    goLeft();
                    Serial.println("Going Left");
                }
            }
            else
            {
                if (readRight() == 1)
                {
                    motorStop();
                    Serial.println("Motors Stopped");
                }
                else
                {
                    goLeft();
                    Serial.println("Going Left");
                }
            }
        }
        else
        {
            if (readMiddle() == 1)
            {
                if (readRight() == 1)
                {
                    goRight();
                    Serial.println("Going Right");
                }
                else
                {
                    goForward();
                    Serial.println("Going Forward");
                }
            }
            else
            {
                if (readRight() == 1)
                {
                    goRight();
                    Serial.println("Going Right");
                }
                else
                {
                    motorStop();
                    Serial.println("Motors Stopped");
                }
            }
        }
    }
    Serial.println("All Black Detected!! Ended Line Following");
    Serial.println("Press Down Button and 0 after to exit Line Following");
    motorStop();
}

void stopLineFollow()
{
    motorStop();
    Serial.println("Line Following Ended..");
}