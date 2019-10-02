#include "Orc.h"

std::string Orc::getMessage() {
    return "HelLo I iS oRC. I cAlLEd " + getName();
}

Orc::Orc(std::string name) {
    this->name = name;
}
