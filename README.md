### 4x4-Matrix-Keypad-Arduino
#This is a simple yet flexible library for Arduino to interface with popular 4x4 matrix keypads. 

Arduino pins to connect a 4x4-Matrix-keypad are set using:
'void setKeypadPins(int row_1, int row_2, int row_3, int row_4, int col_1, int col_2, int col_3, int col_4)'

Key presses are scanned using:
'char scanKeyPress()'

Assigning user defined values to each key can be done by modifying:
'char keyMap(char key)'
