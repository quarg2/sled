#ifndef SLED_LINEBUFFER_H
#define SLED_LINEBUFFER_H

#include <stdlib.h>

typedef struct
{
    size_t count;
    size_t capacity;
    char **lines;
} LineBuffer;

LineBuffer initLineBuffer(void);
int appendLineToBuffer(LineBuffer *, char *);
int insertLineToBuffer(LineBuffer *, char *);
int insertLineToBufferAt(LineBuffer *, char *, size_t);
int removeLineFromBuffer(LineBuffer *, size_t);
void freeLineBuffer(LineBuffer *);

#endif
