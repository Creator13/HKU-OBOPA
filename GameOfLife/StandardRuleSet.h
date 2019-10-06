#ifndef GAMEOFLIFE_STANDARDRULESET_H
#define GAMEOFLIFE_STANDARDRULESET_H

#include "RuleSet.h"

class StandardRuleSet : public RuleSet {
//    void runGeneration(Grid* grid) override;
    bool getCellStatus(bool current, int liveNeighbours) override;
};

#endif
