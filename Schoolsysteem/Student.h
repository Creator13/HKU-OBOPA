#ifndef GAMEOFLIFE_STUDENT_H
#define GAMEOFLIFE_STUDENT_H

#include <string>
#include <vector>
#include "Module.h"

class Student {
public:
    Student(std::string name);
    ~Student();

    std::string name;
    std::vector<Module*>* modules;
};

#endif
