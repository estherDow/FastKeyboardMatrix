#include <Arduino.h>

#include "application/KeyboardReader.h"
#include "infra/midi/MidiConfig.h"
using namespace keyboard_reader;
using namespace rtc_midi_config;



void setup()
{
  Serial.begin(115200);
  initMidi();
}

void loop()
{
  readKeys();
}
