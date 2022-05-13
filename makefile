all: main

main: main-1.cpp RunGame.hpp Display.hpp Game.hpp Draw.hpp Ship.hpp Enemy.hpp Laser.hpp
	g++ main-1.cpp -lncurses -o main

playertest: PlayerTest.cpp Player.hpp
	g++ PlayerTest.cpp -lncurses -o playertest

drawtest: Draw.hpp DrawTest.cpp
	g++ DrawTest.cpp -lncurses -o drawtest