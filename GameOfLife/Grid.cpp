#include "Grid.h"

Grid::Grid(int size) : gridSize(size) {

}

Grid::~Grid() {
    // Delete grid arrays
    for (int i = 0; i < gridSize; i++) {
        delete grid[i];
    }
    delete grid;
}

void Grid::initializeGrid() {
    for (int i = 0; i < gridSize; i++) {

    }
}