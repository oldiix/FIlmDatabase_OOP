#ifndef ACTOR_H
#define ACTOR_H

#include <string>

#include "Person.h"
class Actor:public Person
{
    public:
    int filmsIn;

    Actor();
    Actor(const std::string& nm, int a, const std::string& n, int f);
    Actor(const Actor& other);
    Actor(Actor&& other) noexcept;

    Actor& operator=(const Actor& other) = default;
    Actor& operator=(Actor&& other) noexcept = default;

    [[nodiscard]] int getfilmsIn() const;
    void setfilmsIn(int f);

    ~Actor();

};

#endif
