#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <ncurses.h>
#include "Draw.hpp"
#include "Display.hpp"
#include "Laser.hpp"
using namespace std;


class Player: public Ship{
    public:

    Player(){
        Draw(0,0,'0');
    }

    Player(int y, int x, char ch){
        Draw(y,x,ch);
    }

    void fire(){

    }
    
};
#endif