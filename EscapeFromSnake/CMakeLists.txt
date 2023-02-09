cmake_minimum_required(VERSION 3.0)
project(EscapeFromSnake)
set(CMAKE_CXX_STANDARD 11)

add_executable(app main.cpp
                src/New_Game.cpp
                src/User.cpp
                src/Snake.cpp)
target_link_libraries(app sfml-window sfml-system sfml-graphics)