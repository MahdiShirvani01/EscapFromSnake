/*
Mehdi Shirvani
40012358021
*/
#include "../include/User.hpp"
#include "../include/New_Game.hpp"
#include "../include/Snake.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#define icon_size 0.3

///////////////////////////////////// User class get random situation to player
User pl;
///////////////////////////////////// Snake class get random situation to snake
Snake sk;
///////////////////////////////////// menu actions
void NewGame::fix_menu()
{
    ///////////////////////////////////// main menu window
    Menu.create(sf::VideoMode(1000, 500), "Main Menu", sf::Style::Default);

    ///////////////////////////////////// set buttons textur and sprit
    textur_start.loadFromFile("../asserts/start.jpg"); // start
    sprit_start.setTexture(textur_start);
    sprit_start.setScale(icon_size, icon_size);
    sprit_start.setPosition(450, 200);

    textur_setting.loadFromFile("../asserts/setting.jpg"); // setting
    sprit_setting.setTexture(textur_setting);
    sprit_setting.setScale(icon_size, icon_size);
    sprit_setting.setPosition(300, 200);

    textur_exit.loadFromFile("../asserts/exit.jpg"); // exit
    sprit_exit.setTexture(textur_exit);
    sprit_exit.setScale(icon_size, icon_size);
    sprit_exit.setPosition(600, 200);

    textur_hard.loadFromFile("../asserts/hard.jpg"); // setting/hard
    sprit_hard.setTexture(textur_hard);
    sprit_hard.setScale(0.4, 0.4);
    sprit_hard.setPosition(300, 200);

    textur_noraml.loadFromFile("../asserts/normal.jpg"); // setting/normal
    sprit_normal.setTexture(textur_noraml);
    sprit_normal.setScale(0.4, 0.4);
    sprit_normal.setPosition(600, 200);

    textur_back_setting.loadFromFile("../asserts/back.jpg"); // setting/back
    sprit_back_setting.setTexture(textur_back_setting);
    sprit_back_setting.setScale(0.3, 0.3);
    sprit_back_setting.setPosition(10, 10);

    Menu.setFramerateLimit(60);

    while (Menu.isOpen())
    {   
        Menu.clear(sf::Color(200, 200, 200));
        Menu.draw(sprit_start);
        Menu.draw(sprit_setting);
        Menu.draw(sprit_exit);
        Menu.display();
        ///////////////////////////////////// mouse and keys event
        sf::Event event_main;
        while (Menu.pollEvent(event_main))
        {
            switch (event_main.type)
                {
                ///////////////////////////////////// close the window
                case sf::Event::EventType::Closed:
                    Menu.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if(event_main.mouseButton.button == sf::Mouse::Button::Left)
                    {
                        ///////////////////////////////////// exit button region
                        if(event_main.mouseButton.x >= 600 && event_main.mouseButton.x <= 670
                                    && event_main.mouseButton.y >= 200 && event_main.mouseButton.y <= 270)
                        {
                            Menu.close();
                            window.close();
                        }
                        ///////////////////////////////////// start button region
                        if(event_main.mouseButton.x >= 450 && event_main.mouseButton.x <= 520
                                    && event_main.mouseButton.y >= 200 && event_main.mouseButton.y <= 270)
                        {
                            first_fixing();
                            runing_game();
                        }
                        ///////////////////////////////////// setting button region
                        if(event_main.mouseButton.x >= 300 && event_main.mouseButton.x <= 370
                                    && event_main.mouseButton.y >= 200 && event_main.mouseButton.y <= 270)
                        {
                            Menu.clear(sf::Color(20, 40, 60));
                            while (Menu.isOpen())
                            {
                                Menu.draw(sprit_normal);
                                Menu.draw(sprit_hard);
                                Menu.draw(sprit_back_setting);
                                Menu.display();
                                sf::Event event_setting;
                                while (Menu.pollEvent(event_setting))
                                {
                                    switch(event_setting.type)
                                    {
                                        case sf::Event::EventType::Closed: // close window
                                            Menu.close();
                                            break;
                                        case sf::Event::MouseButtonPressed:
                                            if(event_setting.mouseButton.button == sf::Mouse::Button::Left)
                                            {   
                                                ///////////////////////////////// hard button in setting
                                                if(event_setting.mouseButton.x >= 300 && event_setting.mouseButton.x <= 380
                                                    && event_setting.mouseButton.y >= 200 && event_setting.mouseButton.y <= 260)
                                                {
                                                    difficulty = 2;
                                                    fix_menu();
                                                }
                                                ///////////////////////////////// normal button in setting
                                                if(event_setting.mouseButton.x >= 600 && event_setting.mouseButton.x <= 680
                                                    && event_setting.mouseButton.y >= 200 && event_setting.mouseButton.y <= 260)
                                                {
                                                    difficulty = 1;
                                                    fix_menu();
                                                }
                                                ///////////////////////////////// back button in setting
                                                if(event_setting.mouseButton.x >= 20 && event_setting.mouseButton.x <= 80
                                                    && event_setting.mouseButton.y >= 20 && event_setting.mouseButton.y <= 80)
                                                {
                                                    fix_menu();
                                                }
                                            }
                                            break;
                                    }       
                                }
                            }
                        }
                    }
                    break;
                ///////////////////////////////////// close the main menu with escape
                case sf::Event::EventType::KeyReleased:
                    if(event_main.key.code == sf::Keyboard::Key::Escape)
                        Menu.close();
                    break;
                default:
                    break;
                }
        }
    }
}
void NewGame::first_fixing()
{
    ///////////////////////////////////// when snake situation & player situation is not eqal, can continue
    while (sk.x_situation_snake() == pl.x_situation() && sk.y_situation_snake() == pl.y_situation() &&
                            abs(sk.x_situation_snake() - pl.x_situation()) < 200 && abs(sk.y_situation_snake() - pl.y_situation()) < 200)
        {
            ///////////////////////////////////// set random situation for snake
            sk.set_location_snake();
            ///////////////////////////////////// set random situation for player
            pl.set_location();
        }
    ///////////////////////////////////// game environment window
    window.create(sf::VideoMode(1000, 500), st, sf::Style::Default);
    
    textur_mouse.loadFromFile("../asserts/mouse.jpg"); // player
    sprit_mouse.setTexture(textur_mouse);
    sprit_mouse.setScale(0.150, 0.150);
    sprit_mouse.setPosition(pl.x_situation(), pl.y_situation());

    textur_snake.loadFromFile("../asserts/snake.jpg");// snake
    sprit_snake.setTexture(textur_snake);
    sprit_snake.setScale(0.2, 0.2);
    sprit_snake.setPosition(sk.x_situation_snake(), sk.y_situation_snake());

    ///////////////////////////////////// lose texture & sprite
    textur_lose_game.loadFromFile("../asserts/lose.jpg");
    sprit_lose_game.setTexture(textur_lose_game);
    sprit_lose_game.setScale(1, 1);
    sprit_lose_game.setPosition(400, 100);
    ///////////////////////////////////// back texture & sprite
    textur_back.loadFromFile("../asserts/back.jpg");
    sprit_back.setTexture(textur_back);
    sprit_back.setScale(0.3, 0.3);
    sprit_back.setPosition(10, 10);

    window.setFramerateLimit(60);
 
    ///////////////////////////////////// sprites position
    pos_player = sprit_mouse.getPosition();
    pos_snake = sprit_snake.getPosition();
    ///////////////////////////////////// diffrece between sprites positioin
    x_value = abs(pos_player.x - pos_snake.x);
    y_value = abs(pos_player.y - pos_snake.y);
}
void NewGame::fixing()
{
    window.clear();
    ///////////////////////////////////// set again situations
    while (sk.x_situation_snake() == pl.x_situation() && sk.y_situation_snake() == pl.y_situation() &&
            abs(sk.x_situation_snake() - pl.x_situation()) < 150 && abs(sk.y_situation_snake() - pl.y_situation()) < 150)
        {
            sk.set_location_snake();
            pl.set_location();
        }
    sprit_snake.setPosition(sk.x_situation_snake(), sk.y_situation_snake());
    sprit_mouse.setPosition(pl.x_situation(), pl.y_situation());

    pos_player = sprit_mouse.getPosition();
    pos_snake = sprit_snake.getPosition();

    x_value = abs(pos_player.x - pos_snake.x);
    y_value = abs(pos_player.y - pos_snake.y);
}
///////////////////////////////////// get difficulty of game from user in ui
int NewGame::get_difficulty()
{
    return difficulty;
}
void NewGame::run_algorithms()
{
    ///////////////////////////////////// if player & snake position is eqal you lose the game
    if((pos_player.x == pos_snake.x || (pos_player.x - pos_snake.x < 40) && (pos_snake.x - pos_player.x < 20)) && pos_player.y == pos_snake.y) // player position is equal with snake position
        {
            lose_window();
        }
        else if(x_value > y_value)
        {
            if(y_value == 0)
            {
                if(pos_player.x > pos_snake.x)
                {
                    if(get_difficulty() == 1) // python
                    {
                        sprit_snake.move(0.5, 0);
                        pos_snake.x += 0.5;
                    }
                    else
                    {
                        sprit_snake.move(1.5, 0); // boa
                        pos_snake.x += 1.5;
                    }
                }
                else if(pos_player.x < pos_snake.x)
                {
                    if(get_difficulty() == 1) // python
                    {
                        sprit_snake.move(-0.5, 0);
                        pos_snake.x -= 0.5;
                    }
                    else
                    {
                        sprit_snake.move(-1.5, 0); // boa
                        pos_snake.x -= 1.5;
                    }
                }
            }
            if(pos_player.y > pos_snake.y)
            {
                if(get_difficulty() == 1) // python
                {
                    sprit_snake.move(0, 1);
                    pos_snake.y += 1;
                }
                else
                {
                    sprit_snake.move(0, 1); // boa
                    pos_snake.y += 1;
                }
            }
            else if(pos_player.y < pos_snake.y)
            {
                if(get_difficulty() == 1) // python
                {
                    sprit_snake.move(0, -1);
                    pos_snake.y -= 1;
                }
                else
                {
                    sprit_snake.move(0, -1); // boa
                    pos_snake.y -= 1;
                }
            }
        }
        else if(x_value < y_value)
        {
            if(x_value == 0)
            {
                if(pos_player.y > pos_snake.y)
                {
                    if(get_difficulty() == 1) // python
                    {
                        sprit_snake.move(0, 1);
                        pos_snake.y += 1;
                    }
                    else
                    {
                        sprit_snake.move(0, 1); // boa
                        pos_snake.y += 1;
                    }
                }
                else if(pos_player.y < pos_snake.y)
                {
                    if(get_difficulty() == 1)
                    {
                        sprit_snake.move(0, -1); // python
                        pos_snake.y -= 1;
                    }
                    else
                    {
                        sprit_snake.move(0, -1); // boa
                        pos_snake.y -= 1;
                    }
                }
            }
            if(pos_player.x > pos_snake.x)
            {
                if(get_difficulty() == 1) // python
                {
                    sprit_snake.move(0.5, 0);
                    pos_snake.x += 0.5;
                }
                else
                {
                    sprit_snake.move(1.5, 0); // boa
                    pos_snake.x += 1.5;
                }
            }
            else if(pos_player.x < pos_snake.x)
            {
                if(get_difficulty() == 1) // python
                {
                    sprit_snake.move(-0.5, 0);
                    pos_snake.x -= 0.5;
                }
                else
                {
                    sprit_snake.move(-1.5, 0); // boa
                    pos_snake.x -= 1.5;
                }
            }
        }
}
void NewGame::check_events()
{
    sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::EventType::Closed: // close window
                window.close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Right)
                {   
                    if(pos_player.x < 980)
                    {
                        sprit_mouse.move(5, 0);
                        pos_player.x += 5;
                    }          
                }
                else if(event.key.code == sf::Keyboard::Up)
                {
                    if(pos_player.y > 10)
                    {
                        sprit_mouse.move(0, -5);
                        pos_player.y -= 5;
                    }
                }
                else if(event.key.code == sf::Keyboard::Left)
                {   
                    if(pos_player.x > 10)
                    {
                        sprit_mouse.move(-5, 0);
                        pos_player.x -= 5;
                    }
                }
                else if(event.key.code == sf::Keyboard::Down)
                {
                    if(pos_player.y < 480)
                    {
                        sprit_mouse.move(0, 5);
                        pos_player.y += 5;
                    }
                }
            default:
                break;
            }
        }
}
void NewGame::show_game()
{
    window.clear();
    window.draw(sprit_mouse);
    window.draw(sprit_snake);
    window.display();
}

void NewGame::lose_window()
{
  
    window.clear(sf::Color::Red);
    while (window.isOpen())
    {
        window.draw(sprit_lose_game);
        window.draw(sprit_back);
        window.display();
        sf::Event ev2;
        while (window.pollEvent(ev2))
        {
            switch(ev2.type)
            {
                case sf::Event::EventType::Closed: // close window
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if(ev2.mouseButton.button == sf::Mouse::Button::Left)
                    {
                        if(ev2.mouseButton.x <= sprit_back.getPosition().x + 70 && ev2.mouseButton.y <= sprit_back.getPosition().y + 70)
                        {
                            fixing();
                            window.close();
                        }
                    }
                    break;
            }       
        }
    }
}
void NewGame::runing_game()
{
    sf::sleep(sf::seconds(2));
    while (window.isOpen())
    {
        run_algorithms();
        show_game();
        check_events();
    }
}