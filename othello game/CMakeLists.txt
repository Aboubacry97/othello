cmake_minimum_required(VERSION 3.25)
project(othello)

set(CMAKE_CXX_STANDARD 17)

add_executable(othello main.cpp Game.h Game.cpp Board.h Board.cpp Position.h Position.cpp playablepositions.cpp playablepositions.h changeColours.h changeColours.cpp)
