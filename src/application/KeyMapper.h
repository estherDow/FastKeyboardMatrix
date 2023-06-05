#ifndef KEYMAPPER_H
#define KEYMAPPER_H

// maps keys to midi messages
namespace key_mapper
{
    int mapKeyToChannel(char key)
    {
        switch (key)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            return 1;
        case '6':
        case '7':
        case '8':
        case '9':
        case 'A':
        case 'B':
            return 2;
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
            return 3;
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
            return 4;
        default:
            return -1;
        }
    }

    int mapKeyToNote(char key)
    {
        switch (key)
        {
        case '0':
        case '6':
        case 'C':
        case 'I':
            return 10;
        case '1':
        case '7':
        case 'D':
        case 'J':
            return 20;
        case '2':
        case '8':
        case 'E':
        case 'K':
            return 30;
        case '3':
        case '9':
        case 'F':
        case 'L':
            return 40;
        case '4':
        case 'A':
        case 'G':
        case 'M':
            return 50;
        case '5':
        case 'B':
        case 'H':
        case 'N':
            return 60;

        default:
            return -1;
        }
    }
}

#endif