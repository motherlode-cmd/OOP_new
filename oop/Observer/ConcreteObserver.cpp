//
// Created by motherlode on 09.12.22.
//

#include "ConcreteObserver.h"

void ConcreteObserver::update(Message &message) {
    if(levels[message.getLevelNum()] != 0) {
        for (int i = 0; i < loggers.size(); i++) {
            loggers[i]->update(message);
        }
    }
}

void ConcreteObserver::deleteLogger(Logger *logger) {
    if(findLogger(logger) != -1) {
        loggers.erase(loggers.begin() + findLogger(logger));
    }
}

void ConcreteObserver::addLogger(Logger *logger) {
    if(findLogger(logger) == -1) {
        loggers.push_back(logger);
    }
}

int ConcreteObserver::findLogger(Logger *logger) {
    for(int i = 0; i < loggers.size(); i++) {
        if(logger == loggers[i]) return i;
    }
    return -1;
}

void ConcreteObserver::setLevel(int inf, int chng, int err) {
    levels[0] = inf;
    levels[1] = chng;
    levels[2] = err;
}

ConcreteObserver::~ConcreteObserver() {
    for(int i = 0; i < loggers.size(); i++) {
        if(loggers[i] != nullptr) {
            delete loggers[i];
        }
    }
    loggers.clear();
}
