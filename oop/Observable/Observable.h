//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_OBSERVABLE_H
#define OOP_OBSERVABLE_H
#include "../Logging/Message.h"
#include "../Observer/Observer.h"
class Observable {
public:
    virtual void notify(Message & m) = 0;
    virtual void addObs(Observer * obs) = 0;
    virtual void clean() = 0;
};
#endif //OOP_OBSERVABLE_H
