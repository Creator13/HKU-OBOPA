#ifndef GAMEOFLIFE_ORC_H
#define GAMEOFLIFE_ORC_H


#include "Actor.h"

class Orc : public Actor {
public:
    explicit Orc(std::string name);
    virtual ~Orc() = default;
protected:
    std::string getMessage() override;
};


#endif
