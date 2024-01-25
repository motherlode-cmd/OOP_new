//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_CONCRETEOBSERVER_H
#define OOP_CONCRETEOBSERVER_H

#include "Observer.h"
#include "vector"
class ConcreteObserver: public Observer{
public:
    ConcreteObserver() = default;
    ~ConcreteObserver();
    void addLogger(Logger * logger) override;
    void deleteLogger(Logger * logger) override;
    void update(Message & message) override;
    void setLevel(int inf, int chng, int err) override;
private:
    int findLogger(Logger * logger);
    std::vector <Logger *> loggers;
    int levels[3] = {0,0,0};
};


#endif //OOP_CONCRETEOBSERVER_H
