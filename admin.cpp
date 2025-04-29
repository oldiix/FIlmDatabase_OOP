#include "Admin.h"
#include "Film.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include "user.h"

admin::admin(const std::string& name, const std::string& password)
: user(name), password(password) {}

bool admin::isAdmin() const
{
    return true;
}

bool admin::checkPassword(const std::string& p) const
{
    return p == password;
}

void admin::displayMenu() const
{
    std::cout << "\n ==== Admin Menu ====\n"
    << "1. Add a movie\n"
    << "2. Update movie\n"
    << "3. Delete movie\n"
    << "4. List all movies\n"
    << "5. View users' activity\n"
    << "6. Logout\n"
    << "Choice: ";
}

void admin::addFilm(std::vector<std::shared_ptr<Film>>& films,
                    const std::shared_ptr<Film>& f) { films.push_back(f);
    std::cout << "Added: " << f->getTitle() << "\n";
    logAction("Added film: " + f->getTitle());
}

void admin::updateFilm(std::vector<std::shared_ptr<Film>>& films,
                       const std::string& title) {
    for (auto& film : films)
    {
        if (film->getTitle() == title) {
            std::string nt, ng;
            int ny;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "New title: ";    std::getline(std::cin, nt);
            std::cout << "New genre: ";    std::getline(std::cin, ng);
            std::cout << "New year: ";     std::cin >> ny; std::cin.ignore();

            film->setTitle(nt);
            film->setGenre(ng);
            film->setReleaseYear(ny);

            std::cout << "Updated.\n";
            logAction("Updated film: " + film->getTitle() + " -> " + nt);
            return;
        }
    }
    std::cout << "Film has not been found.\n";
}

void admin::removeFilm(std::vector<std::shared_ptr<Film>>& films, const std::string& title)
{
    auto it = std::remove_if(films.begin(), films.end(),
        [&title](const std::shared_ptr<Film>& f) {
            return f->getTitle() == title;
        });
    if (it != films.end()) {
        films.erase(it, films.end());
        std::cout << "Deleted.\n";
        logAction("Removed film: " + title);
    } else {
        std::cout << "Not found.\n";
        logAction("Failed delete attempt for film: " + title);
    }
}


void admin::viewUserActivities(const std::vector<std::shared_ptr<user>>& users) const
{
    std::cout << "\n ==== View Users' activities ====\n";
    for (auto& user : users)
    {
        std::cout << "\nUser: " << user->getUsername() << "\n";
        std::ifstream logF("history_" + user->getUsername() + ".log");
        if (!logF.is_open())
        {
            std::cout << "No activity.\n";

        } else {
        std::string line;
        while (std::getline(logF, line))
        {
            std::cout << line << "\n";
        }
    }
    }
    logAction("Viewed Users' activities");
}