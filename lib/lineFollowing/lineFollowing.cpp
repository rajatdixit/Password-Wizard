//-----------------------Includes-------------------------------------//
#include "Arduino.h"
#include "lineFollowing.h"
#include "remoteFunctions.h"
#include "motorFunctions.h"
//-----------------------Variable Definitions-------------------------//
#define SENSOR_LEFT     2
#define SENSOR_RIGHT    10
#define SENSOR_MIDDLE   4
bool needToExit3;
unsigned long int tempMotorIncomingValue3;
//-----------------------Functions------------------------------------//
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

void readLeft()
{
    digitalRead(SENSOR_LEFT);
}

void readMiddle()
{
    digitalRead(SENSOR_MIDDLE);
}

void readRight()
{
    digitalRead(SENSOR_RIGHT);
}

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
            case Forward: //move servo right
            startLineFollow();
            resumeRemote();
            break;

            case Back: //move servo left
            stopLineFollow();
            resumeRemote();
            break;

            case ZERO: //exit case
            needToExit3 = true;
            break;
        }
    } 
}

void startLineFollow()
{

}

void stopLineFollow()
{
    
}