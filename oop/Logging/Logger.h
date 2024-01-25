#ifndef OOP_LOGGER_H
#define OOP_LOGGER_H
#include "Message.h"
class Logger {
public:
    virtual ~Logger(){}
    virtual void update(Message & message) = 0;
    virtual std::string getName() const = 0;
    bool operator == (const Logger & other) {
        return this->getName() == other.getName();
    };
};
#endif //OOP_LOGGER_H
