#ifndef REVIEW_H
#define REVIEW_H

#include <string>

class Review {
private:
    std::string comment;
    int rating;

public:
    Review();
    Review(const std::string& comment, int rating);
    Review(const Review& other);
    Review(Review&& other) noexcept;
    Review& operator=(const Review& other);

    [[nodiscard]] std::string getComment() const;
    [[nodiscard]] int getRating() const;

    void setComment(const std::string& comment);
    void setRating(int rating);
};

#endif // REVIEW_H