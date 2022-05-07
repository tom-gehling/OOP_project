all: main

main: main.cpp Display.hpp Game.hpp Draw.hpp
	g++ main.cpp -lncurses -o main