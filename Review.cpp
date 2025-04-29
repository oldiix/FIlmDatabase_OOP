#include "Review.h"
#include <iomanip>

Review::Review(const std::string& comment, int rating, const std::string& filmTitle)
    : comment(comment), rating(rating), filmTitle(filmTitle) {}

std::string Review::getComment() const { return comment; }
int Review::getRating() const { return rating; }
std::string Review::getFilmTitle() const { return filmTitle; }

void Review::setComment(const std::string& comment) { this->comment = comment; }
void Review::setRating(int rating) { this->rating = rating; }
void Review::setFilmTitle(const std::string& filmTitle) { this->filmTitle = filmTitle; }

void Review::displayInfo() const {
    std::cout << "Film: " << filmTitle << "\n";
    std::cout << "Rating: " << rating << "/10\n";
    std::cout << "Comment: " << comment << "\n";
    std::cout << "--------------------------\n";
}