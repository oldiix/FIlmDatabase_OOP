#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <memory>
#include "Film.h"

class user {
protected:
    std::string username;
    std::vector<std::shared_ptr<Film>> viewedFilms;

public:
    explicit user(const std::string& name);
    virtual ~user() = default;

    [[nodiscard]] virtual bool isAdmin()   const { return false; }
    [[nodiscard]] virtual bool checkPassword(const std::string& ) const { return false; }
    virtual void displayMenu() const = 0;

    void viewFilm(const std::shared_ptr<Film>& f);
    void displayViewedFilms() const;
    void logAction(const std::string& action) const;
    [[nodiscard]] virtual std::string getPassword() const { return ""; }
    [[nodiscard]] std::string getUsername() const;
    [[nodiscard]] const std::vector<std::shared_ptr<Film>>& getViewedFilms() const;
};

class regular_user : public user {
public:
    explicit regular_user(const std::string& name);
    void displayMenu() const override;
};

#endif // USER_H