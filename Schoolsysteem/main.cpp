#include <iostream>
#include "Module.h"
#include "Student.h"

using namespace std;

auto modules = vector<Module*>();
auto studenten = vector<Student*>();
auto docenten = vector<Docent*>();

void printStudents();

// TODO CLEAN THIS FILE UP

int main() {
    auto* oop = new Module("Object-Oriented Programming", 2);
    auto* vrij = new Module("Project Vrij", 5);
    auto* kern = new Module("Kernmodule 1", 4);

    modules.push_back(oop);
    modules.push_back(vrij);
    modules.push_back(kern);

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

    auto* edwin = new Docent("Edwin van Ouwerkerk Moria");
    auto* valentijn = new Docent("Valentijn Muijrers");
    auto* aaron = new Docent("Aaron Oostdijk");

    docenten.push_back(edwin);
    docenten.push_back(valentijn);
    docenten.push_back(aaron);

    vrij->docenten->push_back(edwin);
    vrij->docenten->push_back(aaron);
    vrij->docenten->push_back(valentijn);
    kern->docenten->push_back(valentijn);
    kern->docenten->push_back(aaron);
    oop->docenten->push_back(edwin);

    auto student_i = studenten.begin();
    int n = 0;
    while (student_i != studenten.end()) {
        (*student_i)->modules->push_back(vrij);

        if (n % 2 == 0) {
            (*student_i)->modules->push_back(kern);
        }
        if (n % 3 == 0) {
            (*student_i)->modules->push_back(oop);
        }

        student_i++;
        n++;
    }

    /////// PRINTING
    cout << "Docenten: " << endl;
    auto docent_i = docenten.begin();
    while (docent_i != docenten.end()) {
        cout << (*docent_i)->name << endl;
        docent_i++;
    }

    printStudents();

    cout << "-----------" << endl;
    cout << "Modules: " << endl;
    auto module_i = modules.begin();
    while (module_i != modules.end()) {
        cout << (*module_i)->name << endl;
        module_i++;
    }

    oop->ec = 10;

    printStudents();
}

void printStudents() {
    cout << "-----------" << endl;
    cout << "Studenten: " << endl;
    auto student_i = studenten.begin();
    while (student_i != studenten.end()) {
        auto studentModules = (*student_i)->modules;
        auto studentModules_i = studentModules->begin();
        int total_ec = 0;
        while (studentModules_i != studentModules->end()) {
            total_ec += (*studentModules_i)->ec;
            studentModules_i++;
        }

        cout << (*student_i)->name << " | " << total_ec << "EC" << endl;
        student_i++;
    }
}