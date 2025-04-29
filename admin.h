#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <vector>
#include <memory>
#include <string>

class Film;

class admin : public user {
private:
    std::string password;

public:
    admin(const std::string& name, const std::string& pwd);
    bool isAdmin()   const override;
    bool checkPassword(const std::string& p) const override;
    std::string getPassword() const override { return password; }
    void displayMenu() const override;

    void addFilm(std::vector<std::shared_ptr<Film>>& films,
                 const std::shared_ptr<Film>& f);
    void updateFilm(std::vector<std::shared_ptr<Film>>& films,
                    const std::string& title);
    void removeFilm(std::vector<std::shared_ptr<Film>>& films,
                    const std::string& title);
    void viewUserActivities(const std::vector<std::shared_ptr<user>>& users) const;
};

#endif // ADMIN_H