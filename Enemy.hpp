#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <ncurses.h>
#include <stdlib.h>
#include "Draw.hpp"
#include "Display.hpp"
#include "Laser.hpp"
using namespace std;


class Enemy: public Ship{
    public:

    Enemy(){
        Draw(0,0,'0');
    }

    Enemy(int y, int x, char ch){
        Draw(y,x,ch);
    }

    void fire(){
    }
};
#endif