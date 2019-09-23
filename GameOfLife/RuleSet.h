#ifndef GAMEOFLIFE_RULESET_H
#define GAMEOFLIFE_RULESET_H

#include "Cell.h"

class RuleSet {
public:
    virtual void checkCell(Cell* cell) = 0;
};

#endif
