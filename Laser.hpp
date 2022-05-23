/* COMP SCI 1102 - Object Oriented Programming - Space Invaders Project */
// By Thomas Gehling, Gun (Chris) Park, Patrick Williams
// This is the class definition of the Laser class. This class defines the laser projectile '-' that users and enemy ships can shoot.

#ifndef LASER_HPP
#define LASER_HPP
#include <ncurses.h>
#include "Draw.hpp"
#include "Display.hpp"
#include "Ship.hpp"
using namespace std;


class Laser: public Draw{
    public:
    bool fired; // determines whether something is fired or not

    Laser() {
        Draw(0,0,'0');
        fired = false;
    }

    Laser(int y, int x, char ch) {
        this->y = y;
        this->x = x;
        this->ch = ch;
        Draw(y,x,ch);
        fired = false;
    }

    /* Moves projectile coordinate right */
    void moveRight(int move){
        y += move;
    }

    /* Moves projectile coordinate left */
    void moveLeft(int move){
        y -= move;
    }

    /* Returns fired result */
    bool isFired(){
        return fired;
    }

    /* Shoots projectile from specified ship */
    void shoot(Laser*laser, Ship*ship){
        laser->setx(ship->getx()); // spawns projectile next to ship
        laser->sety(ship->gety()+1);
    }

    /* Generates destroy effect on other ships when projectile makes impact */
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