#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <ncurses.h>
#include "Draw.hpp"

using namespace std;

class Display{
    public:
    WINDOW * display_win;

    void construct(int size){
        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);
        display_win = newwin(size, size*2.5, (yMax/2)-(size/2),(xMax/2.5)-(size/2));
    }

    Display(){
        construct(0);
    }

    Display(int size){
        construct(size);
    }

    void initialise(){
        clear();
        refresh();
        noecho();
    }

    void add(Draw draw){
        addAt(draw.getx(), draw.gety(), draw.getIcon());
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
};

#endif