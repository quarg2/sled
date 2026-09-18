#include "commands.h"

#include "sled.h"

#include <stdbool.h>
#include <stdio.h>

void cat(FILE *fp)
{
    int lineNum = 1;
    char buffer[LINE_BUFFER_SIZE];

    while (fgets(buffer, sizeof(buffer), fp))
    {
        fprintf(stdout, "%d | %s", lineNum, buffer);
        lineNum++;
    }

    fseek(fp, 0, SEEK_SET);
}

void print(LineBuffer buffer)
{
    for (size_t i = 0; i < buffer.count; i++)
    {
        printf("%zu | %s", i + 1, buffer.lines[i]);
    }
}

void save(FILE *fp, LineBuffer buffer)
{
    freopen(NULL, "w", fp);
    for (size_t i = 0; i < buffer.count; i++)
    {
        fprintf(fp, "%s", buffer.lines[i]);
    }
    fflush(fp);
    freopen(NULL, "r+", fp);
}

void addLine(LineBuffer *buffer)
{
    size_t at;
    char line[LINE_BUFFER_SIZE];
    char pos[INPUT_BUFFER_SIZE];

    while (true)
    {
        fgets(pos, INPUT_BUFFER_SIZE, stdin);
        if (sscanf(pos, " %zu", &at) != 1)
        {
            fputs("Err: Enter line number to insert line in.\n", stderr);
        }
        else
        {
            if (at > buffer->count)
            {
                fputs("Err: Enter valid line number within bounds.\n", stderr);
                fprintf(stderr, "Cannot be more than %zu.\n", buffer->count);
            }
            else
            {
                break;
            }
        }
    }
    fgets(line, LINE_BUFFER_SIZE, stdin);
    if (at == buffer->count)
    {
        appendLineToBuffer(buffer, line);
    }
    else
    {
        insertLineToBufferAt(buffer, line, at);
    }
}

void deleteLine(LineBuffer *buffer)
{
    size_t at;
    char pos[INPUT_BUFFER_SIZE];

    while (true)
    {
        fgets(pos, INPUT_BUFFER_SIZE, stdin);
        if (sscanf(pos, " %zu", &at) != 1)
        {
            fputs("Err: Enter line number to delete line.\n", stderr);
        }
        else
        {
            if (at > buffer->count)
            {
                fputs("Err: Enter valid line number within bounds.\n", stderr);
                fprintf(stderr, "Cannot be more than %zu.\n", buffer->count);
            }
            else
            {
                break;
            }
        }
    }

    removeLineFromBuffer(buffer, at);
}