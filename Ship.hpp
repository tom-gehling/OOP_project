#ifndef SHIP_HPP
#define SHIP_HPP
#include <ncurses.h>
#include "Draw.hpp"
#include "Display.hpp"
#include "Laser.hpp"
using namespace std;


class Ship: public Draw{
    public:

    Ship(){
        this->y = 0;
        this->x = 0;
        this->ch = '0';
        Draw(0,0,'0');
    }

    Ship(int y, int x, char ch){
        this->y = y;
        this->x = x;
        this->ch = ch;
        Draw(y,x,ch);
    }

    void moveUp(int move){
        x -= move;
    }

    void moveDown(int move){
        x += move;
    }

    void moveRight(int move){
        y += move;
    }

    void moveLeft(int move){
        y -= move;
    }

    virtual bool fire() = 0;
    
};
#endif