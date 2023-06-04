#ifndef KEYBOARDCONFIG_H
#define KEYBOARDCONFIG_H
#include <Keypad.h>

namespace keyboard_config
{
    const byte ROWS = 4;
    const byte COLS = 6;

    char hexaKeys[ROWS][COLS] = {
        {'0', '1', '2', '3', '4', '5'},
        {'6', '7', '8', '9', 'A', 'B'},
        {'C', 'D', 'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'L', 'M', 'N'}};
    byte rowPins[ROWS] = {13, 14, 15, 16};
    byte colPins[COLS] = {17, 18, 19, 21, 22, 23};

    Keypad kpd = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
}
#endif