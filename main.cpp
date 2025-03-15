#include <iostream>

#include "Actor.h"
#include "Director.h"
#include "Film.h"

int main()
{
    Film f1("Kill Bill", "Action", 2003);
    Film f2 = f1;
    Film f3 = std::move(f1);

    std::cout << "Film 1: " << f1 << std::endl;
    std::cout << "Film 2/copy: " << f2 << std::endl;
    std::cout << "Film 3/move: " << f3 << std::endl;

    std::cout << "Total number of films: " << Film::getNumFilms() << std::endl;

    const Film constFilm("Inception", "Sci-Fi", 2010);
    std::cout << "Constant Film: " << constFilm.getTitle() << " (" << constFilm.getReleaseYear() << ")" << std::endl;


    Director d1("Quentin Tarantino", 62, 27);
    std::cout << "Director: " << d1.getName() << ", Age: " << d1.getAge()
              << ", Films Directed: " << d1.getFilmsDirected() << std::endl;

    Actor a1("Uma Thurman", 55, 15);
    std::cout << "Actor: " << a1.getName() << ", Age: " << a1.getAge()
              << ", Films Acted In: " << a1.getfilmsIn() << std::endl;

    return 0;
}

