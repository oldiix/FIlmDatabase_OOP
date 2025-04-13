#ifndef FILMDATAHANDLER_H
#define FILMDATAHANDLER_H

#include "DataHandler.h"
#include "Film.h"

class FilmDataHandler : public DataHandler {
private:
    Film film;

public:
    explicit FilmDataHandler(const Film& f) : film(f) {}

    void processData() const override {
        std::cout << "Processing Film Data: " << film.getTitle() << std::endl;
    }

    [[nodiscard]] std::string getDatatype() const override {
        return "Film Data";
    }
};

#endif