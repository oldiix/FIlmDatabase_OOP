#include "Director.h"

Director::Director() : Director("Unknown", 0, 0) {}
Director::Director(string n, int a, int f) : name(n), age(a), filmsDirected(f) {}
Director::~Director() {}

string Director::getName() const { return name; }
int Director::getAge() const { return age; }
int Director::getFilmsDirected() const { return filmsDirected; }

void Director::setName(string n) { name = n; }
void Director::setAge(int a) { age = a; }
void Director::setFilmsDirected(int f) { filmsDirected = f; }

/* Actor.h */