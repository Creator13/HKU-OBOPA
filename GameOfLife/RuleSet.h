#ifndef GAMEOFLIFE_RULESET_H
#define GAMEOFLIFE_RULESET_H

#include "Grid.h"

class RuleSet {
public:
    RuleSet() = default;

    virtual ~RuleSet() = default;

    virtual bool getCellStatus(bool current, int liveNeighbours) = 0;
};

#endif
