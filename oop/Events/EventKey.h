//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_EVENTKEY_H
#define OOP_EVENTKEY_H
#include "EventPlayer.h"
class EventKey : public EventPlayer {
public:
    EventKey(PlayerInterface * player):EventPlayer(player){}
    void start() override {
        player->setWin(true);
        Message m(Message("Event Player got key and can win", Level::Change));
        this->notify(m);
    }
};
#endif //OOP_EVENTKEY_H
