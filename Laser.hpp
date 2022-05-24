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
    int laserVelocity;

    Laser(){
        Draw(0,0,'0');
        fired = false;
        this->laserVelocity = 1;
    }

    Laser(int y, int x, char ch){
        this->y = y;
        this->x = x;
        this->ch = ch;
        Draw(y,x,ch);
        fired = false;
        this->laserVelocity = 1;
    }

    void moveRight(int move){
        y += move;
    }

    void moveLeft(int move){
        y -= move;
    }

    int get_laserVelocity(){
        return laserVelocity;
    }

    void set_laserVelocity(int velocity){
        this->laserVelocity = velocity;
    }

    bool isFired(){
        return fired;
    }

    void shoot(Laser*laser, Ship*ship){
        laser->setx(ship->getx());
        laser->sety(ship->gety()+1); 
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