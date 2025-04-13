#ifndef PERSONDATAHANDLER_H
#define PERSONDATAHANDLER_H

#include "DataHandler.h"
#include "Person.h"

class PersonDataHandler : public DataHandler {
private:
    const Person& person;

public:
    explicit PersonDataHandler(const Person& p) : person(p) {}

    void processData() const override {
        std::cout << "Processing Person Data: " << person.getName() << std::endl;
    }

    [[nodiscard]] std::string getDatatype() const override {
        return "Person Data";
    }
};

#endif