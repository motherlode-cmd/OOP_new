//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_EVENTWIN_H
#define OOP_EVENTWIN_H
#include "EventField.h"
#include "../PlayerInteface.h"
class EventWin: public EventField {
public:
    EventWin(Field * field, PlayerInterface * player):EventField(field), player(player){}
    void start() override {
        if(player->canWin()) {
            field->winner();
            Message m(Message("Win Game", Level::Change));
            this->notify(m);
        } else {
            Message m(Message("Player haven't key, can't win", Level::Info));
            this->notify(m);
        }
    }
private:
    PlayerInterface * player;
};
#endif //OOP_EVENTWIN_H
