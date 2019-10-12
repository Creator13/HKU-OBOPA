#include <iostream>
#include "Parent.h"

int main() {
    Parent* p1 = new Parent("Parent1");
    std::cout << "p1:" << *p1 << std::endl;

    Parent* p2 = new Parent(*p1); // roept de copy constructor aan
    std::cout << "p2:" << *p2 << std::endl;

    Parent* p3 = new Parent("Parent3");
    std::cout << "p3:" << *p3 << std::endl;

    *p3 = *p1; // roept de assignment operator aan
    std::cout << "p1:" << *p3 << std::endl;

    delete p1;
    delete p2;
    delete p3;

    std::cout << std::endl;
    // Stap 2 van de opdracht
    auto parentPtr = std::make_shared<Parent>("NewParent");
    auto parentPtr2 = parentPtr;
    auto parentPtr3 = parentPtr;
    auto parentPtr4 = parentPtr;

    std::cout << "Reference count after creating three copies of the original: " << parentPtr.use_count() << std::endl;
    // Hier wordt de opdracht zeer onduidelijk...
    // "Verwijder een Child van één van de Parents, en toon de Child count van de andere Parents"
    // De child is een unique_pointer en kan daarom alleen maar verwijderd worden door hem out of scope te laten gaan
    // Bovendien is deze private en dus niet accessible.
    // En daarbij heeft de parent geen childcount.

    // Maar expected behaviour is dat de childcount hetzelfde wordt voor alle parentptrs als je bij één de child
    // verwijderd, omdat het achter de schermen maar één object is. Het zijn tenslotte pointers.

    return 0;
}