#include "Arduino.h"

//Called by scanKeyPress() function only to output characters
//User can re-assign new values to output different chars. e.g. Returning '$' when pressed 'A'
char keyMap(char key);

//Returns characters as per the pressed key.
//Returned characters are mapped in keyMap() function
//Returns '\0' if no key is pressed
char scanKeyPress();

//Pin 1 - 4 of keypad module connects to pin row_1 - row_4 of Arduino
//Pin 5 - 9 of keypad module connects to pin col_1 - col_4 of Arduino
void setKeypadPins(int row_1, int row_2, int row_3, int row_4, int col_1, int col_2, int col_3, int col_4);
