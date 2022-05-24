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
    bool alive;
    int speed;
    int laserVelocity;

    Enemy(){
        Draw(-1,-1,'0');
        laser = new Laser[1];
        this->alive = true;
        this-> speed = 1;
    }

    Enemy(int y, int x, char ch){ // this is the specific constructor for enemy ships; draws enemy ship at specific x,y
        this->y = y;
        this->x = x;
        this->ch = ch;
        this->alive = true;
        Draw(y,x,ch);
        laser = new Laser[1];
        this-> speed = 1;
    }

    // [POLYMORPHISM]  redefined fire() function from base class ship
    bool fire() { // this allows enemy ship to fire in a straight line
        if (1+rand()%6 == 1){
            return true;
        }
        else{
            return false;
        }

    }

    int get_speed(){
        return speed;
    }

    void increase_speed(int increment){
        this->speed += increment;
    }

    bool dead(){
        alive = false;
        }

    bool isAlive(){
        return alive;
    }
};

#endif