/* COMP SCI 1102 - Object Oriented Programming - Space Invaders Project */
// By Thomas Gehling, Gun (Chris) Park, Patrick Williams
// This is the class definition of the Game class. This is the main class that builds and combines the different elements of the game.

#ifndef GAME_HPP
#define GAME_HPP
#include <ncurses.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Display.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Laser.hpp"
#include "Scoreboard.hpp"
#include "Menu.hpp"

using namespace std;

class Game: public Display {

    public:
        Display display_win;
        bool game_over; // flag to determine if game should be stopped
        Player player;
        Enemy *enemies;
        Laser *laser;

        // set default values for game start
        int count = 0;
        int laserAmmo = 40;
        int enemyWave = 3;
        int level = 1;
        int score = 0;
        int health = 100;
        int laserVelocity = 2;

    /* Initiates the display and creates a starting position
    for the player, each of the enemies and each of the lasers*/
    Game(int height, int width){

        /* Game init */
        game_over = false;              // set this to start game
        srand((unsigned)time(NULL));    // set seed for rand

        /* Start Display */
        display_win = Display(height, width);
        display_win.create();

        /* Build Scoreboard */
        int sb_row = display_win.getStartRow()+height;
        int sb_col = display_win.getStartCol();
        Scoreboard scoreboard(width, sb_row, sb_col);
        score = 0;
        scoreboard.initialise(score, health);

        /* Set player starting position */
        player.sety(1);
        player.setx((height/2)-1);
        player.setCh('>');
        display_win.draw(player);
        laser = new Laser[laserAmmo]; // player's shooting bullet

        for(int i = 0; i<laserAmmo;i++) { // creates 40 ammos off-screen as per default
            laser[i].sety(-1);
            laser[i].setx(-1);
            laser[i].setCh('-');
            display_win.draw(laser[i]);
        }

        /* Create enemy */
        enemies = new Enemy[3];
        for(int i =0; i<3;i++) {
            enemies[i].setx(1+rand()%(height-2));   // randomises start position of enemy x
            enemies[i].sety((rand()%width)+width);  // randomises start position of enemy x
            enemies[i].setCh('m');
            display_win.draw(enemies[i]);
        }
    }

    /* Generates collision effects on enemy */
    void collision (Laser * laser){
        for (int i = 0; i<3; i++){
            if (display_win.getCharAt(laser->gety()+1, laser->getx())==enemies[i].getCh()||
            display_win.getCharAt(laser->gety(), laser->getx())==enemies[i].getCh())
            {
                laser->destroy(enemies[i]); // enemies are destroyed
                enemies[i].moveLeft(0);
            }
        }
    }

    void checkCollision(){
         for (int i = 0; i<3; i++){
            if (display_win.getCharAt(laser->gety()+1, laser->getx())==enemies[i].getCh()||
            display_win.getCharAt(laser->gety(), laser->getx())==enemies[i].getCh())
            {
                laser->destroy(enemies[i]);
                enemies[i].moveLeft(0);
            }
        }
    }


    /* Processes user input */
    void processInput() {

        chtype input = display_win.getInput(); // gets user input

        switch (input) {
        case KEY_UP: // up arrow key moves player up
            if(player.getx()>1){
                player.moveUp(1);
                break;
            }
            else{
                break;
            }

         case KEY_DOWN:
                if(player.getx()<display_win.get_height()-2){
                    player.moveDown(1);
                break;
            }
            else{
                break;
            }

            break;

         case KEY_LEFT:
            if(player.gety()>2){
                player.moveLeft(1);
                break;
            }else{
                break;
            }

        case KEY_RIGHT:
            if(player.gety()<display_win.get_width()-3){
                player.moveRight(1);
                break;
            }
            break;
        case ' ': // this is the shooting key
            {if(count > laserAmmo) {
                count = 0;
            }
            laser[count].fired = true;
            laser[count].setx(player.getx());
            laser[count].sety(player.gety()+1);
            count ++ ;
            break;}

        case 'p': // pauses game and brings up menu
           {display_win.setTimeout(-1);
            Menu * pause_menu = new Menu;
            game_over = !pause_menu->operate(PAUSE_GAME);
            display_win.setTimeout(1000); // input refresh rate
            delete pause_menu;
            break;}

        case 'q': // brings up quit game menu
            {Menu * quit_menu = new Menu;
            game_over = !quit_menu->operate(QUIT_GAME);
            delete quit_menu;
            break;}

        default:
            break;
        }
    }

    /* Auto-updates state of game */
    void updateState(){

        for (int i=0; i<laserAmmo;i++) { // laser ammo moves at defined velocity every 1s (refresh rate as set above)
            if (laser[i].isFired() == true){
            laser[i].sety(laser[i].gety()+laserVelocity);
            }
        }

        for (int i=0; i<3;i++) { // enemies move left 1 space every 1s
            enemies[i].moveLeft(1);
        }


        for(int i=0;i<3;i++) {
            for (int j=0; j<laserAmmo;j++) {
                if(display_win.getCharAt(laser[j].gety()+1,laser[j].getx()) == enemies[i].getCh()){
                    laser[j].destroy(enemies[i]);
                    laser[j].destroy(laser[j]);
                }
            }
        }
    }

    /* Redraws window at current state of game */
    void redraw(){
        display_win.clear();
        display_win.draw(player);

        for(int i=0;i<laserAmmo;i++){
            display_win.draw(laser[i]);
        }

        for(int i=0;i<3;i++){
            display_win.draw(enemies[i]);
        }

        display_win.refresh(); // refresh to update visible window
    }

    /* Returns game_over result */
    bool gameOver(){
        return game_over;
    }

    /* Returns scoreboard user score */
    int getScore(){
        return score;
    }

    /* Closes game & ends window */
    void closeGame() {
        display_win.clear();
        display_win.refresh();
        endwin();
        delwin(display_win.display_win);
    }

};
#endif