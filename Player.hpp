/* COMP SCI 1102 - Object Oriented Programming - Space Invaders Project */
// By Thomas Gehling, Gun (Chris) Park, Patrick Williams
// This is the class definition of the Player class. This class defines the player's ship in the game.

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <ncurses.h>
#include "Draw.hpp"
#include "Display.hpp"
#include "Laser.hpp"
using namespace std;


class Player: public Ship {
    public:
    Laser * laser;

    Player() { // default constructor
        this->y = 0;
        this->x = 0;
        this->ch = '0';
        Draw(0,0,'0');
        laser = new Laser[10];
    }

    Player(int y, int x, char ch) {
        this->y = y;
        this->x = x;
        this->ch = ch;
        Draw(y,x,ch);
        laser = new Laser[10];
    }

    bool fire() { // fires a laser projectile
        return laser->isFired();
    }

};
#endif