#ifndef KEYBOARDCONFIG_H
#define KEYBOARDCONFIG_H

#include <application/Key.h>
using namespace key;

namespace keyboard_config
{
    const byte enableMatrix0 = 10;
    const byte enableMatrix1 = 16;

    const byte dataPins[] = {9,8,7,6};

    const byte signalPin = 21;

        Key keys[24] = {
        Key(10, 1),
        Key(20, 1),
        Key(30, 1),
        Key(40, 1),
        Key(50, 1),
        Key(60, 1),
        Key(10, 2),
        Key(20, 2),
        Key(30, 2),
        Key(40, 2),
        Key(50, 2),
        Key(60, 2),
        Key(10, 3),
        Key(20, 3),
        Key(30, 3),
        Key(40, 3),
        Key(50, 3),
        Key(60, 3),
        Key(10, 4),
        Key(20, 4),
        Key(30, 4),
        Key(40, 4),
        Key(50, 4),
        Key(60, 4),
    };
}
#endif