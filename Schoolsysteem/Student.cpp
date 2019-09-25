#include "Student.h"

Student::Student(std::string name) : name(name), modules(new std::vector<Module*>) { }

Student::~Student() {
    delete modules;
}
