#include <ctime>
#include <iostream>
#include "GameOfLife.h"

GameOfLife::GameOfLife(int gridSize, RuleSet* ruleSet) : grid(new Grid(gridSize)), rules(ruleSet) {
    seedRandom();
}

GameOfLife::~GameOfLife() {
    // Ruleset is not created by this class so it doesn't need to be deleted here
    delete grid;
}

void GameOfLife::tick() {
    std::cout << grid->toString();
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