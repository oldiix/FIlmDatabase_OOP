#ifndef FILM_H
#define FILM_H

#include <string>
using namespace std;

class Film
{
private:
    string title;
    string genre;
    int releaseYear;
public:
    Film();
    Film(string t, string g, int y);
    ~Film();
    [[nodiscard]]
    string getTitle() const;
    [[nodiscard]] string getGenre() const;
    [[nodiscard]] int getReleaseYear() const;

    void setTitle(string t);
    void setGenre(string g);
    void setReleaseYear(int y);
};

#endif
