#include "Review.h"

#include <iostream>
#include <ostream>

Review::Review() : comment(" "), rating(0) {}

Review::Review(const std::string& comment, int rating)
    : comment(comment), rating(rating) {}

Review::Review(const Review& other)
    : comment(other.comment), rating(other.rating) {}

Review::Review(Review&& other) noexcept
    : comment(std::move(other.comment)), rating(other.rating) {
    other.rating = 0;
}

Review& Review::operator=(const Review& other) {
    if (this != &other) {
        comment = other.comment;
        rating = other.rating;
    }
    return *this;
}

std::string Review::getComment() const {
    return comment;
}

int Review::getRating() const {
    return rating;
}

void Review::setComment(const std::string& c) {
    comment = c;
}

void Review::setRating(int r) {
    rating = r;
}

void Review::demonstrateFinal() {
    std::cout << "Demonstrating final method\n";
    Review review("Test review", 5);
    review.finalMethod();
}

void Review::finalMethod() const {
    std::cout << "This method is in final class and can't be overridden\n";
    std::cout << "Current review: " << comment << ", Rating: " << rating << "\n";
}