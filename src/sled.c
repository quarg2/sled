#include "sled.h"

#include "input.h"
#include "lineBuffer.h"

#include <stdio.h>

static int readFile(FILE *fp, LineBuffer *buffer);

int main(int argc, char *argv[])
{
    Input input;
    FILE *fp;
    LineBuffer buffer;

    if (argc == 1)
    {
        fprintf(stderr, "Supply file name.\n"
                        "Usage\n"
                        "sled FILE");
        return 64;
    }

    fp = fopen(argv[1], "r+");
    if (!fp)
    {
        fprintf(stderr, "Error with opening file.");
        return 74;
    }

    readFile(fp, &buffer);

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
            goto outofloop;
        default: // Unreachable
            goto outofloop;
        }
    }

outofloop:

    return 0;
}

static int readFile(FILE *fp, LineBuffer *buffer)
{
    char line[LINE_BUFFER_SIZE];

    while (fgets(line, LINE_BUFFER_SIZE, fp))
    {
        appendLineToBuffer(buffer, line);
    }
    fseek(fp, 0, SEEK_SET);
}