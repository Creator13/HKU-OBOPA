#include <iostream>
#include "Parent.h"

Parent::Parent(std::string name) {
    std::cout << "Parent ctor : " << name << std::endl;
    this->name = name;
    std::string childName = "ChildOf" + name;
//    this->child = new Child(childName);
    this->child = std::make_unique<Child>(childName);
}

Parent::Parent(const Parent &other) {
    std::cout << "Parent cctor" << std::endl;
    this->name = other.name;
//    this->child = new Child(*other.child);
    this->child = std::make_unique<Child>(*other.child);
}

Parent::~Parent() {
    std::cout << "Parent dtor : " << this->name << std::endl;
}

Parent &Parent::operator=(const Parent &other) {
    std::cout << "Parent assignment" << std::endl;

    if (this == &other) return *this;

    this->name = other.name;
//    this->child = new Child(*other.child);
    this->child = std::make_unique<Child>(*other.child);

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Parent &parent) {
    os << "parent name: " << parent.name << "," << *parent.child;
    return os;
}
