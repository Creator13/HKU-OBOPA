#include <iostream>
#include "Actor.h"

Actor::~Actor() = default;

Actor::Actor() { };

void Actor::draw() {
    std::cout << getMessage() << std::endl;
}

std::string Actor::getName() const {
    return this->name;
}
