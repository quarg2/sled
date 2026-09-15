#ifndef SLED_INPUT_H
#define SLED_INPUT_H

typedef enum
{
    INPUT_CAT,         // c
    INPUT_ADD_LINE,    // a
    INPUT_DELETE_LINE, // d
    INPUT_EDIT_LINE,   // e
    INPUT_WORD_COUNT,  // w
    INPUT_EXIT,        // q
} Input;

Input getInput(void);

#endif