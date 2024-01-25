//
// Created by motherlode on 08.12.22.
//

#ifndef OOP_MEDIATOR_H
#define OOP_MEDIATOR_H
#include "Controller.h"
#include "CommandReader.h"

class Mediator {
public:
    explicit Mediator();
    ~Mediator();
    void start();
    void nextLevel(int h, int w, Observer * obs);
private:
    Controller controller;
    CommandReader commandReader = CommandReader("settings.txt");
    Observer * obs;
};


#endif //OOP_MEDIATOR_H
