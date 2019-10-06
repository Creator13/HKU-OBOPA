#include <stdexcept>
#include "Grid.h"

Grid::Grid(int size) : gridSize(size) {
    allocate();
}

Grid::Grid(const Grid &_src) : gridSize(_src.gridSize) {
    allocate();

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            setCell(i, j, _src.grid[i][j]);
        }
    }
}

Grid::~Grid() {
    // Delete grid arrays
    for (int i = 0; i < gridSize; i++) {
        delete grid[i];
    }
    delete grid;
}

void Grid::copy(Grid* other) {
    if (other->gridSize != gridSize) {
        throw std::invalid_argument("grids must be of the same size");
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            setCell(i, j, other->getCell(i, j));
        }
    }
}

void Grid::allocate() {
    grid = new bool *[gridSize];
    for (int i = 0; i < gridSize; i++) {
        grid[i] = new bool[gridSize];
    }
}

void Grid::setCell(int x, int y, bool val) {
    grid[x][y] = val;
}

bool Grid::getCell(int x, int y) {
    return grid[x][y];
}

int Grid::countLiveNeighbors(int x, int y) {
    int count = 0;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            // Exclude the cell itself
            if (i == x && j == y) continue;

            if (probePoint(i, j) && getCell(i, j)) {
                count++;
            }
        }
    }

    return count;
}

bool Grid::probePoint(int x, int y) {
    return x >= 0 && y >= 0 && x < gridSize && y < gridSize;
}

std::string Grid::toString() {
    std::string gridStr;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            bool cell = getCell(i, j);

            // Use a * for live cells and a 0 for dead ones
            char c = cell ? '*' : '0';
            gridStr += c;

            // Add a space unless it's the end of the line
            gridStr += j != gridSize - 1 ? " " : "";
        }
        gridStr += "\n";
    }

    return gridStr;
}
