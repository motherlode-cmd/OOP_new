//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_EVENTPLAYER_H
#define OOP_EVENTPLAYER_H
#include "Event.h"
#include "../PlayerInteface.h"
class EventPlayer : public Event {
public:
    explicit EventPlayer(PlayerInterface * player):player(player){}
    ~EventPlayer() override {player = nullptr;}
protected:
    PlayerInterface * player;
};
#endif //OOP_EVENTPLAYER_H
