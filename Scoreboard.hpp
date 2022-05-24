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

<<<<<<< HEAD
    Scoreboard(){
    }
    
    Scoreboard(int width, int y, int x){
        score_win = newwin(3, width, y, x);
    }

    void initialise(int level, int initial_score, int initial_health){
        clear();
        mvwprintw(score_win, 0, 0, "Level: ");
        mvwprintw(score_win, 1, 0, "Score: ");
        mvwprintw(score_win, 2, 0, "Health: ");
        updateScoreboard(level, initial_score, initial_health);
=======
    Scoreboard(int width, int y, int x) {
        score_win = newwin(2, width, y, x); // makes scoreboard mini window
    }

    void initialise (int initial_score, int initial_health){
        clear();
        mvwprintw(score_win, 0, 0, "Score: "); // displays text on screen
        mvwprintw(score_win, 1, 0, "Health: ");
        updateScoreboard(initial_score, initial_health);
>>>>>>> 98cb14b6f1fc7695ba0f0ee9d8336492de9cf649
        refresh();

    }

<<<<<<< HEAD
    void updateScoreboard(int level, int score, int health){
        mvwprintw(score_win, 0, 30, "%9llu", level);
        mvwprintw(score_win, 1, 30, "%9llu", score);
        mvwprintw(score_win, 2, 30, "%9llu", health);
=======
    void updateScoreboard(int score, int health){ // prints to screen specified score/health
        mvwprintw(score_win, 0, 30, "%9llu", score);
        mvwprintw(score_win, 1, 30, "%9llu", health);
>>>>>>> 98cb14b6f1fc7695ba0f0ee9d8336492de9cf649
    }

    void clear(){ // clears mini score window
        wclear(score_win);
    }

    void refresh(){ // refresh & updates display of mini score window
        wrefresh(score_win);
    }

};

#endif