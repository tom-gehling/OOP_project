/* COMP SCI 1102 - Object Oriented Programming - Space Invaders Project */
// By Thomas Gehling, Gun (Chris) Park, Patrick Williams
// This is the class definition of the Enemy class. This class creates an Enemy ship that the user must shoot and destroy.

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "Draw.hpp"
#include "Display.hpp"
#include "Laser.hpp"

using namespace std;


class Enemy: public Ship { // derived from Ship class
    public:
    Laser *laser;

    Enemy() { // default constructor
        Draw(0,0,'0');
        laser = new Laser[1];
    }

    Enemy(int y, int x, char ch){ // this is the specific constructor for enemy ships; draws enemy ship at specific x,y
        this->y = y;
        this->x = x;
        this->ch= ch;
        Draw(y,x,ch);
        laser = new Laser[1];
    }

    // [POLYMORPHISM]  redefined fire() function from base class ship
    bool fire() { // this allows enemy ship to fire in a straight line
        srand((unsigned)time(NULL));
        if ((rand()%6+1) == 0){
            return true;
        }
        else{
            return false;
        }

    }
};

#endif