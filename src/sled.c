#include "sled.h"

#include "commands.h"
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
        fputs("Error with opening file.\n", stderr);
        return 74;
    }

    readFile(fp, &buffer);

    while ((input = getInput()) != INPUT_EXIT)
    {
        switch (input)
        {
        case INPUT_CAT:
            cat(fp);
            break;
        case INPUT_PRINT:
            print(buffer);
            break;
        case INPUT_ADD_LINE:
            addLine(&buffer);
            break;
        case INPUT_DELETE_LINE:
            break;
        case INPUT_EDIT_LINE:
            break;
        case INPUT_SAVE:
            save(fp, buffer);
            break;
        case INPUT_WORD_COUNT:
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

    return 0;
}