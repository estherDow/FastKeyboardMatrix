
#include <Arduino.h>

#include "application/KeyboardReader.h"
#include "infra/midi/MidiConfig.h"
using namespace keyboard_reader;
using namespace midi_config;



void setup()
{
  Serial.begin(9600);
  initPins();
  initMidi();
}

void loop()
{
  readKeys();
}