#include <ctime>
#include <iostream>
#include "GameOfLife.h"

GameOfLife::GameOfLife(int gridSize, RuleSet *ruleSet) : grid(new Grid(gridSize)), temp(Grid(gridSize)),
                                                         rules(ruleSet) {
    seedRandom();
}

GameOfLife::~GameOfLife() {
    // Ruleset is not created by this class so it doesn't need to be deleted here
    delete grid;
}

void GameOfLife::tick() {
    system("CLS");

    temp.copy(grid);

    for (int i = 0; i < grid->gridSize; i++) {
        for (int j = 0; j < grid->gridSize; j++) {
            int neighbours = grid->countLiveNeighbors(i, j);
            bool cell = grid->getCell(i, j);

            temp.setCell(i, j, rules->getCellStatus(cell, neighbours));
        }
    }

    grid->copy(&temp);

    std::cout << grid->toString();
    std::cout << ++gen << std::endl;
}

void GameOfLife::seedRandom() {
    srand(time(nullptr));

    for (int i = 0; i < grid->gridSize; i++) {
        for (int j = 0; j < grid->gridSize; j++) {
            int r = rand() % 2;
            grid->setCell(i, j, static_cast<bool> (r));
        }
    }
}