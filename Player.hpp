#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <ncurses.h>
#include "Draw.hpp"
#include "Display.hpp"
#include "Laser.hpp"
using namespace std;


class Player: public Ship{
    public:
    int health;

    Player(){
        this->y = 0;
        this->x = 0;
        this->ch = '0';
        Draw(0,0,'0');
        health = 100;
    }

    Player(int y, int x, char ch){
        this->y = y;
        this->x = x;
        this->ch = ch;
        Draw(y,x,ch);
        health = 100;
    }

    void updateHealth(int incrementHealth){
        health += incrementHealth;
    }

    int getHealth(){
        return health;
    }

    bool fire(){
        return true;
    }
    
};
#endif