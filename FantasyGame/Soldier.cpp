#include "Soldier.h"

Soldier::Soldier(Actor* target) : Decorator(target) { }

Soldier::~Soldier() { }

std::string Soldier::getMessage() {
    return Decorator::getMessage() + "\n" +
           "- I am a soldier";
}
