default: all

all: sled

sled: input.o lineBuffer.o sled.o
	gcc input.o lineBuffer.o sled.o -o sled

input.o:
	gcc -S ./src/input.c -o input.o

lineBuffer.o: sled.o
	gcc -S ./src/lineBuffer.c -o lineBuffer.o

sled.o: input.o
	gcc -S ./src/sled.c -o sled.o