#include "Actor.h"


Actor::Actor() : Actor("default", 0, 0) {}
Actor::Actor(string n, int a, int m) : name(n), age(a), filmsIn(m) {}
Actor::~Actor() {}

string Actor::getName() const { return name; }
int Actor::getAge() const { return age; }
int Actor::getfilmsIn() const { return filmsIn; }

void Actor::setName(string n) { name = n; }
void Actor::setAge(int a) { age = a; }
void Actor::setfilmssIn(int m) { filmsIn = m; }