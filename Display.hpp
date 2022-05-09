#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <time.h>
#include <ncurses.h>
#include "Draw.hpp"
#include "Ship.hpp"

using namespace std;

class Display{
    public:
    WINDOW * display_win;
    WINDOW * scoreboard;
    int height, width;
    int start_row, start_col;

    void construct(int height, int width){ 
        int yMax, xMax; 
        getmaxyx(stdscr, yMax, xMax);
        this->height = height;
        this->width = width;
        this->start_row = (yMax/2)-(height/3);
        this->start_col = (xMax/2)-(width/2);
        
        display_win = newwin(height, width, (yMax/2)-(height/3),(xMax/2)-(width/2));
        wtimeout(display_win,500);
        keypad(display_win, true);
    } 

    Display(){
        construct(0,0);
    }

    Display(int height, int width){
        construct(height, width);
    }

    void initialise(){
        clear();
        refresh();
        noecho();
        curs_set(0);
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

    int get_height(){
        return height;
    }

    int get_width(){
        return width;
    }

    int get_StartRow(){
        return start_row;
    }

    int get_StartCol(){
        return start_col;
    }
};

#endif