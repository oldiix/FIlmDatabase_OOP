#include "FileManager.h"
#include "Admin.h"
#include "user.h"
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

void FileManager::saveFilms(const std::vector<std::shared_ptr<Film>>& films, const std::string& fn) {
    std::ofstream out(fn);
    if (!out) throw std::runtime_error("Cannot open " + fn);
    for (const auto& f : films) {
        out << f->getTitle() << '|'
            << f->getGenre() << '|'
            << f->getReleaseYear() << '\n';
    }
}

std::vector<std::shared_ptr<Film>> FileManager::loadFilms(const std::string& fn) {
    std::vector<std::shared_ptr<Film>> films;
    std::ifstream in(fn);
    if (!in) {
        std::cerr << "Warning: Could not open films file\n";
        return films;
    }


    std::string line;
    while (std::getline(in, line)) {
        // Пропускаємо пусті рядки
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::string title, genre, yearStr;

        if (std::getline(iss, title, '|') &&
            std::getline(iss, genre, '|') &&
            std::getline(iss, yearStr)) {

            // Нормалізація даних
            title.erase(0, title.find_first_not_of(" \t\n\r\f\v"));
            title.erase(title.find_last_not_of(" \t\n\r\f\v") + 1);

            genre.erase(0, genre.find_first_not_of(" \t\n\r\f\v"));
            genre.erase(genre.find_last_not_of(" \t\n\r\f\v") + 1);

            try {
                int year = std::stoi(yearStr);
                films.push_back(std::make_shared<Film>(
                    title, genre, year,
                    Director("Unknown", 0, "Unknown", 0)
                ));
            } catch (...) {
                std::cerr << "Invalid year format in line: " << line << "\n";
            }
            }
    }
    return films;
}


void FileManager::saveUsers(const std::vector<std::shared_ptr<user>>& users, const std::string& fn) {
    std::ofstream out(fn);
    if (!out) throw std::runtime_error("Cannot open " + fn);
    for (const auto& u : users) {
        if (u->isAdmin()) {
            out << "admin|" << u->getUsername() << "|" << u->getPassword() << '\n';
        } else {
            out << "user|" << u->getUsername() << '\n';
        }
    }
}

std::vector<std::shared_ptr<user>> FileManager::loadUsers(const std::string& fn) {
    std::vector<std::shared_ptr<user>> users;
    std::ifstream in(fn);
    if (!in) return users;

    std::string line;
    while (std::getline(in, line)) {
        std::istringstream iss(line);
        std::string role, name, pass;

        std::getline(iss, role, '|');
        std::getline(iss, name, '|');

        if (role == "admin") {
            std::getline(iss, pass);
            users.push_back(std::make_shared<admin>(name, pass));
        } else if (role == "user") {
            users.push_back(std::make_shared<regular_user>(name));
        }
    }

    bool hasAdmin = false;
    for (const auto& u : users) {
        if (u->isAdmin()) {
            hasAdmin = true;
            break;
        }
    }

    if (!hasAdmin) {
        users.push_back(std::make_shared<admin>("admin", "labsaretough"));
    }

    return users;
}