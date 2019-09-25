#include <windows.h>
#include "Grid.h"
#include "GameOfLife.h"
#include "StandardRuleSet.h"

using namespace std;

int main() {
    StandardRuleSet *rules = new StandardRuleSet();
    GameOfLife *game = new GameOfLife(35, rules);
    while (game->gen < 1000) {
        game->tick();
        Sleep(100);
    }

    delete game;

    system("pause");
}