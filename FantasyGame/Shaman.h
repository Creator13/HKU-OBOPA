#ifndef GAMEOFLIFE_SHAMAN_H
#define GAMEOFLIFE_SHAMAN_H


#include "Decorator.h"

class Shaman : public Decorator {
public:
    explicit Shaman(Actor* target);
    virtual ~Shaman();

    std::string getMessage() override;
};


#endif //GAMEOFLIFE_SHAMAN_H
