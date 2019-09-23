#ifndef GAMEOFLIFE_GAMEOFLIFE_H
#define GAMEOFLIFE_GAMEOFLIFE_H


#include "Grid.h"
#include "RuleSet.h"

class GameOfLife {
public:
    GameOfLife();
    ~GameOfLife();

    void tick();
private:
    unsigned int gen;
    Grid* grid;
    RuleSet* rules;
};


#endif
