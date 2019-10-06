#include "StandardRuleSet.h"

bool StandardRuleSet::getCellStatus(bool current, int liveNeighbours) {
    if (!current) {
        // Cell is born if there are exactly 3 neighbors
        if (liveNeighbours == 3) {
            return true;
        }
    }
    else {
        // Cell dies if there are not exactly 2 or 3 neighbors
        if (liveNeighbours < 2 || liveNeighbours > 3) {
            return false;
        }
    }

    // Cell remains unchanged if neither condition is true
    return current;
}
