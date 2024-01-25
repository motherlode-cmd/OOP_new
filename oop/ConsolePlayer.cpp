//
// Created by motherlode on 08.12.22.
//

#include "ConsolePlayer.h"
#include <iostream>
void ConsolePlayer::makeMove(Move & move) {
    x = move.getX();
    y = move.getY();
    Message m1(Message("Player's Health is " + std::to_string(health) , Level::Info));
    this->notify(m1);
    Message m2(Message("Player's Position is " + std::to_string(y) + " row " + std::to_string(x) + " column", Level::Info));
    this->notify(m2);
}

int ConsolePlayer::getHealth() {
    return health;
}

void ConsolePlayer::changeHealth(int health) {
    this->health += health;
    if(health == 0) {
        Message m(Message("LOSE", Level::Change));
        this->notify(m);
    }
}

void ConsolePlayer::setWin(bool win) {
    this->win = win;
}

int ConsolePlayer::getY() const{
    return y;
}

int ConsolePlayer::getX() const{
    return x;
}

bool ConsolePlayer::canWin() {
    return win;
}
