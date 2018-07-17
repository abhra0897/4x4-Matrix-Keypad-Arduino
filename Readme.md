# 4x4-Matrix-Keypad-Arduino


######  This is a very simple yet flexible library for Arduino to interface with popular 4x4 matrix keypads. The library uses NO delay() function.

Arduino pins to connect a 4x4-Matrix-keypad are set using:

> `void setKeypadPins(int row_1, int row_2, int row_3, int row_4, int col_1, int col_2, int col_3, int col_4)`

example: `void setKeypadPins(5, 6, 7, 2, 10, 12, 9, 8)`

Pin 1 - 4 (L -> R) of the keypad module connects to the Pin `row_1 - row_4` of Arduino.

Pin 5 - 9 of the keypad module connects to the Pin `col_1 - col_4` of Arduino.

Key presses are scanned using:

> `char scanKeyPress()`

This function should be called in loop without using `delay()` to get key presses.

Assigning user defined values to each key can be done by modifying:

> `char keyMap(char key)`

