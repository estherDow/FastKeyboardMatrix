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
            return 0;
        case '6':
        case '7':
        case '8':
        case '9':
        case 'A':
        case 'B':
            return 1;
        case 'C':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
            return 2;
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
            return 3;
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
        case '3':
        case '4':
        case '5':
            return 0;
        case '7':
        case '1':
        case '8':
        case '9':
        case 'A':
        case 'B':
            return 1;
        case '2':
        case 'D':
        case 'E':
        case 'F':
        case 'G':
        case 'H':
            return 2;
        case 'I':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
            return 3;
        default:
            return -1;
        }
    }
}

#endif