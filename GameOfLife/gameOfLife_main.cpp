#include <iostream>
#include "Grid.h"
#include "GameOfLife.h"

using namespace std;

int main() {
    GameOfLife* game = new GameOfLife(25, nullptr);
    game->tick();
}