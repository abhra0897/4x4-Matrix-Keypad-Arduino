#include "keyScan.h"

const long timeOffset = 300; //Key debounce time in ms. No keypress is registered within this period since the last press
int rowPin_1, rowPin_2, rowPin_3, rowPin_4;
int colPin_1, colPin_2, colPin_3, colPin_4;

//Called by scanKeyPress() function only to output characters
//User can re-assign new values to output different chars. e.g. Returning '$' when pressed 'A'
char keyMap(char key)
{
    char val;
    switch (key)
    {
        case '1':
           val = '1';
           break;
        case '2':
            val = '2';
            break;
        case '3':
            val = '3';
            break;
        case 'A':
            val = 'A';
            break;
        
        case '4':
           val = '4';
           break;
        case '5':
            val = '5';
            break;
        case '6':
            val = '6';
            break;
        case 'B':
            val = 'B';
            break; 
        
        case '7':
           val = '7';
           break;
        case '8':
            val = '8';
            break;
        case '9':
            val = '9';
            break;
        case 'C':
            val = 'C';
            break;

        case '*':
           val = '.';   //originally *
           break;
        case '0':
            val = '0';
            break;
        case '#':
            val = '#';
            break;
        case 'D':
            val = 'D';
            break;

        default:
            Serial.println("Unmatched");
    }
    return val;
}

//Returns characters as per the pressed key.
//Returned characters are mapped in keyMap() function
//Returns '\0' if no key is pressed
char scanKeyPress()
{
    char pressedKey;
    static long now = 0;       //'now' is a local var but it will keep its last value between function calls
    long repeatTime = millis() - now;        //Key debounce wait time

    ///*********************************   ROW 1   ********************************************///
    
    digitalWrite(rowPin_1, 0);            //Make the row LOW and scan coloums one by one.
    
    //Scan coloumn 1
    if(!digitalRead(colPin_1) && repeatTime > timeOffset) //Accept new keypress only if a certain amount of time is elapsed
    {
        pressedKey = '1';     //Assign original key values
        now = millis();
    }
    
    //Scan coloumn 2
    else if(!digitalRead(colPin_2) && repeatTime > timeOffset) 
    {
        pressedKey = '2';
        now = millis();
    }

    //Scan coloumn 3
    else if(!digitalRead(colPin_3) && repeatTime > timeOffset) 
    {
        pressedKey = '3';
        now = millis();
    }

    //Scan coloumn 4
    else if(!digitalRead(colPin_4) && repeatTime > timeOffset) 
    {
        pressedKey = 'A';
        now = millis();
    }

    //If no key press is detected, default pressedKey val is '\0'
    else
        pressedKey = '\0';

    digitalWrite(rowPin_1, 1);    //Make the row pin HIGH after all coloums are scanned

    if(pressedKey != '\0')
        return keyMap(pressedKey);
    
    ///*****************************************   ROW 2   *******************************************///

    digitalWrite(rowPin_2, 0);            //Make the row 2 LOW and scan coloums one by one.
    
    //Scan coloumn 1
    if(!digitalRead(colPin_1) && repeatTime > timeOffset) //Accept new keypress only if a certain amount of time is elapsed
    {
        pressedKey = '4';     //Assign original key values
        now = millis();
    }
    
    //Scan coloumn 2
    else if(!digitalRead(colPin_2) && repeatTime > timeOffset) 
    {
        pressedKey = '5';
        now = millis();
    }

    //Scan coloumn 3
    else if(!digitalRead(colPin_3) && repeatTime > timeOffset) 
    {
        pressedKey = '6';
        now = millis();
    }

    //Scan coloumn 4
    else if(!digitalRead(colPin_4) && repeatTime > timeOffset) 
    {
        pressedKey = 'B';
        now = millis();
    }

    //If no key press is detected, default pressedKey val is '\0'
    else
        pressedKey = '\0';
    
    digitalWrite(rowPin_2, 1);    //Make the row pin HIGH after all coloums are scanned

    if(pressedKey != '\0')
        return keyMap(pressedKey);
    
    ///*****************************************   ROW 3   *******************************************///

    digitalWrite(rowPin_3, 0);            //Make the row 3 LOW and scan coloums one by one.
    
    //Scan coloumn 1
    if(!digitalRead(colPin_1) && repeatTime > timeOffset) //Accept new keypress only if a certain amount of time is elapsed
    {
        pressedKey = '7';     //Assign original key values
        now = millis();
    }
    
    //Scan coloumn 2
    else if(!digitalRead(colPin_2) && repeatTime > timeOffset) 
    {
        pressedKey = '8';
        now = millis();
    }

    //Scan coloumn 3
    else if(!digitalRead(colPin_3) && repeatTime > timeOffset) 
    {
        pressedKey = '9';
        now = millis();
    }

    //Scan coloumn 4
    else if(!digitalRead(colPin_4) && repeatTime > timeOffset) 
    {
        pressedKey = 'C';
        now = millis();
    }

    //If no key press is detected, default pressedKey val is '\0'
    else
        pressedKey = '\0';

    digitalWrite(rowPin_3, 1);    //Make the row pin HIGH after all coloums are scanned

    if(pressedKey != '\0')
        return keyMap(pressedKey);
    
    ///*****************************************   ROW 4   *******************************************///

    digitalWrite(rowPin_4, 0);            //Make the row 4 LOW and scan coloums one by one.
    
    //Scan coloumn 1
    if(!digitalRead(colPin_1) && repeatTime > timeOffset) //Accept new keypress only if a certain amount of time is elapsed
    {
        pressedKey = '*';         //Assign original key values
        now = millis();
    }
    
    //Scan coloumn 2
    else if(!digitalRead(colPin_2) && repeatTime > timeOffset) 
    {
        pressedKey = '0';
        now = millis();
    }

    //Scan coloumn 3
    else if(!digitalRead(colPin_3) && repeatTime > timeOffset) 
    {
        pressedKey = '#';
        now = millis();
    }

    //Scan coloumn 4
    else if(!digitalRead(colPin_4) && repeatTime > timeOffset) 
    {
        pressedKey = 'D';
        now = millis();
    }

    //If no key press is detected, default pressedKey val is '\0'
    else
        pressedKey = '\0';

    digitalWrite(rowPin_4, 1);    //Make the row pin HIGH after all coloums are scanned

    if(pressedKey != '\0')
        return keyMap(pressedKey);

    ///************************************************************************************///

    return pressedKey;         //If no key is pressed, return '\0'
}

