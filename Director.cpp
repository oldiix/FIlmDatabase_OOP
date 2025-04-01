#include "Director.h"
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

Director::~Director() = default;


