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

    Menu(int height, int width) {
        menu_win = Display(height,width);
        menu_win.create();
    }

    bool operate(int menu_type) { // operates menu, calls decider and returns run_flag (a bit messy currently, to be simplified/elegantified)
        int selection = 0;
        vector<char*> options;
        int number_of_options = 0;

        switch (menu_type) {
            case START: // start menu
                options.insert(options.end(), {"START GAME","HOW TO PLAY","QUIT GAME"});
                break;
            case PAUSE_GAME:
                options.insert(options.end(), {"RESUME GAME","RESTART GAME", "HOW TO PLAY","QUIT GAME"});
                break;
            case QUIT_GAME:
                options.insert(options.end(), {"RESUME GAME","QUIT GAME"});
                break;
        }

        number_of_options = options.size();
        while (true) {
            for (int i = 0; i < number_of_options; ++i) {
                if (i == selection) {
                    menu_win.highlight_on();
                }
                menu_win.addText(i+7,5,options[i]);
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

                    if (strcmp(options[selection],"START GAME") == 0) {
                        menu_win.delete_window();
                        return true;
                    }
                    if (strcmp(options[selection],"RESTART GAME") == 0) {
                        menu_win.delete_window();
                        return true; // true functionality to be implemented 16/05
                    }
                    if (strcmp(options[selection],"RESUME GAME") == 0) {
                        menu_win.delete_window();
                        return true;
                    }
                    if (strcmp(options[selection],"HOW TO PLAY") == 0) {
                        run_instruction_menu();
                        break;
                    }
                    if (strcmp(options[selection],"QUIT GAME") == 0) {
                        menu_win.delete_window();
                        return false;
                    }
                default:
                    break;
            }
        }
    }

    void run_instruction_menu() { // runs instruction menu
        vector<char*> instructions;
        instructions.insert(instructions.end(), {"Welcome to Space Invaders.","","GAME INSTRUCTIONS:","", "Enemies are denoted 'm'.", "Your spaceship is '>'.","SPACEBAR to destroy your enemies!"});

        for (int i = 0; i < instructions.size(); i++) {
            menu_win.addText(i+2,2, instructions[i]);
        }

        menu_win.addText(18,2,"PRESS ENTER TO RETURN TO MAIN MENU");

        while (true) {
            chtype user_keyinput = menu_win.getInput();
            if (user_keyinput == ENTER) {
                    menu_win.clear();
                    menu_win.refresh();
                    return;
            }
        }
    }

};

#endif