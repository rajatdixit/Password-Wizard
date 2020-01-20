#include "Arduino.h"
#include "remoteFunctions.h"
///-----------------------Includes--------------------------------------///
#include "IRremote.h"
///-----------------------Variable Definitions--------------------------///
#define RECV_PIN 12
IRrecv irrecv(RECV_PIN);
decode_results results;
long unsigned int value;

void initializeRemote()
{
    Serial.println("Enabling IR Remote..");
    irrecv.enableIRIn();
    delay(500);
    Serial.println("Done");
}

void waitForInput()
{
    delay(1000);
    while (!(irrecv.decode(&results)))
    {
        //keep waiting
    }
}

long unsigned int inputReceived()
{
    Serial.println("Digit received");
    return results.value;
}

void resumeRemote()
{
    delay(500);
    irrecv.resume(); // Receive the next value
    delay(500);
}