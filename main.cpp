#include <iostream>

#include "Actor.h"
#include "Director.h"
#include "Film.h"

int main()
{
    Film f1("Kill Bill", "Action", 2003);
    Director d1("Quentin Tarantino", 62, 27);
    Actor a1("Uma Thurman", 55, 15);

    cout << "Film: " << f1.getTitle() << ", Genre: " << f1.getGenre() << ", Year: " << f1.getReleaseYear() << endl;
    cout << "Director: " << d1.getName() << ", Age: " << d1.getAge() << ", Films directed: " << d1.getFilmsDirected() << endl;
    cout << "Actor: " << a1.getName() << ", Age of actor/actress: " << a1.getAge() << ", Films acted in: " << a1.getfilmsIn() << endl;
}
