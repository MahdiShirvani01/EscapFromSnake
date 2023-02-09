/*
Mehdi Shirvani
40012358021
*/
#ifndef NEW_GAME_H
#define NEW_GAME_H
// it is a class to have game
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <string>
///////////////// game engien
class NewGame
{
private:

    int x_value, y_value, difficulty = 1; // x_value & y_value is difference of player situation and snake situation
    const sf::String st = "Escape From Snake"; // title of game
    ///////////////// main menu & game environment window
    sf::RenderWindow Menu;
    sf::RenderWindow window;
    ///////////////// set game textures and sprites
    sf::Texture textur_mouse;
    sf::Texture textur_snake;
    sf::Texture textur_lose_game;
    sf::Texture textur_back;
    sf::Texture textur_start;
    sf::Texture textur_setting;
    sf::Texture textur_exit;
    sf::Texture textur_hard;
    sf::Texture textur_noraml;
    sf::Texture textur_back_setting;
    sf::Sprite sprit_mouse;
    sf::Sprite sprit_snake;
    sf::Sprite sprit_lose_game;
    sf::Sprite sprit_back;
    sf::Sprite sprit_start;
    sf::Sprite sprit_setting;
    sf::Sprite sprit_exit;
    sf::Sprite sprit_hard;
    sf::Sprite sprit_normal;
    sf::Sprite sprit_back_setting;
    ///////////////////////////////////// player & snake position
    sf::Vector2f pos_player;
    sf::Vector2f pos_snake; 
public:
    ///////////////////////////////////// set windows & player & snake
    void first_fixing();
    ///////////////////////////////////// set player & snake position after losing
    void fixing();
    ///////////////////////////////////// return difficulty of game 
    int get_difficulty();
    ///////////////////////////////////// clear & draw & disply attributes on game environment
    void show_game();
    ///////////////////////////////////// check keyboards event 
    void check_events();
    /////////////////////////////////////  rule of the game
    void run_algorithms();
    ///////////////////////////////////// open losing window
    void lose_window();
    ///////////////////////////////////// loop of engien
    void runing_game();
    ///////////////////////////////////// main menu
    void fix_menu();
};
#endif