#ifndef GAMEOFLIFE_GAMEOFLIFE_H
#define GAMEOFLIFE_GAMEOFLIFE_H


#include "Grid.h"
#include "RuleSet.h"

class GameOfLife {
public:
    unsigned int gen{0};

    GameOfLife(int gridSize, RuleSet *ruleSet);
    ~GameOfLife();
    void tick();

private:
    Grid *grid;
    Grid temp;
    RuleSet *rules;

    void seedRandom();
};


#endif
