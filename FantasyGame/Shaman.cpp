#include "Shaman.h"

Shaman::Shaman(Actor* target) : Decorator(target) { }

Shaman::~Shaman() { }

std::string Shaman::getMessage() {
    return Decorator::getMessage() + "\n" +
           "- I am a shaman";
}
