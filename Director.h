#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <string>
#include "Person.h"

class Director : public Person {
 public:
 int filmsDirected;

 Director();
 Director(const std::string& nm, int a, const std::string& n, int fd);
 Director(const Director& other);
 Director(Director&& other) noexcept;
 ~Director();

 Director& operator=(const Director& other) = default;
 Director& operator=(Director&& other) noexcept = default;

 [[nodiscard]] int getFilmsDirected() const;
 void setFilmsDirected(int fd);
};

#endif