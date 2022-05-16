#ifndef PAUSEQUITMENU_HPP
#define PAUSEQUITMENU_HPP
#include "Display.hpp"
#include <string.h>
#include <vector>

using namespace std;

#define START       3
#define RESTART     2
#define PAUSE_GAME  1
#define QUIT_GAME   0
#define ENTER       10 // ascii value of 'Enter' letter

class Menu: public Display {

    public:
        Display menu_win;
        int option;

    Menu() {
        menu_win = Display(20,40);
        menu_win.create();
    }

    bool operate(int menu_type) { // operates menu, calls decider and returns run_flag (a bit messy currently, to be simplified/elegantified)
        int selection = 0;
        vector<char*> options;
        int number_of_options = 0;

        switch (menu_type) {
            case START: // start menu
                options.insert(options.end(), {"START GAME","HOW TO PLAY","QUIT GAME"});
                number_of_options = 3;
                break;
            case PAUSE_GAME:
                options.insert(options.end(), {"RESUME GAME","RESTART GAME", "HOW TO PLAY","QUIT GAME"});
                number_of_options = 4;
                break;
            case QUIT_GAME:
                options.insert(options.end(), {"RESUME GAME","QUIT GAME"});
                number_of_options = 2;
                break;
        }

        while (true) {
            for (int i = 0; i < number_of_options; ++i) {
                if (i == selection) {
                    menu_win.highlight_on();
                }
                mvwprintw(menu_win.display_win, i+1, 13, options[i]);
                menu_win.highlight_off();
            }
            chtype user_keyinput = menu_win.getInput();
            switch(user_keyinput) {
                case KEY_UP:
                    selection--;
                    if (selection < 0) selection = selection + number_of_options;
                    break;
                case KEY_DOWN:
                    selection++;
                    if (selection == number_of_options) selection = 0;
                    break;
                case ENTER:
                    menu_win.clear();
                    menu_win.refresh();
                    menu_win.delete_window();

                    if (strcmp(options[selection],"START GAME") == 0) return true;
                    if (strcmp(options[selection],"RESTART GAME") == 0) return true; // true functionality to be implemented 16/05
                    if (strcmp(options[selection],"RESUME GAME") == 0) return true;
                    if (strcmp(options[selection],"HOW TO PLAY") == 0) return true; //15/05 - need to implement how to play
                    if (strcmp(options[selection],"QUIT GAME") == 0) return false;

                default:
                    break;
            }
        }
    }
};

#endif