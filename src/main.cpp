/* Long Term Robotics Schedule
     As soon as we unlock the password
     We will develop a state machine with 9 digits
     Each digit unlocks a special mode to make arduino car work

     Left, Right, Top Bottom  : Move car
     Digit 0                  : Reset Code
     Digit 1 pressed          : Move Car Mode
     Digit 2 pressed          : Servo Sweep
     Digit 3 pressed          : Line Follow Code
     Digit 4 pressed          : Object Follower
     Digit 5 pressed          : 
     Digit 6 pressed          :
     Digit 7 pressed          :
     Digit 8 pressed          :
     Digit 9 pressed          :
     Digit * and #            : 
*/
#include "Arduino.h"
#include "led.h"
#include "password.h"
#include "remoteFunctions.h"
#include "motorFunctions.h"
#include "servoFunctions.h"
#include "lineFollowing.h"
#include "objectFollower.h"
#include "ultrasonicFunctions.h"
#include "lcdFunctions.h"

//------DEFINITIONS-------//
long unsigned int tempIncomingValue;

void setup()
{
  Serial.begin(9600);
  initializeRemote();
  //enterPassword();
  //printStoredPassword();
  //tryPassword(); // You are allowed only 4 tries to break password.
  initializeMotor();
  initializeLED();
  blinkLED(10, 50);
  initializeLCD();
  printTestMessage();
  blinkLED(10,50);
}

void loop()
{
{
  Serial.println("Press a button");
  waitForInput();
  tempIncomingValue = inputReceived();

  switch (tempIncomingValue)
  {
    case OK:
    Serial.println ("Digit 1 pressed            : Move Car Mode");
    Serial.println ("Digit 2 pressed            : Servo Sweep");
    Serial.println ("Digit 3 pressed            : Line Follow Mode");
    Serial.println ("Digit 4 pressed            : Object Follower");
    Serial.println ("Digit 5 pressed            : ");
    Serial.println ("Digit 6 pressed            : ");
    Serial.println ("Digit 7 pressed            : ");
    Serial.println ("Digit 8 pressed            : ");
    Serial.println ("Digit 9 pressed            : ");
    Serial.println ("Digit * and # pressed      : ");
    resumeRemote();
    break;

    case ONE:
    Serial.println("You are in Move Car Mode");
    Serial.println("Press Forward, Back, Left, Right Buttons to move the car");
    moveCarMode();
    resumeRemote();
    break;

    case TWO:
    Serial.println("You are in Servo Sweep Mode");
    Serial.println("Press Left, Right to move Servo");
    defaultServo();
    moveServo();
    resumeRemote();
    break;

    case THREE:
    Serial.println("You are in Line Follow Mode");
    Serial.println("Press Up arrow to start line following");
    Serial.println("Press Down arrow to stop line following");
    lineFollow();
    resumeRemote();
    break;

    case FOUR:
    Serial.println("You are in Object Follower Mode");
    Serial.println("Press Up arrow to start Following Objects");
    objectFollower();
    resumeRemote();
    break;

    default:
    Serial.println("Welcome to the home page");
    Serial.println("Press OK on your IR remote to see list of available options");
    resumeRemote();
    break;
  }
}
}