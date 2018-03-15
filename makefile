CC=g++
CFLAGS = -l SDL2 -l SDL2_image -l SDL2_mixer

all: programa
	./jogo.out

programa: main.o Game.o State.o Sprite.o Music.o
	$(CC) main.o Game.o Sprite.o State.o Music.o $(CFLAGS) -o jogo.out

main.o: main.cpp
	$(CC) -c main.cpp

Game.o: Game.h Game.cpp
	$(CC) -c Game.cpp

State.o: State.h State.cpp Game.h
	$(CC) -c State.cpp

Sprite.o: Sprite.h Sprite.cpp Game.h
	$(CC) -c Sprite.cpp

Music.o: Music.h Music.cpp Game.h
	$(CC) -c Music.cpp

clean:
	rm *.o

iniciante:
	g++ *.cpp -o prog -std=c++11 $(CFLAGS)

.PHONY: programa run
