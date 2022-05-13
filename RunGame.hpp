#ifndef RUNGAME_HPP
#define RUNGAME_HPP
#include "Game.hpp"

using namespace std;

class RunGame{
    public:
    RunGame(int height, int width){

        initscr();
        refresh();

        Game game(height, width);

        while (!game.gameOver()){
        game.processInput();
        game.updateState();
        game.redraw();
        }

        getch();
        endwin();
        
    }

};
#endif