#include "commands.h"
#include <stdio.h>

void cat(FILE *fp) {
    int lineNum = 1;
    char buffer[4096];

    while (fgets(buffer, sizeof(buffer), fp)) {
        fpintf(stdout, "%d | %s", lineNum, buffer);
        lineNum++;
    }
}