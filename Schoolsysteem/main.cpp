#include <iostream>
#include "Module.h"
#include "Student.h"

using namespace std;

auto modules = vector<Module *>();
auto studenten = vector<Student *>();
auto docenten = vector<Docent *>();

void printStudents();

int main() {
    // Create modules
    auto *oop = new Module("Object-Oriented Programming", 2);
    auto *vrij = new Module("Project Vrij", 5);
    auto *kern = new Module("Kernmodule 1", 4);

    // Collect modules in vector
    modules.push_back(oop);
    modules.push_back(vrij);
    modules.push_back(kern);

    // Create studenten in vector
    studenten.push_back(new Student("Maria"));
    studenten.push_back(new Student("Peter"));
    studenten.push_back(new Student("Jeroen"));
    studenten.push_back(new Student("Martijn"));
    studenten.push_back(new Student("Anne"));
    studenten.push_back(new Student("Marijn"));
    studenten.push_back(new Student("Nick"));
    studenten.push_back(new Student("Laura"));
    studenten.push_back(new Student("Ellie"));
    studenten.push_back(new Student("Marit"));

    // Create docenten
    auto *edwin = new Docent("Edwin van Ouwerkerk Moria");
    auto *valentijn = new Docent("Valentijn Muijrers");
    auto *aaron = new Docent("Aaron Oostdijk");

    // Collect docenten in vector
    docenten.push_back(edwin);
    docenten.push_back(valentijn);
    docenten.push_back(aaron);

    // Assign docenten to modules
    vrij->docenten->push_back(edwin);
    vrij->docenten->push_back(aaron);
    vrij->docenten->push_back(valentijn);
    kern->docenten->push_back(valentijn);
    kern->docenten->push_back(aaron);
    oop->docenten->push_back(edwin);

    // Assign modules to studenten
    // For demo: every student gets vrij, every second one gets kern and every third one gets oop
    int n = 0;
    for (auto &student : studenten) {
        student->modules->push_back(vrij);

        if (n % 2 == 0) {
            student->modules->push_back(kern);
        }
        if (n % 3 == 0) {
            student->modules->push_back(oop);
        }

        n++;
    }

    // Print everything
    cout << "Docenten: " << endl;
    for (auto &docent : docenten) {
        cout << docent->name << endl;
    }

    cout << "-----------" << endl;

    printStudents();

    cout << "-----------" << endl;

    cout << "Modules: " << endl;
    for (auto &module : modules) {
        cout << module->name << endl;
    }

    // Change EC of one course
    oop->ec = 10;
    cout << "------ OOP has now 10 EC! ------" << endl;

    // Show that the EC changes for all students
    printStudents();
}

void printStudents() {
    cout << "Studenten: " << endl;
    for (auto &student : studenten) {
        int total_ec = 0;
        for (auto &module : *student->modules) {
            total_ec += module->ec;
        }

        cout << student->name << " | " << total_ec << "EC" << endl;
    }
}