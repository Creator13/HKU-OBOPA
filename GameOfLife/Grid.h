#ifndef GAMEOFLIFE_GRID_H
#define GAMEOFLIFE_GRID_H

#include <string>

class Grid {
public:
    int gridSize;

    Grid(int size);
    Grid(const Grid &_grid);
    ~Grid();

    bool getCell(int x, int y);
    void setCell(int x, int y, bool val);
    std::string toString();

private:
    bool **grid;

    void initializeGrid();
};

#endif
