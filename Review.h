#ifndef REVIEW_H
#define REVIEW_H

#include <string>
#include <iostream>

class Review {
private:
    std::string comment;
    int rating;
    std::string filmTitle;

public:
    Review(const std::string& comment = "", int rating = 0, const std::string& filmTitle = "");

    std::string getComment() const;
    int getRating() const;
    std::string getFilmTitle() const;

    void setComment(const std::string& comment);
    void setRating(int rating);
    void setFilmTitle(const std::string& filmTitle);

    void displayInfo() const;
};

#endif // REVIEW_H