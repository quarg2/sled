#include "input.h"
#include <stdbool.h>
#include <stdio.h>

Input getInput(void)
{
    int c;

    while (true)
    {
        switch (c = getchar())
        {
        case 'c':
            getchar();
            return INPUT_CAT;
        case 'p':
            getchar();
            return INPUT_PRINT;
        case 'a':
            getchar();
            return INPUT_ADD_LINE;
        case 'd':
            getchar();
            return INPUT_DELETE_LINE;
        case 'e':
            getchar();
            return INPUT_EDIT_LINE;
        case 's':
            getchar();
            return INPUT_SAVE;
        case 'w':
            getchar();
            return INPUT_WORD_COUNT;
        case 'q':
            getchar();
            return INPUT_EXIT;
        default:
            getchar();
            fprintf(stderr, "Invalid input: %c\n", c);
            break;
        }
    }
}
