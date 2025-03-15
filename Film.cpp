#include "Film.h"

Film::Film() : Film("Unknown", "Unknown", 0) {}
Film::Film(string t, string g, int y) : title(t), genre(g), releaseYear(y) {}

Film::Film(const Film& other) : title(other.title), genre(other.genre), releaseYear(other.releaseYear) {}

Film::Film(Film&& other) noexcept : title(std::move(other.title)), genre(std::move(other.genre)), releaseYear(std::move(other.releaseYear))
{
    other.title = "";
    other.genre = "";
    other.releaseYear = 0;
}

Film::~Film() = default;

string Film::getTitle() const { return this->title; }
string Film::getGenre() const { return this->genre; }
int Film::getReleaseYear() const { return this->releaseYear; }

void Film::setTitle(string t) { this->title = std::move(t); }
void Film::setGenre(string g) { this->genre = std::move(g); }
void Film::setReleaseYear(int y) { this->releaseYear = y; }