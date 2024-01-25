//
// Created by motherlode on 09.12.22.
//

#include "ConcreteObservable.h"

void ConcreteObservable::notify(Message &m) {
    if(obs!= nullptr) {
        obs->update(m);
    }
}

void ConcreteObservable::addObs(Observer *observer) {
    if(observer != nullptr) {
        obs = observer;
    }
}


void ConcreteObservable::clean() {
    if(obs != nullptr) {
        delete obs;
    }
}

ConcreteObservable::~ConcreteObservable() {
    //clean();
}
