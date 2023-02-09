/*
Mehdi Shirvani
40012358021
*/
#include <iostream>
#include "../include/User.hpp"
////////////////////////////// set random situation for player
void User::set_location()
{
    srand(time(0));
    x = rand() % 400;
    y = rand() % 400;
    
}
int User::x_situation()
{
    return x;
}
int User::y_situation()
{
    return y;
}
