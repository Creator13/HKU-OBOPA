#ifndef GAMEOFLIFE_GAMEOFLIFE_H
#define GAMEOFLIFE_GAMEOFLIFE_H


#include "Grid.h"
#include "RuleSet.h"

class GameOfLife {
public:
    GameOfLife(int gridSize, RuleSet *ruleSet);

    ~GameOfLife();

    void tick();

private:
    unsigned int gen{0};
    Grid *grid;
    RuleSet *rules;

    void seedRandom();
};


#endif
