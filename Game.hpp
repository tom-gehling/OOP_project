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

using namespace std;

class Game: public Display{

    public:
        Display display_win;
        bool game_over;
        Player player;
        Enemy *enemies;
        Laser *laser;
        int count;
        int laserAmmo = 40;
        int enemyWave = 3;
        int level = 1;
        int score = 0;
        int laserVelocity = 2;


    //initiates the display and creates a starting position 
    //for the player, each of the enemies and each of the lasers
    Game(){
        display_win = Display(20,40);
        display_win.create();
    }


    //initiates the display and creates a starting position 
    //for the player, each of the enemies and each of the lasers
    Game(int height, int width){ 
        srand((unsigned)time(NULL));
        display_win = Display(height, width);
        display_win.create();
        
        
        player.sety(1);
        player.setx((height/2)-1);
        player.setCh('>');
        display_win.draw(player);
       
        

        laser = new Laser[laserAmmo];
        for(int i = 0; i<laserAmmo;i++){
            laser[i].sety(-1);
            laser[i].setx(-1);
            laser[i].setCh('-');
            display_win.draw(laser[i]);
        }

        enemies = new Enemy[3];
        for(int i =0; i<3;i++){
            enemies[i].setx(1+rand()%(height-2)); //sets height of enemy between x = 1 to 17 
            enemies[i].sety((rand()%width)+width);
            enemies[i].setCh('m');
            display_win.draw(enemies[i]);
        }
    }   


    void processInput(){
        chtype input = display_win.getInput();
        switch (input)
        {
        case KEY_UP:
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
            }else{
                break;
            }

        case ' ':
            if(count > laserAmmo){
                count =0;
            }
            laser[count].fired = true;
            laser[count].setx(player.getx());
            laser[count].sety(player.gety()+1);
            count ++ ;
            break;

        case 'p': //pauses game
            display_win.setTimeout(-1);
            while(display_win.getInput()!='p'){
                display_win.setTimeout(1000);
            }
            break;
        default:
            break;
        }
    }

    void updateState(){

        for (int i=0; i<laserAmmo;i++){
            if (laser[i].isFired() == true){
            laser[i].sety(laser[i].gety()+laserVelocity);
            } 
        }
        
        for (int i=0; i<5;i++){
            enemies[i].moveLeft(1);
        } 

        for(int i=0;i<5;i++){
            for (int j=0; j<5;j++){
                if(laser[j].getx() == enemies[i].getx() && laser[j].gety() == enemies[i].gety()){
                    laser[j].destroy(enemies[i]);
                    laser[j].destroy(laser[j]);
                }
            }
        }
    }

    void redraw(){
        display_win.clear();
        display_win.draw(player);

        for(int i=0;i<laserAmmo;i++){
            display_win.draw(laser[i]);
        }

        for(int i=0;i<3;i++){
            display_win.draw(enemies[i]);
        }
        
        display_win.refresh();
    }

    bool gameOver(){
        return game_over;
    }

};
#endif