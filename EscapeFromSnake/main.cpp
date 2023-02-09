#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "include/Snake.hpp"
#include "include/User.hpp"
#include "include/New_Game.hpp"

int main()
{
    NewGame s;
    s.fix_menu();
    s.runing_game();
}