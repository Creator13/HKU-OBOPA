#ifndef GAMEOFLIFE_GRID_H
#define GAMEOFLIFE_GRID_H

#include <string>

class Grid {
public:
    Grid(int size);
    ~Grid();

    std::string toString();
private:
    int gridSize;
    int** grid;

    void initializeGrid();
};

#endif
