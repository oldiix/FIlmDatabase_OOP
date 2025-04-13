#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <iostream>

class DataHandler {
public:
    virtual ~DataHandler() = default;
    virtual void processData() const = 0;
    [[nodiscard]] virtual std::string getDatatype() const = 0;

    static void demonstrateInterface()
    {
        std::cout << "Demonstrate interface" << std::endl;
    }
};

#endif