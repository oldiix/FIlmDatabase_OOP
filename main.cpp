#include <iostream>
#include "Actor.h"
#include "Director.h"
#include "Film.h"
#include "Review.h"
#include "FilmDataHandler.h"
#include "PersonDataHandler.h"

int main() {
    Director Tarantino("Quentin Tarantino", 62, "American", 27);
    Actor Uma("Uma Thurman", 54, "American", 15);
    Film killBill("Kill Bill", "Action", 2003, Tarantino);

    killBill.addActor(Uma);
    killBill.addReview(Review("Masterpiece of action cinema", 10));

    std::cout << "=== Film Information ===\n";
    std::cout << killBill << std::endl;

    // Демонстраційні приклади
    Person::demonstrateStaticBinding();
    Actor::demonstrateBasePointer();
    Director::demonstrateBaseReference();
    Review::demonstrateFinal();
    DataHandler::demonstrateInterface();

    std::cout << "\nTotal films created: " << Film::getNumFilms() << std::endl;

    return 0;
}