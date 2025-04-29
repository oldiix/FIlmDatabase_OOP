#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <memory>
#include <string>
#include "Film.h"
#include "User.h"

class FileManager {
public:
    static void saveFilms(const std::vector<std::shared_ptr<Film>>& films, const std::string& fn);
    static std::vector<std::shared_ptr<Film>> loadFilms(const std::string& fn);

    static void saveUsers(const std::vector<std::shared_ptr<user>>& users, const std::string& fn);
    static std::vector<std::shared_ptr<user>> loadUsers(const std::string& fn);
};

#endif // FILEMANAGER_H