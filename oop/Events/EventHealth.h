//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_EVENTHEALTH_H
#define OOP_EVENTHEALTH_H
#include "EventPlayer.h"
class EventHealth: public EventPlayer {
public:
    EventHealth(PlayerInterface * player):EventPlayer(player){}
    void start() override {
        player->changeHealth(5);
        Message m(Message("Event Health + 5", Level::Change));
        this->notify(m);
    }
};
#endif //OOP_EVENTHEALTH_H
