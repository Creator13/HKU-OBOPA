#include "StandardRuleSet.h"

void StandardRuleSet::runGeneration(Grid *grid) {
    Grid temp = Grid(grid->gridSize);
    temp.copy(grid);

    for (int i = 0; i < grid->gridSize; i++) {
        for (int j = 0; j < grid->gridSize; j++) {
            int neighbors = grid->countLiveNeighbors(i, j);
            bool cell = grid->getCell(i, j);

            if (!cell) {
                // Cell is born if there are exactly 3 neighbors
                if (neighbors == 3) {
                    temp.setCell(i ,j, true);
                }
            }
            else {
                // Cell dies if there are not exactly 2 or 3 neighbors
                if (neighbors < 2 || neighbors > 3) {
                    temp.setCell(i, j, false);
                }
            }
        }
    }

    grid->copy(temp);
}
