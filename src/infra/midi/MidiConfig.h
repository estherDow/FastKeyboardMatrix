#ifndef MIDICONFIG_H
#define MIDICONFIG_H

#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32_NimBLE.h>

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <AppleMIDI.h>

namespace ble_midi_config
{
    BLEMIDI_CREATE_INSTANCE("CustomName", MIDI)
    void initMidi()
    {
        MIDI.begin();
    }
}

namespace rtc_midi_config
{
    byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
    char ssid[] = "vodafoneBA1234"; //  your network SSID (name)
    char pass[] = "nattoteamo.";     // your network password (use for WPA, or use as key for WEP)
    unsigned long t0 = millis();
    int8_t isConnected = 0;

    APPLEMIDI_CREATE_DEFAULTSESSION_INSTANCE();

    void initMidi()
    {
        AM_DBG_SETUP(115200);
        Serial.println("Booting");

        WiFi.begin(ssid, pass);

        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
            Serial.println("Establishing connection to WiFi..");
        }

        MIDI.begin();
    }
}

#endif