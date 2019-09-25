cmake_minimum_required(VERSION 3.14)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameOfLife GameOfLife/gameOfLife_main.cpp GameOfLife/Grid.cpp GameOfLife/Grid.h GameOfLife/GameOfLife.cpp GameOfLife/GameOfLife.h GameOfLife/RuleSet.h GameOfLife/StandardRuleSet.cpp GameOfLife/StandardRuleSet.h)
add_executable(Schoolsysteem Schoolsysteem/main.cpp Schoolsysteem/Module.cpp Schoolsysteem/Module.h Schoolsysteem/Student.cpp Schoolsysteem/Student.h Schoolsysteem/Docent.cpp Schoolsysteem/Docent.h)