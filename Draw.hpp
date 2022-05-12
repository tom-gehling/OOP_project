#ifndef DRAW_HPP
#define DRAW_HPP
#include <ncurses.h>
#include "Display.hpp"
using namespace std;

class Draw{
    protected:
        int y, x;
        char ch;
    public:
        Draw(){
            y = x = 0;
            ch = ' ';
        }

        Draw(int y, int x, char ch){
            this->y = y;
            this->x = x;
            this->ch = ch;
        }

        int getx(){
            return x;
        }

        int gety(){
            return y;
        }

        char getCh(){
            return ch;
        }

        void setx(int x){
            this->x = x;
        }

        void sety(int y){
            this->y = y;
        }

        void setCh(char ch){
            this->ch = ch;
        }

};
#endif