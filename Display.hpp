#ifndef DISPLAY_HPP
#define DISPLAY_HPP
#include <ncurses.h>
#include "Draw.hpp"

using namespace std;

class Display{
    public:
    WINDOW * display_win;
    int height, width, start_row, start_col;

    
    // default constructor for
    Display(){
        height = 0;
        width = 0;
        start_row = 0;
        start_col = 0;
    }

    Display(int height, int width){
        initscr();
        curs_set(FALSE); // hides cursor
        this->height = height;
        this->width = width;
        start_row = 0;
        start_col = 0;
    }

    void create(){
        display_win = newwin(height, width, start_row, start_col);

        noecho();
        curs_set(0);

        wtimeout(display_win, 200);
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

    void addText(int y, int x, char* str) {
        mvwprintw(display_win, y, x, str);
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

    void delete_window(){
        endwin();
        delwin(display_win);
    }

    void highlight_on() {
        wattron(display_win, A_REVERSE);
    }

    void highlight_off() {
        wattroff(display_win, A_REVERSE);
    }

    int get_height(){
        return height;
    }

    int get_width(){
        return width;
    }

    char getCharAt(int y, int x){
        return mvwinch(display_win, y, x);
    }

    void setTimeout(int timeout){
        wtimeout(display_win, timeout);
    }

    int getStartRow(){
        return start_row;
    }

     int getStartCol(){
        return start_col;
    }

};

#endif