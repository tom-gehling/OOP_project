#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <ncurses.h>
#include "Draw.hpp"

using namespace std;

class Display{
    public:
    WINDOW * display_win;
    int height, width;

    Display(){
        height = 0;
        width = 0;
    }

    Display(int height, int width){
        this->height = height;
        this->width = width;
    }

    void create(){     
        display_win = newwin(height, width, 1,1);

        noecho();
        curs_set(0);

        wtimeout(display_win, 500);
        keypad(display_win, true);

        box(display_win, 0, 0);
        wrefresh(display_win);
    } 

    void draw(Draw draw){
        addAt(draw.getx(), draw.gety(), draw.getCh());
    }

    void addBorder(){
        box(display_win,0,0);
    }

    void addAt(int y, int x, char ch){
        mvwaddch(display_win, y, x, ch);
    }

    chtype getInput(){
        return wgetch(display_win);
    }

    void clear(){
        wclear(display_win);
        addBorder();
    }

    void refresh(){
        wrefresh(display_win);
    }

    int get_height(){
        return height;
    }

    int get_width(){
        return width;
    }

    

};

#endif