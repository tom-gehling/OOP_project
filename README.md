# OOP_project
This is a Space Invaders game coded in C++ for the Object Oriented Programming COMP SCI 1102 course in The University of Adelaide.

BUG LIST (reported by in columns):
----------------------------------
- When game starts, OCCASIONALLY before enemies appear, if you shoot, raises seg fault. (Gun detected)
- collision + check collision are the same (Game.hpp)
- collide, offscreen still being made on Laser.hpp