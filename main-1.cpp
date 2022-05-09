#include <iostream>
#include <string>
#include <ncurses.h>
#include "Display.hpp"
#include "Game.hpp"

using namespace std;

int main(){
    initscr();
    refresh();

    Game game(20,40);

    while (!game.isOver()){
        game.processInput();
        game.updateState();
        game.redraw();
    }

    // getch();
    endwin();

    return 0;
}