#ifndef LASER_HPP
#define LASER_HPP
#include <ncurses.h>
#include "Draw.hpp"
#include "Display.hpp"
#include "Ship.hpp"
using namespace std;


class Laser: public Draw{
    public:
    bool fired;

    Laser(){
        Draw(0,0,'0');
        fired = false;
    }

    Laser(int y, int x, char ch){
        Draw(y,x,ch);
        fired = false;
    }

    void moveRight(int move){
        y += move;
    }

    void moveLeft(int move){
        y -= move;
    }

    bool isFired(){
        return fired;
    }

    void destroy(Draw drawable){
        drawable.setx(-1);
        drawable.sety(-1);
    }

    void collide(int x, int y, int obj_x, int obj_y){
        x = -1;
        y = -1;
        obj_x = -1;
        obj_y = -1;
    }

    // bool offScreen(){
    //     if (x>5){
    //         return true;
    //     }else{
    //         return false;
    //     }
    // }
};
#endif