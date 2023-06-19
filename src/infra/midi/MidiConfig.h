#ifndef MIDICONFIG_H
#define MIDICONFIG_H

#include <Arduino.h>
#include <MIDI.h>


namespace midi_config
{
    MIDI_CREATE_DEFAULT_INSTANCE();
    //MIDI_CREATE_INSTANCE(TinyDebugSerial, Serial,  MIDI);
    void initMidi() {
        MIDI.begin(9);
    }
}

#endif