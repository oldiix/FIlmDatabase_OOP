#include "Menu.h"
#include <iostream>
#include <limits>

menu::menu() {
    try {
        loadData();
    } catch (const std::exception& e) {
        std::cout << "Error occurred while loading data: " << e.what() << std::endl;
    }
}

void menu::loadData() {
    try {
        films = FileManager::loadFilms("films.txt");
        users = FileManager::loadUsers("users.dat");
    } catch (const std::exception& e) {
        std::cout << "Error occurred while loading data: " << e.what() << std::endl;
    }
}

void menu::saveData() {
    try {
        FileManager::saveFilms(films, "films.txt");
        FileManager::saveUsers(users, "users.dat");
    } catch (const std::exception& e) {
        std::cout << "Error occurred while saving data: " << e.what() << std::endl;
    }
}

void menu::run() {
    while (true) {
        displayMainMenu();
        int choice;
        std::cin >> choice;
        if (choice == 1) loginUser();
        else if (choice == 2) loginAdmin();
        else if (choice == 3) { saveData(); break; }
        else std::cout << "Invalid choice.\n";
    }
}

void menu::displayMainMenu() {
    std::cout << "\n1. Login as User\n"
              << "2. Login as Admin\n"
              << "3. Exit\n"
              << "Choice: ";
}

void menu::loginUser() {
    std::cout << "Username: ";
    std::string name;
    std::cin >> name;
    currentUser = nullptr;
    for (auto& u : users) {
        if (!u->isAdmin() && u->getUsername() == name) {
            currentUser = u; break;
        }
    }
    if (!currentUser) {
        currentUser = std::make_shared<regular_user>(name);
        users.push_back(currentUser);
    }
    displayUserMenu();
}

void menu::loginAdmin() {
    std::cout << "Admin login: ";
    std::string name; std::cin >> name;
    std::cout << "Password: ";
    std::string pwd; std::cin >> pwd;

    if (name == "admin" && pwd == "labsaretough") {
        currentUser = std::make_shared<admin>(name, pwd);
        displayAdminMenu();
    } else {
        std::cout << "Invalid admin credentials. Try again!\n";
    }
}

void menu::displayUserMenu() {
    while (true) {
        dynamic_cast<regular_user*>(currentUser.get())->displayMenu();
        int c; std::cin >> c;
        if (c == 1) listAllFilms();
        else if (c == 2) showFilmDetails();
        else if (c == 3) currentUser->displayViewedFilms();
        else if (c == 4) { saveData(); break; }
        else std::cout << "Invalid choice.\n";
    }
}

void menu::displayAdminMenu() {
    while (true) {
        dynamic_cast<admin*>(currentUser.get())->displayMenu();
        int c; std::cin >> c;
        if (c == 1) addNewFilm();
        else if (c == 2) updateExistingFilm();
        else if (c == 3) removeExistingFilm();
        else if (c == 4) listAllFilms();
        else if (c == 5) dynamic_cast<admin*>(currentUser.get())->viewUserActivities(users);
        else if (c == 6) { saveData(); break; }
        else std::cout << "Invalid choice.\n";
    }
}

void menu::listAllFilms() const {
    std::cout << "\n=== Films ===\n";
    for (auto& f : films) {
        std::cout << "- " << f->getTitle()
                  << " (" << f->getReleaseYear() << ")\n";
    }
}

std::string trim(const std::string& str) {

    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos) return "";

    size_t end = str.find_last_not_of(" \t\n\r\f\v");

    return str.substr(start, end - start + 1);
}

void menu::showFilmDetails() const {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (films.empty()) {
        std::cout << "\nNo films available. Please add films first.\n";
        return;
    }

    std::cout << "\nEnter exact film title: ";
    std::string searchTitle;
    if (!std::getline(std::cin, searchTitle)) {
        std::cerr << "Input error occurred. Please try again.\n";
        return;
    }
    searchTitle = trim(searchTitle);

    bool found = false;
    for (const auto& filmPtr : films) {
        if (!filmPtr) continue;

        try {
            std::string filmTitle = filmPtr->getTitle();
            filmTitle = trim(filmTitle);

            if (filmTitle == searchTitle) {
                found = true;

                std::cout << "\n=== Film Details ==="
                          << "\nTitle: " << filmPtr->getTitle()
                          << "\nGenre: " << filmPtr->getGenre()
                          << "\nYear: " << filmPtr->getReleaseYear();
            }
        } catch (const std::exception& e) {
            std::cerr << "\nError processing film: " << e.what() << "\n";
            continue;
        }
    }

    if (!found) {
        std::cout << "\nFilm not found. Available films:\n";
        for (const auto& filmPtr : films) {
            if (filmPtr) {
                std::cout << "- " << filmPtr->getTitle() << "\n";
            }
        }
    }
}

void menu::addNewFilm() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string t, g, dn, nt;
    int y, a, fd;
    std::cout << "Title: "; std::getline(std::cin, t);
    std::cout << "Genre: "; std::getline(std::cin, g);
    std::cout << "Year: "; std::cin >> y; std::cin.ignore();
    std::cout << "Director name: "; std::getline(std::cin, dn);
    std::cout << "Director age: "; std::cin >> a; std::cin.ignore();
    std::cout << "Nationality: "; std::getline(std::cin, nt);
    std::cout << "Films directed: "; std::cin >> fd; std::cin.ignore();

    auto f = std::make_shared<Film>(t, g, y, Director(dn, a, nt, fd));
    dynamic_cast<admin*>(currentUser.get())->addFilm(films, f);
}

void menu::updateExistingFilm() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Title to update: ";
    std::string t; std::getline(std::cin, t);
    dynamic_cast<admin*>(currentUser.get())->updateFilm(films, t);
}

void menu::removeExistingFilm() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Title to delete: ";
    std::string t; std::getline(std::cin, t);
    dynamic_cast<admin*>(currentUser.get())->removeFilm(films, t);
}

