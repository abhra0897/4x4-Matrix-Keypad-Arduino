#include <Arduino.h>
#include "keyScan.h"

#define ENTER 'D'
#define CANCEL 'C'
#define INCREMENT 'A'
#define DECREMENT 'B'
#define ZERO '#'

char keypadInputChar[50] = "";
float keypadInputFloat = 0.0;
int counter = 0;


void setup() 
{
    Serial.begin(9600);
    setKeypadPins(2, 3, 4, 5, 6, 7, 8, 9);    
}

void loop() 
{
    char keyVal = scanKeyPress();

    //if pressed key is not '\0', i.e key press is detected,
    //do whatever you want with the returned value.
    if(keyVal != '\0')
    {
        if(keyVal != INCREMENT && keyVal != DECREMENT && keyVal != CANCEL && keyVal != ENTER && keyVal != ZERO)
        {
            keypadInputChar[counter] = keyVal;  //Form a string by appending characters
            counter++;  //Increment the array index
            Serial.print(keyVal);
        }
            
        if(keyVal == ENTER)          //set the value as float from char
        {
            if(strlen(keypadInputChar) > 0)    //Set new value to float var only if the string is non zero. else prev. val stays
                keypadInputFloat = atof(keypadInputChar);
            Serial.println();
            Serial.println(keypadInputFloat);
            counter = 0;
            memset(keypadInputChar, 0, strlen(keypadInputChar));
        }
        else if(keyVal == CANCEL)      //Sets the char input var to null but keeps the float input var untouched
        {
            counter = 0;
            memset(keypadInputChar, 0, strlen(keypadInputChar));
            Serial.println();
        }
        else if(keyVal == INCREMENT)      //Increments the last val of float input var by 1.0
        {
            counter = 0;
            memset(keypadInputChar, 0, strlen(keypadInputChar));   //sets char input var to null first
            keypadInputFloat++;
            Serial.println(keypadInputFloat);
        }
        else if(keyVal == DECREMENT)     //Decrements the ... ^^^^^
        {
            counter = 0;
            memset(keypadInputChar, 0, strlen(keypadInputChar));  ////sets char input var to null first
            keypadInputFloat--;
            if(keypadInputFloat < 0.0)   //if goes negative,
                keypadInputFloat = 0.0;  //make it 0.0
            Serial.println(keypadInputFloat);
        }
        else if(keyVal == ZERO)         //Perform CANCEL operation and also sets the float input var to 0.0
        {
            counter = 0;
            memset(keypadInputChar, 0, strlen(keypadInputChar));
            keypadInputFloat = 0.0;
            Serial.println(keypadInputFloat);
        }
    }    
}
