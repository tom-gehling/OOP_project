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
        score_win = newwin(2, width, y, x);
    }

    void initialise(int initial_score, int initial_health){
        clear();
        mvwprintw(score_win, 0, 0, "Score: ");
        mvwprintw(score_win, 1, 0, "Health: ");
        updateScoreboard(initial_score, initial_health);
        refresh();

    }

    void updateScoreboard(int score, int health){
        mvwprintw(score_win, 0, 30, "%9llu", score);
        mvwprintw(score_win, 1, 30, "%9llu", health);
    }

    void clear(){
        wclear(score_win);
    }

    void refresh(){
        wrefresh(score_win);
    }
    
};

#endif