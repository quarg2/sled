#ifndef SLED_COMMANDS_H
#define SLED_COMMANDS_H

#include "lineBuffer.h"
#include <stdio.h>

void cat(FILE *fp);
void print(LineBuffer buffer);
void save(FILE *fp, LineBuffer buffer);
void addLine(LineBuffer *buffer);

#endif
