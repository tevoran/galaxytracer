CC=g++
CFLAGS=-Wall -g -o
LLIB=-lsfml-system -lsfml-graphics -lsfml-window
SOURCE=src/*.cpp src/gui/*.cpp
all:
	$(CC) $(SOURCE) $(LLIB) $(CFLAGS) main

clean:
	rm main
