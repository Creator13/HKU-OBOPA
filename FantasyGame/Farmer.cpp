#include "Farmer.h"

Farmer::Farmer(Actor* target) : Decorator(target) { }

Farmer::~Farmer() { }

std::string Farmer::getMessage() {
    return Decorator::getMessage() + "\n" +
           "- I am a farmer";
}
