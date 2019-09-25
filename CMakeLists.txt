cmake_minimum_required(VERSION 3.14)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameOfLife GameOfLife/gameOfLife_main.cpp GameOfLife/Grid.cpp GameOfLife/Grid.h GameOfLife/GameOfLife.cpp GameOfLife/GameOfLife.h GameOfLife/RuleSet.cpp GameOfLife/RuleSet.h)