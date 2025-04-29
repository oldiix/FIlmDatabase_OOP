#include "User.h"
#include <iostream>
#include <fstream>

user::user(const std::string& name)
  : username(name)
{}
void user::logAction(const std::string& action) const {

    std::string filename = "history_" + username + ".log";

    std::ofstream log(filename, std::ios::app);
    if (log) {
        log << action << '\n';
    }
}

void user::viewFilm(const std::shared_ptr<Film>& film) {
    viewedFilms.push_back(film);
    std::cout << "Added to history: " << film->getTitle() << "\n";

    logAction("Viewed film: " + film->getTitle());
}


void user::displayViewedFilms() const {
    if (viewedFilms.empty()) {
        std::cout << "History is empty.\n";
        return;
    }
    std::cout << "History for " << username << ":\n";
    for (const auto& f : viewedFilms) {
        std::cout << "- " << f->getTitle()
                  << " (" << f->getReleaseYear() << ")\n";
    }
}

std::string user::getUsername() const {
    return username;
}

const std::vector<std::shared_ptr<Film>>& user::getViewedFilms() const {
    return viewedFilms;
}

regular_user::regular_user(const std::string& name)
  : user(name)
{}

void regular_user::displayMenu() const {
    std::cout << "\n=== User Menu ===\n"
              << "1. View all films\n"
              << "2. View details\n"
              << "3. View history\n"
              << "4. Logout\n"
              << "Choice: ";
}