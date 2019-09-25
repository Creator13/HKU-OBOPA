#ifndef GAMEOFLIFE_RULESET_H
#define GAMEOFLIFE_RULESET_H

#include "Grid.h"

class RuleSet {
public:
    RuleSet() = default;

    virtual ~RuleSet() = default;

    virtual void runGeneration(Grid *grid) = 0;
};

#endif
