#include "lineBuffer.h"

#include "errors.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOCATE(type, size) (type *)malloc(sizeof(type) * (size))

LineBuffer initLineBuffer(void)
{
    return (LineBuffer){0, 0, NULL};
}

/**
 * Resize buffer if needed
 *
 * Args:
 * * LineBuffer \*buffer: buffer to be modified
 * Returns:
 * Returns int signifying success
 * * 0: Success
 * * -1: Call to `realloc()` failied. The buffer is not useable and accessing
 * `lines` is undefined
 */
static int resize(LineBuffer *buffer)
{
    if (buffer->count + 1 >= buffer->capacity)
    {
        buffer->capacity = (buffer->capacity == 0) ? 1 : buffer->capacity;
        buffer->lines = (char **)realloc(buffer->lines, (buffer->capacity * 2) * sizeof(char *));
        if (!buffer->lines)
        {
            return ALLOC_ERR;
        }
        buffer->capacity *= 2;
    }
    return NO_ERR;
}

/**
 * Inserts line at the end of the buffer
 *
 * Args:
 * - LineBuffer *buffer: line buffer to be modified
 * - char *str: String whose contents are copied to the destination
 */
int appendLineToBuffer(LineBuffer *buffer, char *str)
{
    if (resize(buffer) != NO_ERR)
    {
        return ALLOC_ERR;
    }

    buffer->lines[buffer->count] = ALLOCATE(char, strlen(str) + 1);
    strcpy(buffer->lines[buffer->count], str);
    buffer->count++;

    return NO_ERR;
}

/**
 * Adds line at the start of the buffer

 * Args:
 * * LineBuffer \*buffer: line buffer to be modified
 * * char \*str: String whose contents are copied to the destination
*/
int insertLineToBuffer(LineBuffer *buffer, char *str)
{
    char **temp;

    if (resize(buffer) != NO_ERR)
    {
        return ALLOC_ERR;
    }

    buffer->count++;
    temp = ALLOCATE(char *, buffer->count);
    if (!temp)
    {
        return STR_ALLOC_ERR;
    }

    // Shift contents of buffer
    memcpy((void *)temp, (void *)buffer->lines, (size_t)(buffer->count - 1) * sizeof(char *));
    memcpy((void *)(buffer->lines + 1), (void *)temp, (size_t)(buffer->count - 1) * sizeof(char *));
    buffer->lines[0] = ALLOCATE(char, strlen(str) + 1);

    if (!buffer->lines[0])
    {
        return ALLOC_ERR;
    }

    strcpy(buffer->lines[0], str);
    free(temp);

    return NO_ERR;
}

/**
 * Adds line to the buffer at a given position
 *
 * Args:
 * LineBuffer \*buffer: buffer to be modified
 * - char \*str: String to be copied into the destination
 * - size_t at: The position where it is supposed to be copied
 */
int insertLineToBufferAt(LineBuffer *buffer, char *str, size_t at)
{
    char **temp;

    if (resize(buffer) != NO_ERR)
    {
        return ALLOC_ERR;
    }

    if (at > buffer->count)
    {
        return BAD_INDEX;
    }

    temp = ALLOCATE(char *, buffer->count - at);

    if (!temp)
    {
        return STR_ALLOC_ERR;
    }

    // Shift elements that are after `at`
    memcpy((void *)temp, (void *)(buffer->lines + at), sizeof(char *) * (buffer->count - at));

    *(buffer->lines + at) = ALLOCATE(char, strlen(str) + 1);
    strcpy(buffer->lines[at], str);

    memcpy((void *)(buffer->lines + at + 1), (void *)temp, sizeof(char *) * (buffer->count - at));

    buffer->count++;
    free(temp);

    return NO_ERR;
}

/**
 * Frees the line buffer and the lines in it.
 * Resets the header
 *
 * Args:
 * LineBuffer \*buffer: Buffer to be freed
 */
void freeLineBuffer(LineBuffer *buffer)
{
    for (size_t i = 0; i < buffer->count; i++)
    {
        free(buffer->lines[i]);
    }
    free(buffer->lines);
    *buffer = initLineBuffer();
}

#undef ALLOCATE
