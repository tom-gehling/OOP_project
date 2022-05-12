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
        Draw(0,0,'0');
    }

    Ship(int y, int x, char ch){
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

    virtual void fire() = 0;
    
};
#endif