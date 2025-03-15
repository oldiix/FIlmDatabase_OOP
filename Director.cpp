#include "Director.h"

Director::Director() : Director("Unknown", 0, 0) {}
Director::Director(string n, int a, int f) : name(n), age(a), filmsDirected(f) {}

Director::Director(const Director& other) : name(other.name), age(other.age), filmsDirected(other.filmsDirected) {}

Director::Director(Director&& other) noexcept : name(std::move(other.name)), age(std::move(other.age)), filmsDirected(std::move(other.filmsDirected))
{
    other.name.clear();
    other.age = 0;
    other.filmsDirected = 0;
}

Director::~Director() {}

string Director::getName() const { return this->name; }
int Director::getAge() const { return this->age; }
int Director::getFilmsDirected() const { return this->filmsDirected; }

void Director::setName(string n) { this->name = std::move(n); }
void Director::setAge(int a) { this->age = a; }
void Director::setFilmsDirected(int f) { this->filmsDirected = f; }

/* Actor.h */