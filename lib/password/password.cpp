#include "Arduino.h"
#include "password.h"
///-----------------------Includes--------------------------------------///
#include "systemDuino.h"
#include "remoteFunctions.h"
///-----------------------Variable Definitions--------------------------///
long int storedPassword[6]; // 6 digit password
long int userPassword[6];   // 6 digit password
int numberOfTries;
long unsigned int incomingValue1;
long unsigned int incomingValue2;
int maxTries = 4; // maximum number of tries after incorrect password entered
/////----------------------Funtion Definitions-------------------------/////
void enterPassword()
{
  Serial.println("!..Welcome to Password Setup Wizard..!");

  Serial.println("Please enter first digit..Waiting..");
  passwordStore(0); //store first digit

  Serial.println("Please enter second digit..Waiting..");
  passwordStore(1); //store second digit

  Serial.println("Please enter third digit..Waiting..");
  passwordStore(2); //store third digit

  Serial.println("Please enter fourth digit..Waiting..");
  passwordStore(3); //store fourth digit

  Serial.println("Please enter fifth digit..Waiting..");
  passwordStore(4); //store fifth digit

  Serial.println("Please enter sixth digit..Waiting..");
  passwordStore(5); //store sixth digit
}

void passwordStore(int digitNumber) //for self password
{
  waitForInput();
  incomingValue1 = inputReceived();
  storedPassword[digitNumber] = incomingValue1;
  resumeRemote();
}

void passwordStoreUser(int digitNumber) //user entered password
{
  waitForInput();
  incomingValue2 = inputReceived();
  userPassword[digitNumber] = incomingValue2;
  resumeRemote();
}

void tryPassword()
{
  if (numberOfTries >= maxTries)
  {
    //LOCKED OUT//
    numberOfTries = 0; // reset number of tries
    Serial.println("!..You have 0 tries remaining..!");
    lockArduino(); // After 4 tries Arduino gets locked and prints Try Again for 1 minute (delay(60000))
  }

  else if (numberOfTries == 0) // first time
  {
    Serial.println("!..Welcome..!");
    Serial.println("!..Please enter password to gain access..!");
  }

  else if (numberOfTries == 1) //first time after incorrect
  {
    Serial.println("!..You have 3 tries remaining..!");
  }

  else if (numberOfTries == 2) //second time after incorrect
  {
    Serial.println("!..You have 2 tries remaining..!");
  }

  else if (numberOfTries == 3) //third time after incorrect
  {
    Serial.println("!..You have 1 try remaining..!");
  }

  Serial.println("Please enter first digit..Waiting..");
  passwordStoreUser(0); //store first digit

  Serial.println("Please enter second digit..Waiting..");
  passwordStoreUser(1); //store second digit

  Serial.println("Please enter third digit..Waiting..");
  passwordStoreUser(2); //store third digit

  Serial.println("Please enter fourth digit..Waiting..");
  passwordStoreUser(3); //store fourth digit

  Serial.println("Please enter fifth digit..Waiting..");
  passwordStoreUser(4); //store fifth digit

  Serial.println("Please enter sixth digit..Waiting..");
  passwordStoreUser(5); //store sixth digit

  comparePassword(); // Compare both self password vs user password
}

void comparePassword()
{
  if (storedPassword[0] == userPassword[0]) //compare first digit
  {
    if (storedPassword[1] == userPassword[1]) //compare second digit
    {
      if (storedPassword[2] == userPassword[2]) //compare third digit
      {
        if (storedPassword[3] == userPassword[3]) //compare fourth digit
        {
          if (storedPassword[4] == userPassword[4]) //compare fifth digit
          {
            if (storedPassword[5] == userPassword[5]) //compare sixth digit
            {
              //!DONE!//
              Serial.println("!SUCCESS!");
              Serial.println("Password Accepted");
              successArduino();
            }
            else //sixth digit incorrect
            {
              numberOfTries++; //increment as incorrect password entered
              tryPassword();
            }
          }
          else // fifth digit incorrect
          {
            numberOfTries++; //increment as incorrect password entered
            tryPassword();
          }
        }
        else //fourth digit incorrect
        {
          numberOfTries++; //increment as incorrect password entered
          tryPassword();
        }
      }
      else //third digit incorrect
      {
        numberOfTries++; //increment as incorrect password entered
        tryPassword();
      }
    }
    else //second digit incorrect
    {
      numberOfTries++; //increment as incorrect password entered
      tryPassword();
    }
  }
  else //first digit incorrect
  {
    numberOfTries++; //increment as incorrect password entered
    tryPassword();
  }
}

void printStoredPassword()
{
  //verify the 4 digit password
  int i;
  Serial.println("Your Password is: ");
  for (i = 0; i < 6; i++)
  {
    Serial.println(storedPassword[i]);
    delay(250);
    Serial.println();
  }
}

void printUserPassword()
{
  //verify the 4 digit password
  int i;
  Serial.println("Your Password is: ");
  for (i = 0; i < 6; i++)
  {
    Serial.println(userPassword[i]);
    delay(250);
    Serial.println();
  }
}