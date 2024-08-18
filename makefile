all: compile link

compile:
	g++ -Isrc/include -c main.cpp

link:
	g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

	g++ -Isrc/include -c main.cpp Player.cpp Dice.cpp Text.cpp Square.cpp
	g++ main.o Player.o Dice.o Text.o Square.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
	./main.exe

	g++ -Isrc/include -c main.cpp Player.cpp
	g++ -o main.exe main.cpp Player.cpp -lsfml-graphics -lsfml-window -lsfml-system
	./main.exe