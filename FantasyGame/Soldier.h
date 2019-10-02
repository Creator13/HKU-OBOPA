#ifndef GAMEOFLIFE_SOLDIER_H
#define GAMEOFLIFE_SOLDIER_H


#include "Decorator.h"

class Soldier : public Decorator {
public:
    explicit Soldier(Actor* target);
    virtual ~Soldier();

    std::string getMessage() override;
};


#endif //GAMEOFLIFE_SOLDIER_H
