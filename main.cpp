#include <iostream>
#include "Actor.h"
#include "Director.h"
#include "Film.h"
#include "Review.h"

int main() {
    Director Tarantino("Quentin Tarantino", 62, "American", 27);

    Actor Uma("Uma Thurman", 54, "American", 15);
    Actor Bill("David Carradine", 89, "American", 12);
    Actor Oren("Lucy Liu", 56, "American", 10);

    Film killBill("Kill Bill", "Action", 2003, Tarantino);

    killBill.addActor(Uma);
    killBill.addActor(Bill);
    killBill.addActor(Oren);

    // Додавання відгуків
    killBill.addReview(Review("Masterpiece of action cinema", 10));
    killBill.addReview(Review("Tarantino is a GOAT", 10));
    killBill.addReview(Review("Men, that's insanely good movie", 10));


    Film killBillCopy = killBill;
    Film killBillMoved = std::move(killBill);

    std::cout << "--- Original Film ---" << std::endl;
    std::cout << killBill << std::endl;

    std::cout << "\n--- Copied Film ---" << std::endl;
    std::cout << killBillCopy << std::endl;

    std::cout << "\n--- Moved Film ---" << std::endl;
    std::cout << killBillMoved << std::endl;

    std::cout << "\nTotal films created: " << Film::getNumFilms() << std::endl;


    const Film constFilm("Pulp Fiction", "Crime", 1994, Tarantino);
    std::cout << "\nConstant Film Info: " << constFilm.getTitle()
              << " (" << constFilm.getReleaseYear() << ")" << std::endl;

    std::cout << "\nDirector Info: " << Tarantino.getName()
              << ", Age: " << Tarantino.getAge()
              << ", Films Directed: " << Tarantino.getFilmsDirected() << std::endl;


    std::cout << "\nActor Info: " << Uma.getName()
              << ", Age: " << Uma.getAge()
              << ", Films Acted In: " << Uma.getfilmsIn() << std::endl;

    return 0;
}