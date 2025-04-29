#include "Person.h"
#include <iostream>
#include <ostream>

Person::Person() : name("default"), age(0), nationality("ukrainian") {}

Person::Person(const std::string& nm, int a, const std::string& n)
: name(n), age(a), nationality(n) {}

Person::Person(const Person& other) : name(other.name), age(other.age), nationality(other.nationality) {}

Person::Person(Person&& other) noexcept
    : name(std::move(other.name)), age(other.age), nationality(std::move(other.nationality)) {}


std::string Person::getName() const { return name; }
int Person::getAge() const { return age; }
std::string Person::getNationality() const { return nationality; }
void Person::setName(const std::string& nm) { name = nm; }
void Person::setAge(int a) { age = a; }
void Person::setNationality(const std::string& n) { nationality = n; }

