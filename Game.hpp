#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "Display.hpp"
#include "Draw.hpp"
#include "Ship.hpp"
using namespace std;

class Game: public Display{
    public:
    Display display;
    bool game_over;
    Ship ship;

    Game(int height, int width){
        display = Display(height, width);
        startGame();
        game_over=false;
        srand(time(NULL));
    }

    void startGame(){
        ship = Ship(1,9);
        display.initialise();
        game_over = false;
        display.add(ship);
    }

    void processInput(){
        chtype input = display.getInput();
        switch (input)
        {
        case KEY_UP:
            if(ship.getx()>1){
                ship.moveUp(1);
                break;
            }
            else{
                break;
            }
           
         case KEY_DOWN:
                if(ship.getx()<display.get_height()-2){
                    ship.moveDown(1);
                break;
            }
            else{
                break;
            }
           
            break;

         case KEY_LEFT:
            if(ship.gety()>2){
                ship.moveLeft(2);
                break;
            }else{
                break;
            }

        case KEY_RIGHT:
            if(ship.gety()<display.get_width()-3){
                ship.moveRight(2);
                break;
            }else{
                break;
            }

        case 's':
            display.addAt(ship.gety(),ship.getx()+1, ship.getLaser());
            break;
        
        default:
            break;
        }

    }

    void updateState(){
        
    }

    void redraw(){
        // display.refresh();
        display.clear();
        display.add(ship);

    }

    bool isOver(){
        return game_over;
    }

};
#endif