//Pin 1 - 4 of keypad module connects to pin row_1 - row_4 of Arduino
//Pin 5 - 9 of keypad module connects to pin col_1 - col_4 of Arduino
void setKeypadPins(int row_1, int row_2, int row_3, int row_4, int col_1, int col_2, int col_3, int col_4)
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
    rowPin_1 = row_1;
    rowPin_2 = row_2;
    rowPin_3 = row_3;
    rowPin_4 = row_4;

    colPin_1 = col_1;
    colPin_2 = col_2;
    colPin_3 = col_3;
    colPin_4 = col_4;
    
     //Row keys. OUTPUT & HIGH by default
    pinMode(rowPin_1, 1);
    pinMode(rowPin_2, 1);
    pinMode(rowPin_3, 1);
    pinMode(rowPin_4, 1);

    //Row keyes are set HIGH
    digitalWrite(rowPin_1, 1);
    digitalWrite(rowPin_2, 1);
    digitalWrite(rowPin_3, 1);
    digitalWrite(rowPin_4, 1);
    
    //Coloumn keys. Input pullup enabled
    pinMode(colPin_1, INPUT_PULLUP);
    pinMode(colPin_2, INPUT_PULLUP);
    pinMode(colPin_3, INPUT_PULLUP);
    pinMode(colPin_4, INPUT_PULLUP);
}