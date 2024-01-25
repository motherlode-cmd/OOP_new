//
// Created by motherlode on 08.12.22.
//

#include "Mediator.h"
#include <iostream>
#include "./Logging/Message.h"
#include "Logging/FileLogger.h"
#include "Logging/ConsoleLogger.h"
#include "Observer/ConcreteObserver.h"
Mediator::Mediator() {
    obs = nullptr;
}

void Mediator::start() {
    std::pair <int, int> sizes = commandReader.getFieldSize();
    obs = commandReader.readObserver();
    controller.start(sizes.first, sizes.second, obs);
    while (controller.getStatus() == 1 && commandReader.isProcess()) {
        controller.makeMove(commandReader.readMove());
        if(controller.getStatus() == 2 && commandReader.nextLevel("начать новый") || controller.getStatus() == 0 && commandReader.nextLevel("перезапустить")) {
            nextLevel(sizes.first, sizes.second, obs);
        }
    }
}

Mediator::~Mediator() {
    delete obs;
}

void Mediator::nextLevel(int h, int w, Observer * obs) {
    controller.start(h + controller.getStatus()/2, w + controller.getStatus()/2, obs);
}

