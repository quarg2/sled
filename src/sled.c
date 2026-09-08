#include "input.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        fprintf(stderr, "Supply file name.\n"
                        "Usage\n"
                        "sled FILE");
        return 0;
    }

    char inputBuffer[128];
    Input input;

    FILE *fp = fopen(argv[1], "r+");
    if (!fp)
    {
        return 74;
    }

    while ((input = getInput()) != INPUT_EXIT)
    {
        switch (input)
        {
        case INPUT_CAT:
            break;
        case INPUT_ADD_LINE:
            break;
        case INPUT_DELETE_LINE:
            break;
        case INPUT_EDIT_LINE:
            break;
        case INPUT_EXIT: // Unreachable
            break;
        default: // Unreachable
            goto outofloop;
        }
    }

outofloop:

    return 0;
}