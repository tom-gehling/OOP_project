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
// #include "PauseQuitMenu.hpp"

using namespace std;

class Game: public Display{

    public:
        Display display_win;
        Scoreboard scoreboard;
        bool game_over;
        Player player;
        Enemy *enemies;
        Laser *laser;
        Laser *enem_laser;
        int count;
        int laserAmmo = 40;
        int enemyWave = 5;
        int enemyCount = enemyWave;
        int level = 1;
        int score = 0;
        int laserVelocity = 2;



    //initiates the display and creates a starting position
    //for the player, each of the enemies and each of the lasers
    Game(){
        // display_win = Display(20,40);
        // display_win.create();
    }


    //initiates the display and creates a starting position
    //for the player, each of the enemies and each of the lasers
    Game(int height, int width){
        srand((unsigned)time(NULL));
        game_over = false; // set this to start game

        int sb_row = display_win.getStartRow()+height;
        int sb_col = display_win.getStartCol();
        count = 0;

        display_win = Display(height, width);
        display_win.create();


        scoreboard = Scoreboard(width, sb_row, sb_col);
        scoreboard.initialise(level, score, player.getHealth());


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

        enem_laser = new Laser[laserAmmo];
        for(int i = 0; i<laserAmmo;i++){
            enem_laser[i].sety(-1);
            enem_laser[i].setx(-1);
            enem_laser[i].setCh('-');
            display_win.draw(enem_laser[i]);
        }


        enemies = new Enemy[enemyWave];
        for(int i =0; i<enemyWave;i++){
            enemies[i].setx(1+rand()%(height-2)); //sets height of enemy between x = 1 to 17
            enemies[i].sety((rand()%width)+width);
            enemies[i].setCh('m');
            display_win.draw(enemies[i]);
        }
    }


    //checks for all possibilities of collision: 
    //enemy v laser
    //player v enemy
    //player v enemy laser

    void checkCollision(){
         for (int i = 0; i<enemyWave; i++){
             for(int j=0; j<laserAmmo; j++){
                if(enemies[i].isHit(laser[j].gety(),laser[j].getx())){
                    if(enemies[i].isAlive()){
                        enemies[i].destroy();
                        laser[j].destroy();
                        enemies[i].dead();
                        enemyCount --;
                        score += 100;
                    }
                }
            }
            if(player.isHit(enemies[i].gety(),enemies[i].getx())){
                enemies[i].destroy();
                player.updateHealth(-20);
                enemies[i].dead();
                enemyCount --;
            }

            if(player.isHit(enem_laser[i].gety(),enem_laser[i].getx())){
                enem_laser[i].destroy();
                player.updateHealth(-30);
            }

        } 
    }


    // checks to see if enemy is past the left of screen
    void checkEnemiesPast(){
        for(int i=0; i<enemyWave; i++){
            if(enemies[i].gety() == 0){
                player.updateHealth(-20);
            }
        }
    }

    void deleteEnemies(){
        delete enemies;
    }


    //creates a new array of enemies to be generated
    Enemy*enemyRespawn(int newEnemies){
        enemies = new Enemy[newEnemies];
        return enemies;
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
            {if(count > laserAmmo){
                count = 0;
            }

            laser[count].fired = true;
            laser[count].setx(player.getx());
            laser[count].sety(player.gety()+1);

            //for now I just have the enemy shooting at the same time as player, to check functionality
            enem_laser[count].fired = true;
            enem_laser[count].setx(enemies[0].getx());
            enem_laser[count].sety(enemies[0].gety()+1);
            count ++ ;
            break;}

        // case 'p': //pauses game
        //    {display_win.setTimeout(-1);
        //     Menu * pause_menu = new Menu;
        //     game_over = !pause_menu->operate(PAUSE_GAME);
        //     display_win.setTimeout(1000); // input refresh rate
        //     //while(display_win.getInput()!='p'){
        //     //    display_win.setTimeout(1000);
        //     //}
        //     delete pause_menu;
            // break;}

        // case 'q': // quit game
            // {Menu * quit_menu = new Menu;
            // game_over = !quit_menu->operate(QUIT_GAME);
            // delete quit_menu;
            // break;}

        default:
            break;
        }
    }

    void updateState(){
        for (int i=0; i<enemyWave;i++){
            enemies[i].moveLeft(1);
        }
        for (int i=0; i<laserAmmo;i++){
            if (laser[i].isFired() == true){
            laser[i].sety(laser[i].gety()+laserVelocity);
            }
        }

        for (int i=0; i<laserAmmo;i++){
            if (enem_laser[i].isFired() == true){
            enem_laser[i].sety(enem_laser[i].gety()-laserVelocity);
            }
        }

       

        if(enemyCount == 0){
            level +=1;
            deleteEnemies();
            enemyWave += 2;
            enemies = enemyRespawn(enemyWave);
            srand(time(0));
            for (int i=0; i<enemyWave; i++){
                enemies[i].setx(1+rand()%(display_win.get_height()-2)); //sets height of enemy between x = 1 to 17
                enemies[i].sety((rand()%display_win.get_width())+display_win.get_width());
                enemies[i].setCh('m');
                display_win.draw(enemies[i]);
            }
            enemyCount = enemyWave;
        }

        checkCollision();
        checkEnemiesPast();
        
        if(player.getHealth()==0){
            game_over = true;
        }

        scoreboard.updateScoreboard(level, score, player.getHealth());
    }

    void redraw(){
        display_win.clear();
        display_win.draw(player);
        for(int i=0;i<laserAmmo;i++){
            display_win.draw(laser[i]);
        }
        for(int i=0;i<laserAmmo;i++){
            display_win.draw(enem_laser[i]);
        }
        for(int i=0;i<enemyWave;i++){
            display_win.draw(enemies[i]);
        }
        scoreboard.refresh();
        display_win.refresh();
    }

    bool gameOver(){
        return game_over;
    }

    int getScore(){
        return score;
    }

    int getEnemyCount(){
        return enemyWave;
    }

    void closeGame() {
        display_win.clear();
        display_win.refresh();
        endwin();
        delwin(display_win.display_win);
    }

};
#endif