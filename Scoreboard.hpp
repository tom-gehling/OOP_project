/* COMP SCI 1102 - Object Oriented Programming - Space Invaders Project */
// By Thomas Gehling, Gun (Chris) Park, Patrick Williams
// This is the class definition of the Scoreboard class. This class handles the scoreboard functionality and appearance.

#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP
#include <ncurses.h>
#include "Draw.hpp"

using namespace std;

class Scoreboard {
    private:
        WINDOW * score_win;
    public:

    Scoreboard(int width, int y, int x) {
        score_win = newwin(2, width, y, x); // makes scoreboard mini window
    }

    void initialise (int initial_score, int initial_health){
        clear();
        mvwprintw(score_win, 0, 0, "Score: "); // displays text on screen
        mvwprintw(score_win, 1, 0, "Health: ");
        updateScoreboard(initial_score, initial_health);
        refresh();

    }

    void updateScoreboard(int score, int health){ // prints to screen specified score/health
        mvwprintw(score_win, 0, 30, "%9llu", score);
        mvwprintw(score_win, 1, 30, "%9llu", health);
    }

    void clear(){ // clears mini score window
        wclear(score_win);
    }

    void refresh(){ // refresh & updates display of mini score window
        wrefresh(score_win);
    }

};

#endif