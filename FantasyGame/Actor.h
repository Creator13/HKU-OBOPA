#ifndef GAMEOFLIFE_ACTOR_H
#define GAMEOFLIFE_ACTOR_H


#include <string>

class Actor {
public:
    explicit Actor();
    virtual ~Actor();

    virtual void draw();
    std::string getName() const;

    virtual std::string getMessage() = 0;
protected:
    std::string name;
};


#endif
