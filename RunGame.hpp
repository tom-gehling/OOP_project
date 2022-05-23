#ifndef RUNGAME_HPP
#define RUNGAME_HPP
#include "Game.hpp"
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

            /* Initiate start menu */
            // Menu open_menu; 
            // bool start_flag = false;

            // start_flag = open_menu.operate(START); // run the start menu

            // if (start_flag) {
                Game game(height, width);


                while (!game.gameOver()) {
                        game.processInput();
                        game.updateState();
                        game.redraw();
                }

                game.closeGame();
                getch();
            // }
            // system("clear");
        }

        ~RunGame(){
        }
};
#endif