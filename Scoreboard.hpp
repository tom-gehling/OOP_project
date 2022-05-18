#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP
#include <ncurses.h>
#include "Draw.hpp"

using namespace std;

class Scoreboard{
    private:
        WINDOW * score_win;
    public:
    
    Scoreboard(int width, int y, int x){
        score_win = newwin(1, width, y, x);
    }

    void initialise(int initial_score){
        clear();
        mvwprintw(score_win, 0, 0, "Score: ");
        updateScore(initial_score);
        refresh();

    }

    void updateScore(int score){
        mvwprintw(score_win, 0, 30, "%11llu", score);
    }

    void clear(){
        wclear(score_win);
    }

    void refresh(){
        wrefresh(score_win);
    }
    
};

#endif