#include "Grid.h"

Grid::Grid(int size) : gridSize(size) {
    initializeGrid();
}

Grid::Grid(const Grid &_src) : gridSize(_src.gridSize){
    initializeGrid();

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

void Grid::initializeGrid() {
    grid = new bool*[gridSize];
    for (int i = 0; i < gridSize; i++) {
        grid[i] = new bool[gridSize];

        for (int j = 0; j < gridSize; j++) {
            setCell(i, j, false);
        }
    }
}

void Grid::setCell(int x, int y, bool val) {
    grid[x][y] = val;
}

bool Grid::getCell(int x, int y) {
    return grid[x][y];
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
