#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "Draw.hpp"
#include "Display.hpp"
#include "Laser.hpp"

using namespace std;


class Enemy: public Ship{
    public:
    Laser *laser;
    bool alive;
    int speed;

    Enemy(){
        Draw(-1,-1,'0');
        laser = new Laser[1];
        this->alive = true;
    }

    Enemy(int y, int x, char ch){
        this->y = y;
        this->x = x;
        this->ch = ch;
        this->alive = true;
        Draw(y,x,ch);
        laser = new Laser[1];
    }

    bool fire(){
        srand((unsigned)time(NULL));
        if ((rand()%6+1) == 0){
            return true;
        }
        else{
            return false;
        }

    }

    void set_speed(int increment){
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