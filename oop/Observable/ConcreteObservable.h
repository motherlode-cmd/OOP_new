//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_CONCRETEOBSERVABLE_H
#define OOP_CONCRETEOBSERVABLE_H
#include "Observable.h"
#include "vector"
class ConcreteObservable: public Observable{
public:
    ConcreteObservable() = default;
    ~ConcreteObservable();
    void notify(Message & m) override;
    void addObs(Observer * obs) override;
    void clean() override;
protected:
    Observer * obs = nullptr;

};


#endif //OOP_CONCRETEOBSERVABLE_H
