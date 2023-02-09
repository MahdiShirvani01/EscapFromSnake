/*
Mehdi Shirvani
40012358021
*/
#include <iostream>
#include "../include/Snake.hpp"
////////////////////////////// set random situation for snake
void Snake::set_location_snake()
{
    srand(time(0));
    x = rand() % 595;
    y = rand() % 400;
}
int Snake::x_situation_snake()
{
    return x;
}
int Snake::y_situation_snake()
{
    return y;
}