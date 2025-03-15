#include "Film.h"

int Film::numFilms = 0;

Film::Film() : Film("Unknown", "Unknown", 0) {}
Film::Film(string t, string g, int y) : title(t), genre(g), releaseYear(y)
{
    numFilms++;
}

Film::Film(const Film& other) : title(other.title), genre(other.genre), releaseYear(other.releaseYear)
{
    numFilms++;
}

Film::Film(Film&& other) noexcept : title(std::move(other.title)), genre(std::move(other.genre)), releaseYear(std::move(other.releaseYear))
{
    other.title = "";
    other.genre = "";
    other.releaseYear = 0;
    numFilms++;
}

Film::~Film()
{
    numFilms--;
}

string Film::getTitle() const { return this->title; }
string Film::getGenre() const { return this->genre; }
int Film::getReleaseYear() const { return this->releaseYear; }
int Film::getNumFilms() { return numFilms; }

void Film::setTitle(string t) { this->title = std::move(t); }
void Film::setGenre(string g) { this->genre = std::move(g); }
void Film::setReleaseYear(int y) { this->releaseYear = y; }

bool Film::operator==(const Film& other) const
{
    return this->title == other.title && this->releaseYear == other.releaseYear;
}

std::ostream& operator<<(std::ostream& os, const Film& film) {
    os << "Film: " << film.title << ", Genre: " << film.genre << ", Year: " << film.releaseYear;
    return os;
}