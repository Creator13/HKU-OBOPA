#ifndef GAMEOFLIFE_ELF_H
#define GAMEOFLIFE_ELF_H


#include "Actor.h"

class Elf : public Actor {
public:
    explicit Elf(std::string name);
    virtual ~Elf() = default;
protected:
    std::string getMessage() override;
};


#endif
