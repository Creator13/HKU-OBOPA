#include <iostream>
#include "Decorator.h"

Decorator::Decorator(Actor* target) : target(target) { }

Decorator::~Decorator() {
    if (target) delete target;
}

void Decorator::draw() {
    std::cout << getMessage() << std::endl;
}

std::string Decorator::getMessage() {
    return target->getMessage();
}