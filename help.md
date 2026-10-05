sled help
=========

sled is a small, interactive line editor for an existing text file. It loads
one file into memory, lets you inspect or change the in-memory lines, and can
write those changes back to the file.


Starting sled
-------------

Build the program from the project root:

    make

Run it with the name of an existing file:

    ./sled FILE

The file must already exist and be writable. sled opens it for reading and
writing; it does not create a missing file. If no file name is supplied, sled
prints its usage message and exits.


Command loop
------------

After startup, enter one command letter followed by Return. Commands are
single-letter commands; the extra characters on the line are ignored.

    c    Display the file currently on disk (cat)
    p    Print the in-memory buffer
    a    Add a line at a selected position
    d    Delete a line (recognized, not implemented yet)
    e    Edit a line (recognized, not implemented yet)
    s    Save the in-memory buffer to disk
    w    Count words (recognized, not implemented yet)
    q    Quit sled

Unknown command letters produce an error and return to the command loop.


Viewing content
---------------

Use `c` to read and display the file from disk. Use `p` to display sled's
current in-memory buffer. Both views number lines from 1 and display them as:

    line number | line text

The two commands can differ after you make changes: `p` shows edits that have
not been saved, while `c` shows the last saved contents on disk.


Adding a line
-------------

Enter `a`, then enter the position where the new line should be inserted, then
enter the complete line of text:

    a
    2
    A new line of text

The position is zero-based for insertion. A position of `0` inserts at the
beginning; entering the current line count appends to the end. The line is
stored with its newline, so pressing Return ends the inserted line.

If the position is outside the valid range, sled prints an error and asks for a
new position. Lines are limited to 1023 characters plus the terminating
newline.


Saving and quitting
-------------------

`s` writes the current in-memory buffer to the opened file. Saving is not
automatic. Use `p` to inspect the buffer before saving, then enter `s`.

`q` exits immediately and does not save pending changes. To keep edits, save
with `s` before quitting:

    p
    s
    q


Current implementation status
-----------------------------

The input layer recognizes `d`, `e`, and `w`, but the main command loop does
not currently perform those operations. They have no editing or reporting
effect yet. The implemented commands are `c`, `p`, `a`, `s`, and `q`.


Project layout
--------------

    makefile       Build and clean commands
    src/input.c    Command input handling
    src/commands.c File display, insertion, and saving operations
    src/lineBuffer.c In-memory line storage
    src/sled.c     Program entry point and command loop
