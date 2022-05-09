#ifndef DRAW_HPP
#define DRAW_HPP
#include <ncurses.h>
#include "Display.hpp"
using namespace std;

class Draw{
    protected:
        int y, x;
        chtype icon;
        char laser;
    public:
        Draw(){
            y = x = 0;
            icon = ' ';
            laser = ' ';
        }

        Draw(int y, int x, chtype ch, char las){
            this->y = y;
            this->x = x;
            this->icon = ch;
            this->laser = las;
        }

        int getx(){
            return x;
        }

        int gety(){
            return y;
        }

        chtype getIcon(){
            return icon;
        }

        char getLaser(){
            return laser;
        }

};
#endif