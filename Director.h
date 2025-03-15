#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <string>
using namespace std;

class Director {
 private:
 string name;
 int age;
 int filmsDirected;

 public:
 Director();
 Director(string n, int a, int f);
 Director(const Director& other);
 Director(Director&& other) noexcept;
 ~Director();

 string getName() const;
 int getAge() const;
 int getFilmsDirected() const;

 void setName(string n);
 void setAge(int a);
 void setFilmsDirected(int f);

};

#endif //DIRECTOR_H
