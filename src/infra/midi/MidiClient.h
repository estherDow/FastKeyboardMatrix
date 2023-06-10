#ifndef MIDICLIENT_H
#define MIDICLIENT_H
#include <infra/midi/MidiConfig.h>

using namespace midi_config;

namespace midi_client
{
    void sendNoteOn(byte note, byte velocity, byte channel) {
        MIDI.sendNoteOn(note, velocity, channel);
    }

    void sendAftertouch(byte note, byte pressure, byte channel) {
        MIDI.sendAfterTouch(note, pressure, channel);
    }

    void sendNoteOff(byte note, byte velocity, byte channel) {
        MIDI.sendNoteOff(note, velocity, channel);
    }
}
#endif