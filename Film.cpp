#include "Film.h"
#include <iostream>

int Film::numFilms = 0;

Film::Film() : Film("Unknown", "Unknown", 0, Director()) {}

Film::Film(const std::string& t, const std::string& g, int y, const Director& d)
    : title(t), genre(g), releaseYear(y), director(d) {
    numFilms++;
}

Film::Film(const Film& other)
    : title(other.title), genre(other.genre), releaseYear(other.releaseYear),
      director(other.director), actors(other.actors), reviews(other.reviews) {
    numFilms++;
}

Film::Film(Film&& other) noexcept
    : title(std::move(other.title)), genre(std::move(other.genre)),
      releaseYear(other.releaseYear), director(std::move(other.director)),
      actors(std::move(other.actors)), reviews(std::move(other.reviews)) {
    other.releaseYear = 0;
    numFilms++;
}

Film::~Film() {
    numFilms--;
}

std::string Film::getTitle() const { return title; }
std::string Film::getGenre() const { return genre; }
int Film::getReleaseYear() const { return releaseYear; }
int Film::getNumFilms() { return numFilms; }

const Director& Film::getDirector() const { return director; }
const std::vector<Actor>& Film::getActors() const { return actors; }
const std::vector<Review>& Film::getReviews() const { return reviews; }

void Film::setTitle(const std::string& t) { title = t; }
void Film::setGenre(const std::string& g) { genre = g; }
void Film::setReleaseYear(int y) { releaseYear = y; }
void Film::setDirector(const Director& d) { director = d; }
void Film::addActor(const Actor& a) { actors.push_back(a); }
void Film::addReview(const Review& r) { reviews.push_back(r); }

bool Film::operator==(const Film& other) const {
    return title == other.title && releaseYear == other.releaseYear;
}

std::ostream& operator<<(std::ostream& os, const Film& film) {
    os << "Film Details:\n"
       << "-------------\n"
       << "Title: " << film.title << "\n"
       << "Genre: " << film.genre << "\n"
       << "Year: " << film.releaseYear << "\n"
       << "Director: " << film.director.getName() << "\n"
       << "Actors (" << film.actors.size() << "):\n";

    for (const auto& actor : film.actors) {
        os << "- " << actor.getName() << "\n";
    }

    os << "Reviews (" << film.reviews.size() << "):\n";
    for (const auto& review : film.reviews) {
        os << "- Rating: " << review.getRating()
           << ", Comment: " << review.getComment() << "\n";
    }

    return os;
}