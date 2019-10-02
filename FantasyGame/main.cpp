#include "Elf.h"
#include "Orc.h"
#include "Farmer.h"
#include "Shaman.h"
#include "Soldier.h"

int main() {
    Actor* a1 = new Farmer(new Elf("Foo"));
    a1 = new Shaman(a1);

    Actor* a2 = new Shaman(new Soldier(new Orc("Bar")));

    a1->draw();
    a2->draw();

    delete a1;
    delete a2;
}