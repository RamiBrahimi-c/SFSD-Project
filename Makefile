all:
	gcc file.c main.c secondMem.c -o main -lSDL2 -lSDL2_ttf && ./main