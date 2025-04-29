#ifndef DATAHANDLER_H
#define DATAHANDLER_H

class DataHandler {
public:
    virtual ~DataHandler() = default;
    virtual void displayInfo() const = 0;
};

#endif