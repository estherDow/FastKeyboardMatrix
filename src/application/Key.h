#ifndef KEY_H
#define KEY_H
#include <Arduino.h>
namespace key
{
    enum KeyStates
    {
        PRESS,
        HOLD,
        RELEASE,
        IDLE
    };

    struct KeyData
    {
        KeyStates state;
        byte note;
        byte channel;
        byte velocity;
        KeyData(KeyStates state, byte note, byte channel, byte velocity)
        {
            this->state = state;
            this->note = note;
            this->channel = channel;
            this->velocity = velocity;
        }
    };

    class Key
    {
        public:
        byte note;
        int channel;
        KeyStates state;

        Key(byte note, byte channel)
        {
            this->note = note;
            this->channel = channel;
            this->state = IDLE;
        }

        KeyData press(byte velocity)
        {

            switch (this->state)
            {
            case IDLE:
                this->state = PRESS;
                break;

            case PRESS:
                this->state = HOLD;
                break;

            case HOLD: default:
                break;
            }
            return KeyData(this->state, this->note, this->channel, velocity);
        }

        KeyData release()
        {
        switch (this->state) 
        {
            case HOLD: case PRESS:
                this->state = RELEASE;
                break;
            case RELEASE:
                this->state = IDLE;
                break;
            case IDLE: default:
                break;
        }
        
        return KeyData(this->state, this->note, this->channel, 0); 
    };

    };
}

#endif