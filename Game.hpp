#ifndef GAME_HPP
#define GAME_HPP
#include <ncurses.h>
#include "Display.hpp"
#include "Draw.hpp"
using namespace std;

class Game{
    public:
    Display display;
    bool game_over;

    Game(int size){
        game_over = false;
        display = Display(size);
        display.initialise();
    }

    void processInput(){
        chtype input = display.getInput();

    }

    void updateState(){
        
    }

    void redraw(){
        display.refresh();
    }

    bool isOver(){
        return game_over;
    }



};
#endif