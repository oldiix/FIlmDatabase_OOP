#include "Actor.h"
#include <iostream>
#include <ostream>
#include "Person.h"

Actor::Actor() : Person(), filmsIn(0) {}

Actor::Actor(const std::string& nm, int a, const std::string& n, int f)
    : Person(nm, a, n), filmsIn(f) {}

Actor::Actor(const Actor& other)
    : Person(other), filmsIn(other.filmsIn) {}

Actor::Actor(Actor&& other) noexcept
    : Person(std::move(other)), filmsIn(other.filmsIn) {
    other.filmsIn = 0;
}

int Actor::getfilmsIn() const { return filmsIn; }
void Actor::setfilmsIn(int m) { filmsIn = m; }

void Actor::displayInfo() const
{
    std::cout << "Actor: " << name << ", Age: " << age << ", Films acted in : " << filmsIn << std::endl;
}

void Actor::demonstrateBasePointer() {
    std::cout << "Demonstrate base pointer" << std::endl;
    Actor actor("Jake Gyllenhaal", 44, "American", 48);
    Person* personPtr = &actor;

    personPtr->displayInfo();
    std::cout << "Info (role): " << personPtr->getRole() << std::endl;
}