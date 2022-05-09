#ifndef Player_HPP
#define Player_HPP
#include <ncurses.h>
#include "Display.hpp"
#include "Draw.hpp"
using namespace std;


class Player : public Ship{
    public:
    Player(){
        this->x = 0;
        this->y = 0;
        this->icon = '>';
    }

    Player(int y, int x){
        this->x = x;
        this->y = y;
        this->icon = '>';
    }

    void moveUp(int move){
        x = x - move;
    }

    void moveDown(int move){
        x = x + move;
    }

    void moveRight(int move){
        y = y + move;
    }

    void moveLeft(int move){
        y = y - move;
    }
};
#endif