//This file defines all LCD related functions used in our project
/*
  The circuit for Arduino Mega2560 R3
 * LCD VSS    pin to            GND - LOW
 * LCD VDD    pin to digital pin 53 - HIGH
 * LCD VO     pin to digital pin 51 - HIGH 
 * LCD RS     pin to digital pin 49 - XXXX
 * LCD RW     pin to digital pin 47 - LOW
 * LCD E      pin to digital pin 45 - XXXX
 * LCD D0     pin to digital pin 43 - XXXX
 * LCD D1     pin to digital pin 41 - XXXX
 * LCD D2     pin to digital pin 39 - XXXX
 * LCD D3     pin to digital pin 37 - XXXX
 * LCD D4     pin to digital pin 35 - XXXX
 * LCD D5     pin to digital pin 33 - XXXX
 * LCD D6     pin to digital pin 31 - XXXX
 * LCD D7     pin to digital pin 29 - XXXX
 * LCD A      pin to digital pin 27 - HIGH
 * LCD K      pin to digital pin 25 - LOW
*/
///-----------------------Variable Definitions--------------------------///
#define VDD 53
#define VO  51
#define RS  49
#define RW  47
#define E   45
#define D0  43
#define D1  41
#define D2  39
#define D3  37
#define D4  35
#define D5  33
#define D6  31
#define D7  29
#define A   27
#define K   25
///-----------------------Functions Declarations------------------------///
void initializeLCD();
void printTestMessage();