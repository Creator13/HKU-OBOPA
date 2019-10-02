#ifndef GAMEOFLIFE_DECORATOR_H
#define GAMEOFLIFE_DECORATOR_H


#include "Actor.h"

class Decorator : public Actor {
public:
    explicit Decorator(Actor* target);
    virtual ~Decorator();

    void draw() override;
protected:
    std::string getMessage() override;
private:
    Actor* target;
};


#endif //GAMEOFLIFE_DECORATOR_H
