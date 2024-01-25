//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_EVENTFIELD_H
#define OOP_EVENTFIELD_H
#include "Event.h"
#include "../Field.h"
class EventField : public Event {
public:
    explicit EventField(Field * field):field(field){}
    virtual ~EventField() override {}
protected:
    Field * field;
};
#endif //OOP_EVENTFIELD_H
