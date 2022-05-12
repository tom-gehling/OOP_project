#ifndef GAME_HPP
#define GAME_HPP
#include <ncurses.h>
#include <stdlib.h>
#include "Display.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Laser.hpp"

using namespace std;

class Game: public Display{

    public:
        Display display_win;
        bool game_over;
        Player ship;
        Enemy enemies;
        Laser laser;
        int count;

    Game(){
        display_win.create();
    }

    Game(int height, int width){
        display_win = Display(height, width);
        display_win.create();
        ship.sety(10);
        ship.setx(2);
        ship.setCh('>');
        display_win.draw(ship);
        // laser = new Laser[5];
        // count = 0;
        // for(int i =0; i<5;i++){
        //     laser[i].sety(-1);
        //     laser[i].setx(-1);
        //     laser[i].setCh('~');
        //     display_win.draw(laser[i]);
        // }

        laser.sety(-1);
        laser.setx(-1);
        laser.setCh('~');
        display_win.draw(laser);
        // enemies = new Enemy[5];
        // for(int i =0; i<5;i++){
        //     enemies[i].setx(rand()%height);
        //     enemies[i].sety((rand()%width)+width);
        //     enemies[i].setCh('x');
        //     display_win.draw(enemies[i]);
        // }

        enemies.setx(rand()%height);
        enemies.sety((rand()%width)+width);
        enemies.setCh('x');
        display_win.draw(enemies);

    }   
    

    void processInput(){
        chtype input = display_win.getInput();
        switch (input)
        {
        case KEY_UP:
            if(ship.getx()>1){
                ship.moveUp(1);
                break;
            }
            else{
                break;
            }
           
         case KEY_DOWN:
                if(ship.getx()<display_win.get_height()-2){
                    ship.moveDown(1);
                break;
            }
            else{
                break;
            }
           
            break;

         case KEY_LEFT:
            if(ship.gety()>2){
                ship.moveLeft(2);
                break;
            }else{
                break;
            }

        case KEY_RIGHT:
            if(ship.gety()<display_win.get_width()-3){
                ship.moveRight(2);
                break;
            }else{
                break;
            }

        case 's':
            // laser[count].setx(ship.getx());
            // laser[count].sety(ship.gety()+1);

            laser.setx(ship.getx());
            laser.sety(ship.gety()+1);
            break;
        default:
            break;
        }
    }

    void updateState(){
    //     laser[count].sety(laser[count].gety()+1);
    //     for (int i=0; i<5;i++){
    //         enemies[i].moveLeft(1);
    //     }

    //     for(int i=0;i<5;i++){
    //         for (int j=0; j<5;j++){
    //             if(laser[j].getx() == enemies[i].getx() && laser[j].gety() == enemies[i].gety()){
    //                 laser[j].destroy(enemies[i]);
    //                 laser[j].destroy(laser[j]);
    //             }
    //         }
    //     }



        laser.sety(laser.gety()+3);
        enemies.moveLeft(1);
        if(laser.getx() == enemies.getx() && laser.gety() == enemies.gety()){
            laser.destroy(enemies);
            laser.destroy(laser);
            }
    }

    void redraw(){
        display_win.clear();
        display_win.draw(ship);
        // display_win.draw(laser[count]);
        display_win.draw(laser);

        // for(int i=0;i<5;i++){
        //     display_win.draw(enemies[i]);
        // }
        display_win.draw(enemies);



        // if(laser[count].offScreen()==true){
        //     display_win.addAt(2,2,'d');
        // }
        display_win.refresh();
    }

    bool gameOver(){
        return game_over;
    }

};
#endif