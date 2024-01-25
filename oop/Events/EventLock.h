//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_EVENTLOCK_H
#define OOP_EVENTLOCK_H
#include "EventField.h"

class EventLock : public EventField{
public:
    EventLock(Field * field): EventField(field){}
    void start() override {
        field->setCellsPossible(field->getType(4,4) == 'W', 4, 4);
        Message m(Message("Event locked cell", Level::Change));
        this->notify(m);
    }
};


#endif //OOP_EVENTLOCK_H
