#ifndef KEYBOARDREADER_H
#define KEYBOARDREADER_H
#include <MIDI.h>
#include <infra/keyboard/KeyboardConfig.h>
#include <application/KeyMapper.h>
#include <infra/midi/MidiClient.h>
using namespace keyboard_config;
using namespace key_mapper;
using namespace midi_client;

namespace keyboard_reader
{
    void sendMessageByState(KeyState kstate, int note, int channel)
    {
        switch (kstate)
        {

        case PRESSED:
            sendNoteOn(note, 100, channel);
            break;
        case HOLD:
            sendNoteOn(note, 60, channel);

            break;
        case RELEASED:
            sendNoteOff(note, 0, channel);
            break;
        case IDLE:
            break;
        }
    }

    void parseKeys()
    {
        for (int i = 0; i < LIST_MAX; i++)
        {
            if (kpd.key[i].stateChanged)
            {
                KeyState kstate = kpd.key[i].kstate;
                int channel = mapKeyToChannel(kpd.key[i].kchar);
                int note = mapKeyToNote(kpd.key[i].kchar);
                sendMessageByState(kstate, note, channel);
            }
        }
    }

    void readKeys()
    {
        if (kpd.getKeys())
        {
            parseKeys();
        }
    }
}

#endif