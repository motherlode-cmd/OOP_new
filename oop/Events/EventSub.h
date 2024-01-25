//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_EVENTSUB_H
#define OOP_EVENTSUB_H
#include "EventPlayer.h"
class EventSub: public EventPlayer {
public:
    EventSub(PlayerInterface * player):EventPlayer(player){}
    void start() override {
        player->changeHealth(-5);
        Message m(Message("Event Substract Health - 5", Level::Change));
        this->notify(m);
    }
};
#endif //OOP_EVENTSUB_H
