#include "Film.h"

Film::Film() : Film("Unknown", "Unknown", 0) {}
Film::Film(string t, string g, int y) : title(t), genre(g), releaseYear(y) {}
Film::~Film() = default;

string Film::getTitle() const { return title; }
string Film::getGenre() const { return genre; }
int Film::getReleaseYear() const { return releaseYear; }

void Film::setTitle(string t) { title = t; }
void Film::setGenre(string g) { genre = g; }
void Film::setReleaseYear(int y) { releaseYear = y; }