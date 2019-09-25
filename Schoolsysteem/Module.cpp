#include "Module.h"

Module::Module(std::string name, int ec) : ec(ec), name(name), docenten(new std::vector<Docent*>) { }

Module::~Module() {
    delete docenten;
}