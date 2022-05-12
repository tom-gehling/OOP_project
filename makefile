all: main

main: main-1.cpp Display.hpp Game.hpp Draw.hpp Ship.hpp Enemy.hpp Laser.hpp
	g++ main-1.cpp -lncurses -o main