#ifndef GAMEOFLIFE_MODULE_H
#define GAMEOFLIFE_MODULE_H

#include <string>
#include <vector>
#include "Docent.h"

class Module {
public:
    Module(std::string name, int ec);
    virtual ~Module();

    int ec;
    std::string name;

    std::vector<Docent*>* docenten;
};

#endif
