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
            return INPUT_CAT;
        case 'a':
            return INPUT_ADD_LINE;
        case 'd':
            return INPUT_DELETE_LINE;
        case 'e':
            return INPUT_EDIT_LINE;
        case 'q':
            return INPUT_EXIT;
        default:
            fprintf(stderr, "Invalid input: %c\n", c);
            break;
        }
    }
}
