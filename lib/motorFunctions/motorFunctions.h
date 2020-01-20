//This file defines all Motor related functions used in our project
///-----------------------Variable Definitions--------------------------///
#define ENB 5  // Left  wheel speed
#define IN1 7  // Left  wheel forward
#define IN2 8  // Left  wheel reverse
#define IN3 9  // Right wheel reverse
#define IN4 11 // Right wheel forward
#define ENA 6  // Right wheel speed
///-----------------------Functions Declarations------------------------///
void initializeMotor();
void moveCarMode();
void goForward();
void goBackward();
void goRight();
void goLeft();
void motorStop();

//Special Functions
void harlemShake(); //crazy car mode