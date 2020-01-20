#include "Arduino.h"
#include "servoFunctions.h"
#include "remoteFunctions.h"
///-----------------------Includes--------------------------------------///
#include "Servo.h"
///-----------------------Variable Definitions--------------------------///
Servo myServo1; //local object
#define SERVO_PIN 3 //pin
bool needToExit2;
int currServoPos; //current servo position
long unsigned int tempMotorIncomingValue2;

//-------------------------Functions-----------------------------------//
void initializeServo()
{
    Serial.println("Enabling Servo..");
    myServo1.attach(SERVO_PIN);
    delay(50);
    Serial.println("Done");
}

void defaultServo()
{
    initializeServo();
    myServo1.write(90);
    delay(50);
    disableServo();
}

void disableServo()
{
    Serial.println("Disabling Servo..");
    myServo1.detach();
    delay(50);
    Serial.println("Done");
}

void moveServo()
{
    initializeRemote();
    needToExit2 = false;
    while (!needToExit2)
    {
        waitForInput();
        tempMotorIncomingValue2 = inputReceived();
    
        switch (tempMotorIncomingValue2)
        {
            case Right: //move servo right
            moveServoRight();
            resumeRemote();
            break;

            case Left: //move servo left
            moveServoLeft();
            resumeRemote();
            break;

            case ZERO: //exit case
            needToExit2 = true;
            break;
        }
    } 
}

void moveServoRight()
{
    initializeServo();
    currServoPos = myServo1.read();
    Serial.println(currServoPos);

    if (currServoPos <= 0)
    {
        currServoPos = 0;
        myServo1.write(0);
    }
    else
    {
        myServo1.write(currServoPos - 20);
    }
    disableServo();
}

void moveServoLeft()
{
    initializeServo();
    currServoPos = myServo1.read();
    Serial.println(currServoPos);
    
    if (currServoPos >= 180)
    {
        currServoPos = 180;
        myServo1.write(180);
    }
    else
    {
        myServo1.write(currServoPos + 20);
    }
    disableServo();
}