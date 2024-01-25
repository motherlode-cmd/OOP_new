//
// Created by motherlode on 08.12.22.
//

#ifndef OOP_CONTROLLER_H
#define OOP_CONTROLLER_H
#include "Move.h"
#include "PlayerInteface.h"
#include "Field.h"
#include "FieldView.h"
class Controller {
public:
    Controller();
    ~Controller();
    void start(int h, int w, Observer * obs);
    void game(int level);
    int getStatus();
    void makeMove(Move move);

private:
    int gameStatus = 1;
    Field field = Field(3,3);
    PlayerInterface * player;
    FieldView fieldViewer;
    // 0 - lose
    // 1 - none
    // 2 - win
};


#endif //OOP_CONTROLLER_H
