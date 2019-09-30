#ifndef GAMEOFLIFE_GRID_H
#define GAMEOFLIFE_GRID_H

#include <string>

class Grid {
public:
    int gridSize;

    Grid(int size);
    Grid(const Grid &_grid);
    ~Grid();

    void copy(Grid* grid);

    bool getCell(int x, int y);
    void setCell(int x, int y, bool val);

    int countLiveNeighbors(int x, int y);

    std::string toString();

private:
    bool **grid;

    void allocate();
    bool probePoint(int x, int y);
};

#endif
