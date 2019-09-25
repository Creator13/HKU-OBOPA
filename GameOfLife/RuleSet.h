#ifndef GAMEOFLIFE_RULESET_H
#define GAMEOFLIFE_RULESET_H

#include "Grid.h"

class RuleSet {
public:
    RuleSet(Grid* grid);
    virtual void checkCell(int x, int y) = 0;
private:
    Grid* grid;
};

#endif
