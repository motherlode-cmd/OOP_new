#include "Cell.h"
#include "Events/EventKey.h"
#include "Events/EventSub.h"
#include "Events/EventHealth.h"
#include "Events/EventLock.h"
#include "Events/EventWin.h"
Cell::Cell(const Cell &newCell):event(newCell.event), isPossible(newCell.isPossible){}

Cell::Cell(Cell &&newCell):event(newCell.event), isPossible(newCell.isPossible){}

Cell &Cell::operator=(const Cell &newCell) {
    if(this != &newCell) {
        event = newCell.event;
        isPossible = newCell.isPossible;
    }
    return *this;
}

Cell &Cell::operator=(Cell &&newCell) {
    if(this != &newCell) {
        event = newCell.event;
        isPossible = newCell.isPossible;
    }
    return *this;
}

void Cell::callEvent() {
    if(event != nullptr) {
        event->start();
    }
}

bool Cell::getIsPossible() const {
    return isPossible;
}

void Cell::setPossible(bool isPossible) {
    this->isPossible = isPossible;
}

void Cell::setEvent(Event * newEvent, Observer * obs) {
    if(event != nullptr) {
        delete event;
    }
    event = newEvent;
    event->addObs(obs);
}

Cell::~Cell() {
    if(event != nullptr) {
        delete event;
    }
}

int Cell::getType() const{
    if(event != nullptr) {
        if (event == dynamic_cast<EventKey *>(event)) return 37;//'%'
        if (event == dynamic_cast<EventWin *>(event)) return 87;//'W'
        if (event == dynamic_cast<EventHealth *>(event)) return 43;//'+'
        if (event == dynamic_cast<EventSub *>(event)) return 45;//'-'
        if (event == dynamic_cast<EventLock *>(event)) return 33;//'!'
        else return 95;
    } else return 95;//'_'
}
