//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_OBSERVER_H
#define OOP_OBSERVER_H
#include "../Logging/Level.h"
#include "../Logging/Logger.h"
#include "../Logging/Message.h"
class Observer {
public:
    Observer() = default;
    virtual  ~Observer() = default;
    virtual void addLogger(Logger * logger) = 0;
    virtual void deleteLogger(Logger * logger) = 0;
    virtual void update(Message & message) = 0;
    virtual void setLevel(int inf, int chng, int err) = 0;
};
#endif //OOP_OBSERVER_H
