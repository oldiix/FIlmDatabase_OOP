#ifndef MENU_H
#define MENU_H

#include <vector>
#include <memory>
#include "Film.h"
#include "User.h"
#include "Admin.h"
#include "FileManager.h"

class menu {
private:
    std::vector<std::shared_ptr<Film>> films;
    std::vector<std::shared_ptr<user>> users;
    std::shared_ptr<user> currentUser;

    void displayMainMenu();
    void displayUserMenu();
    void displayAdminMenu();

    void listAllFilms()    const;
    void showFilmDetails() const;
    void addNewFilm();
    void updateExistingFilm();
    void removeExistingFilm();

    void loginUser();
    void loginAdmin();

public:
    menu();
    void loadData();
    void saveData();
    void run();
};

#endif // MENU_H