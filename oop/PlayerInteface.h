//
// Created by motherlode on 08.12.22.
//

#ifndef OOP_PLAYERINTEFACE_H
#define OOP_PLAYERINTEFACE_H
#include "Move.h"
#include "Observable/ConcreteObservable.h"
class PlayerInterface: public ConcreteObservable{
public:
    virtual ~PlayerInterface() = default;
    virtual void makeMove(Move & move) = 0;
    virtual int getHealth() = 0;
    virtual void changeHealth(int health) = 0;
    virtual void setWin(bool win) = 0;
    virtual int getX() const = 0;
    virtual int getY() const = 0;
    virtual bool canWin() = 0;
};
#endif //OOP_PLAYERINTEFACE_H
