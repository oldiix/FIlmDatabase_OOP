#ifndef FILM_H
#define FILM_H

#include <string>
#include <iostream>
#include <vector>
#include "Director.h"
#include "Actor.h"
#include "Review.h"

class Film {
private:
    std::string title;
    std::string genre;
    int releaseYear;
    static int numFilms;

    Director director;
    std::vector<Actor> actors;
    std::vector<Review> reviews;

public:
    Film();
    Film(const std::string& t, const std::string& g, int y, const Director& d);
    Film(const std::string& t, const std::string& g, int y)
        : title(t), genre(g), releaseYear(y) {}
    Film(const Film& other);
    Film(Film&& other) noexcept;
    ~Film();

    void displayInfo() const
    {
        std::cout << "Title: " << title << "\n";
        std::cout << "Genre: " << genre << "\n";
        std::cout << "Release Year: " << releaseYear << "\n";
    }
    Film& operator=(const Film& other);
    Film& operator=(Film&& other) noexcept;

    [[nodiscard]] std::string getTitle() const;
    [[nodiscard]] std::string getGenre() const;
    [[nodiscard]] int getReleaseYear() const;
    static int getNumFilms();

    [[nodiscard]] const Director& getDirector() const;
    [[nodiscard]] const std::vector<Actor>& getActors() const;
    [[nodiscard]] const std::vector<Review>& getReviews() const;

    void setTitle(const std::string& t);
    void setGenre(const std::string& g);
    void setReleaseYear(int y);
    void setDirector(const Director& d);
    void addActor(const Actor& a);
    void addReview(const Review& r);

    bool operator==(const Film& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Film& film);
};

#endif