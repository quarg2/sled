CFLAGS = -std=c11

default: all

debug: CFLAGS += -Wall -Wextra -pedantic -g -O0

debug: all

all: sled

sled: input.o lineBuffer.o sled.o commands.o
	$(CC) $(CFLAGS) input.o lineBuffer.o sled.o commands.o -o sled

input.o: src/input.c src/input.h
	$(CC) $(CFLAGS) -c ./src/input.c -o input.o

lineBuffer.o: src/lineBuffer.c src/lineBuffer.h src/errors.h
	$(CC) $(CFLAGS) -c ./src/lineBuffer.c -o lineBuffer.o

sled.o: src/sled.c src/sled.h src/commands.h src/lineBuffer.h src/input.h
	$(CC) $(CFLAGS) -c ./src/sled.c -o sled.o

commands.o: src/commands.c src/commands.h src/lineBuffer.h src/sled.h
	$(CC) $(CFLAGS) -c ./src/commands.c -o commands.o

.PHONY: clean

clean:
	rm -rf sled.o input.o lineBuffer.o commands.o sled
