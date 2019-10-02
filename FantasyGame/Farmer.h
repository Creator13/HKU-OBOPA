#ifndef GAMEOFLIFE_FARMER_H
#define GAMEOFLIFE_FARMER_H


#include "Decorator.h"

class Farmer : public Decorator {
public:
    explicit Farmer(Actor* target);
    virtual ~Farmer();

    std::string getMessage() override;
};


#endif //GAMEOFLIFE_FARMER_H
