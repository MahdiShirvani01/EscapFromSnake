/*
Mehdi Shirvani
40012358021
*/
#ifndef USER_H
#define USER_H
#include <string>
// we need a class to user, it is whit diffrent feachers
class User
{
private:
    int x, y;
    short int number, difficulty;
    char enter;
    std::string first_name, last_name;
public:
    void set_location(); // to set random situation in frame
    int x_situation(); // return amount of x
    int y_situation(); // return amount of y
};

#endif