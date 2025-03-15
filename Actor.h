#ifndef ACTOR_H
#define ACTOR_H

#include <string>
using namespace std;
class Actor
{
    public:
    string name;
    int age;
    int filmsIn;

    public:
    Actor();
    Actor(string n, int a, int m);
    Actor(const Actor& other);
    Actor(Actor&& other) noexcept;
    ~Actor();

    string getName() const;
    int getAge() const;
    int getfilmsIn() const;

    void setName(string n);
    void setAge(int a);
    void setfilmssIn(int m);
};

#endif
