#ifndef DRAW_HPP
#define DRAW_HPP
#include <ncurses.h>
#include "Display.hpp"
using namespace std;

class Draw{
    protected:
        int y, x;
        chtype icon;
    public:
        Draw(){
            y = x = 0;
            icon = ' ';
        }

        Draw(int y, int x, chtype ch){
            this->y = y;
            this->x = x;
            this->icon = ch;
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
};
#endif