#ifndef SHIP_HPP
#define SHIP_HPP
#include <ncurses.h>
#include "Display.hpp"
#include "Draw.hpp"
using namespace std;


class Ship : public Draw{
    public:
    Ship(){
        this->x = 0;
        this->y = 0;
        this->icon = '>';
        this->laser = '~';
    }

    Ship(int y, int x){
        this->x = x;
        this->y = y;
        this->icon = '>';
        this->laser = '~';
    }

    int getx(){
        return x;
    }

    int gety(){
        return y;
    }

    void setIcon(chtype ch){
        this->icon = ch;
    }

    void setx(int _x){
        this-> x = _x;
    }

    void sety(int _y){
        this->y = _y;
    }

    void moveUp(int move){
        x = x - move;
    }

    void moveDown(int move){
        x = x + move;
    }

    void moveRight(int move){
        y = y + move;
    }

    void moveLeft(int move){
        y = y - move;
    }

    




    
};
#endif