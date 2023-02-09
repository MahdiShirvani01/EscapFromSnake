/*
Mehdi Shirvani
40012358021
*/
#ifndef SNAKE_H
#define SNAKE_H
#include <string>
#include "User.hpp"
#include "New_Game.hpp"
// snake class that we have type of snake on it
class Snake
{
private:  
    int jump; // movement of snake on y
    int x, y;
public:
    void set_location_snake(); // set random situation for snake
    int x_situation_snake(); // return x of snake
    int y_situation_snake(); // return y of snake
    

};
#endif