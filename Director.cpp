#include "Director.h"

#include <iostream>
#include <ostream>

#include "Person.h"

Director::Director() : Person(), filmsDirected(0) {}

Director::Director(const std::string& nm, int a, const std::string& n, int fd)
    : Person(nm, a, n), filmsDirected(fd) {}

Director::Director(const Director& other)
    : Person(other), filmsDirected(other.filmsDirected) {}

Director::Director(Director&& other) noexcept
    : Person(std::move(other)), filmsDirected(other.filmsDirected)
{
    other.filmsDirected = 0;
}

int Director::getFilmsDirected() const { return filmsDirected; }
void Director::setFilmsDirected(int fd) { filmsDirected = fd; }

void Director::displayInfo() const
{
    std::cout << "Director: " << name << " , Age: " << age << " , Films directed: " << filmsDirected << std::endl;
}

void Director::uniqueDirectorMethod()
{
    std::cout << "Example of method which can't be overriden\n";
}

void Director::demonstrateBaseReference() {
    std::cout << "Demonstrate base reference" << std::endl;
    Director director("Steven Spielberg", 75, "American", 50);
    Person& personRef = director;

    personRef.displayInfo();
    std::cout << "Info (role): " << personRef.getRole() << std::endl;
}




