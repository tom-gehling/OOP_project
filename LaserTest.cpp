#include <iostream>
#include <ncurses.h>
#include "Player.hpp"
#include "Ship.hpp"
#include "Draw.hpp"
#include "Laser.hpp"

using namespace std;

int main()
{

    Laser test1(10, 30, 'A');
    if(test1.getx() != 30){
        cout << "Test1 Failed" << endl;
    }

    Laser test2(30,50,'A');
    if(test2.gety() != 30){
        cout << "Test2 Failed" << endl;
    }

    Laser test3(25, 30, 'A');
    if (test3.isFired() == 1)
    {
        cout << "Test3 Failed" << endl;
    }
    
    Laser test4(42, 20, 'A');
    test4.moveLeft(1);
    if (test4.gety() != (42-1))
    {
        cout << "Test4 Failed" << endl;
    }
    
    Laser test5(31, 50, 'A');
    test5.moveRight(1);
    if (test5.gety() != (31+1))
    {
        cout << "Test5 Failed" << endl;
    }

    return 0;
}