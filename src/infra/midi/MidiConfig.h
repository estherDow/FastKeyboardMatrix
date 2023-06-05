#ifndef MIDICONFIG_H
#define MIDICONFIG_H

#include <Arduino.h>
#include <MIDI.h>


namespace midi_config
{
    MIDI_CREATE_DEFAULT_INSTANCE();
    void initMidi() {
        MIDI.begin(9);
    }
}

#endif