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

    Enemy(){
        Draw(0,0,'0');
        laser = new Laser[1];
    }

    Enemy(int y, int x, char ch){
        this->y = y;
        this->x = x;
        this->ch= ch;
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
};
#endif