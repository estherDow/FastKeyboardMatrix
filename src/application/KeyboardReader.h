#ifndef KEYBOARDREADER_H
#define KEYBOARDREADER_H
#include <MIDI.h>
#include <infra/keyboard/KeyboardConfig.h>
#include <infra/keyboard/KeyboardDriver.h>
#include <infra/midi/MidiClient.h>
#include <application/Key.h>
using namespace keyboard_config;
using namespace midi_client;
using namespace key;
using namespace keyboard_driver;

namespace keyboard_reader
{
    void sendMessageByState(KeyData keyData)
    {
        switch (keyData.state)
        {

        case PRESS:
            sendNoteOn(keyData.note, keyData.velocity, keyData.channel);
            Serial.println("ROESS");
            break;
        case HOLD:
            sendAftertouch(keyData.note, keyData.velocity, keyData.channel);
            Serial.println("HOLD");

            break;
        case RELEASE:
            sendNoteOff(keyData.note, keyData.velocity, keyData.channel);
            Serial.println("RELEASEww");

            break;
        case IDLE:
            break;
        }
    }

    void readKeys()
    {
        for (int i = 0; i < 24; i++)
        {
            byte signal = readChannel(i);
            Serial.println(signal);
            if (signal > 50)
            {
                sendMessageByState(keys[i].press(signal));
            }
            else
            {
                sendMessageByState(keys[i].release());
            }
        }
    }
}

#endif