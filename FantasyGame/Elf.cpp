#include "Elf.h"

std::string Elf::getMessage() {
    return "Hello I am elf and my name is " + getName();
}

Elf::Elf(std::string name) {
    this->name = name;
}
