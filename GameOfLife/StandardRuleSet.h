#ifndef GAMEOFLIFE_STANDARDRULESET_H
#define GAMEOFLIFE_STANDARDRULESET_H

#include "RuleSet.h"

class StandardRuleSet : public RuleSet {
    void runGeneration(Grid* grid) override;

};

#endif
