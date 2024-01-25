//
// Created by motherlode on 08.12.22.
//

#ifndef OOP_CONSOLEPLAYER_H
#define OOP_CONSOLEPLAYER_H
#include "PlayerInteface.h"

class ConsolePlayer: public PlayerInterface{
public:
    void makeMove(Move & move) override;
    int getHealth() override;
    void changeHealth(int health) override;
    void setWin(bool win) override;
    int getY() const override;
    int getX() const override;
    bool canWin() override;
private:
    int health = 100;
    bool win = false;
    int x = 0;
    int y = 0;
};


#endif //OOP_CONSOLEPLAYER_H
