#ifndef LASER_HPP
#define LASER_HPP
#include <ncurses.h>
#include "Draw.hpp"
#include "Display.hpp"
#include "Ship.hpp"
using namespace std;


class Laser: public Draw{
    public:
    bool fired;

    Laser(){
        Draw(0,0,'0');
        fired = false;
    }

    Laser(int y, int x, char ch){
        this->y = y;
        this->x = x;
        this->ch = ch;
        Draw(y,x,ch);
        fired = false;
    }

    void moveRight(int move){
        y += move;
    }

    void moveLeft(int move){
        y -= move;
    }

    bool isFired(){
        return fired;
    }

    void shoot(Laser*laser, Ship*ship){
        laser->setx(ship->getx());
        laser->sety(ship->gety()+1); 
    }

    // still being made
    void destroy(Draw drawableIcon){
        drawableIcon.setx(-1);
        drawableIcon.sety(-1);
    }


    // still being made
    // void collide(Draw laser, Draw target){
    //     destroy(laser);
    //     destroy(target);
    // }

    // bool offScreen(){
    //     if (x>5){
    //         return true;
    //     }else{
    //         return false;
    //     }
    // }
};
#endif