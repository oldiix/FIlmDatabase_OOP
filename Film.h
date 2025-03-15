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
    static int numFilms;

public:
    Film();
    Film(string t, string g, int y);
    Film(const Film& other);
    Film(Film&& other) noexcept ;
    ~Film();


    [[nodiscard]] string getTitle() const;
    [[nodiscard]] string getGenre() const;
    [[nodiscard]] int getReleaseYear() const;
    static int getNumFilms();

    void setTitle(string t);
    void setGenre(string g);
    void setReleaseYear(int y);
};

#endif
