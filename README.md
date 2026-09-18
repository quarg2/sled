# sled
A simple line editor written in C.

Allows opening files, and then editing them. Allows printing a file,
writing a line, editing a line, inserting a line, and getting a line count.

## Building

Clone/download this repository then run make

```
make
```

## Help

View HELP.md for command help

## Project structure

```
    /sled
    `-- src
        `-- commands.c
        `-- commands.h
        `-- errors.h
        `-- input.c
        `-- input.h
        `-- lineBuffer.c
        `-- lineBuffer.h
        `-- sled.c
        `-- sled.h
```