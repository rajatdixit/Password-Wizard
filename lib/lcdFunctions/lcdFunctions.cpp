#include "LiquidCrystal.h"
#include "Arduino.h"
#include "lcdFunctions.h"
#include "Wire.h"

LiquidCrystal lcd(RS, E, D0, D1, D2, D3, D4, D5, D6, D7);

void initializeLCD()
{
  //pinMode
  pinMode(VDD, OUTPUT);
  pinMode(VO, OUTPUT);
  pinMode(RW, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(K,OUTPUT);
  
  //digitalWrite
  digitalWrite(VDD, HIGH);
  digitalWrite(VO, LOW);
  digitalWrite(RW, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(K, LOW);

  lcd.begin(16,2);
}
void printTestMessage() 
{
  lcd.print("R");
}

