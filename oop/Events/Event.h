//
// Created by motherlode on 08.12.22.
//

#ifndef OOP_EVENT_H
#define OOP_EVENT_H
#include "../Observable/ConcreteObservable.h"
class Event : public ConcreteObservable{
public:
    virtual void start() = 0;
    virtual ~Event() = default;
};
#endif //OOP_EVENT_H
