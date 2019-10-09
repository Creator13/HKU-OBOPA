cmake_minimum_required(VERSION 3.14)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameOfLife GameOfLife/gameOfLife_main.cpp GameOfLife/Grid.cpp GameOfLife/Grid.h GameOfLife/GameOfLife.cpp GameOfLife/GameOfLife.h GameOfLife/RuleSet.h GameOfLife/StandardRuleSet.cpp GameOfLife/StandardRuleSet.h)
add_executable(Schoolsysteem Schoolsysteem/main.cpp Schoolsysteem/Module.cpp Schoolsysteem/Module.h Schoolsysteem/Student.cpp Schoolsysteem/Student.h Schoolsysteem/Docent.cpp Schoolsysteem/Docent.h)
add_executable(Bankrekening Bankrekening/BankAccount.cpp Bankrekening/BankAccount.h Bankrekening/Transaction.cpp Bankrekening/Transaction.h Bankrekening/main.cpp)
add_executable(FantasyGame FantasyGame/main.cpp FantasyGame/Actor.cpp FantasyGame/Actor.h FantasyGame/Elf.cpp FantasyGame/Elf.h FantasyGame/Orc.cpp FantasyGame/Orc.h FantasyGame/Decorator.cpp FantasyGame/Decorator.h FantasyGame/Farmer.cpp FantasyGame/Farmer.h FantasyGame/Soldier.cpp FantasyGame/Soldier.h FantasyGame/Shaman.cpp FantasyGame/Shaman.h)
add_executable(AlgorithmsOpdracht AlgorithmsOpdracht/main.cpp)
add_executable(ConcurrentVector ConcurrentVector/main.cpp ConcurrentVector/concurrent_vector.h)
add_executable(TemplateOpdracht TemplateOpdracht/main.cpp TemplateOpdracht/SortArray.h TemplateOpdracht/Queue.h)