CC=g++
CFLAGS=-Wall -g -o
LLIB=-lsfml-system -lsfml-graphics -lsfml-window
SOURCE=src/*.cpp src/gui/rewrite/*.cpp
HEADER=src/header/*.hpp src/gui/rewrite/header/*.hpp
all:
	$(CC) $(SOURCE) $(LLIB) $(CFLAGS) main

clean:
	rm main

gitupdatecode:

	git add $(SOURCE) $(HEADER) makefile
	git commit
	git push
