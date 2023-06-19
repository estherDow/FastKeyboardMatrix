#ifndef KEYBOARDDRIVER_H
#define KEYBOARDDRIVER_H
#include <Arduino.h>
#include <application/Key.h>
#include <infra/keyboard/KeyboardConfig.h>

using namespace key;
using namespace keyboard_config;
namespace keyboard_driver
{

    int muxChannel[12][4] = {
        {0, 0, 0, 0}, // channel 0
        {1, 0, 0, 0}, // channel 1
        {0, 1, 0, 0}, // channel 2
        {1, 1, 0, 0}, // channel 3
        {0, 0, 1, 0}, // channel 4
        {1, 0, 1, 0}, // channel 5
        {0, 1, 1, 0}, // channel 6
        {1, 1, 1, 0}, // channel 7
        {0, 0, 0, 1}, // channel 8
        {1, 0, 0, 1}, // channel 9
        {0, 1, 0, 1}, // channel 10
        {1, 1, 0, 1}, // channel 11
    };

    void initPins()
    {
        for (byte pin : dataPins)
        {
            pinMode(pin, OUTPUT);
            digitalWrite(pin, LOW);
        }
        pinMode(signalPin, INPUT);

        pinMode(enableMatrix0, OUTPUT);
        pinMode(enableMatrix1, OUTPUT);
        digitalWrite(enableMatrix0, HIGH);
        digitalWrite(enableMatrix1, HIGH);
    }

    byte readChannel(byte number)
    {
        byte channel = number;
        if (number < 12)
        {
            digitalWrite(enableMatrix0, LOW);
            digitalWrite(enableMatrix1, HIGH);
        }
        else {
            channel = number - 12;
            digitalWrite(enableMatrix0, HIGH);
            digitalWrite(enableMatrix1, LOW);
        }

        for (int i = 0; i < 4; i++)
        {
            digitalWrite(dataPins[i], muxChannel[channel][i]);
        }
        return map(analogRead(signalPin), 0, 1023, 0, 127);
    }

}
#endif