#ifndef RUNGAME_HPP
#define RUNGAME_HPP
#include "Game.hpp"
#include "PauseQuitMenu.hpp"
#include <iostream>

using namespace std;

#define START       3
#define RESTART     2
#define PAUSE_GAME  1
#define QUIT_GAME   0
#define ENTER       10 // ascii value of 'Enter' letter

class RunGame{
    public:
        RunGame(int height, int width){

            initscr();
            refresh();

            /* Initiate start menu */
            Menu open_menu;
            bool start_flag = false;

            start_flag = open_menu.operate(START); // run the start menu

            Game game(height, width);
            while (start_flag) { // game can be started

                while (!game.gamePaused()){
                    game.processInput();
                    game.updateState();
                    game.redraw();
                }
                Menu ingame_menu;
                start_flag = ingame_menu.operate(PAUSE_GAME);
                game.unPause();
            }

            getch();
            endwin();
            system("clear");
        }
};
#endif