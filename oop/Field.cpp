#include "Field.h"
#include <iostream>
#include "./Events/EventSub.h"
#include "./Events/EventKey.h"
#include "./Events/EventWin.h"
#include "./Events/EventHealth.h"
#include "./Events/EventLock.h"
Field::Field(int h , int w){
    if(h <= 0 || w <= 0) {
        h = 3;
        w = 3;
    }
    this->h = h;
    this->w = w;
    cells = new Cell * [h];
    for(int i = 0; i < h; i++) {
        cells[i] = new Cell[w];
    }
}

Field::Field(const Field &newField):h(newField.h), w(newField.w){
    cells = new Cell * [h];
    for(int i = 0; i < h; i++) {
        cells[i] = new Cell[w];
        for(int j = 0; j < w; j++) {
            cells[i][j] = newField.cells[i][j];
        }
    }
    status = newField.status;
}

Field::Field(Field && newField):h(newField.h), w(newField.w){
    cells = new Cell * [h];
    for(int i = 0; i < h; i++) {
        cells[i] = new Cell[w];
        for(int j = 0; j < w; j++) {
            cells[i][j] = newField.cells[i][j];
        }
    }
    status = newField.status;
}

Field &Field::operator=(const Field &newField) {
    if(this != &newField) {
        for (int i = 0; i < h; i++) {
            delete[] cells[i];
        }
        delete[] cells;
        h = newField.h;
        w = newField.w;
        cells = new Cell *[h];
        for (int i = 0; i < h; i++) {
            cells[i] = new Cell[w];
            for (int j = 0; j < w; j++) {
                cells[i][j] = newField.cells[i][j];
            }
        }
        status = newField.status;
    }
    return *this;
}

Field &Field::operator=(Field &&newField) {
    if(this != &newField) {
        for (int i = 0; i < h; i++) {
            delete[] cells[i];
        }
        delete[] cells;
        h = newField.h;
        w = newField.w;
        cells = new Cell *[h];
        for (int i = 0; i < h; i++) {
            cells[i] = new Cell[w];
            for (int j = 0; j < w; j++) {
                cells[i][j] = newField.cells[i][j];
            }
        }
        status = newField.status;
    }
    return *this;
}

void Field::makeMove(PlayerInterface * player, Move & move) {
    move = Move(player->getY() + move.getY(), player->getX() + move.getX());
    if(isMoveCorrect(move)) {
        player->makeMove(move);
        cells[move.getY()][move.getX()].callEvent();
    } else {
        Message m(Message("Can't move on block cell " + move.toString(), Level::Error));
        this->notify(m);
    }
}

bool Field::isMoveCorrect(Move & move) {
    int x = correct(move.getX(), w);
    int y = correct(move.getY(), h);
    move = Move(y, x);
    Message m(Message("Go to " + move.toString(), Level::Info));
    this->notify(m);
    return cells[move.getY()][move.getX()].getIsPossible();
}

int Field::getW() const{
    return w;
}

int Field::getH() const{
    return h;
}

Cell &Field::getCell(int i, int j) const {
    return cells[i][j];
}

int Field::correct(int x, int w) {
    while (x < 0) {
        x += w;
    }
    x %= w;
    return x;
}

void Field::setCellsPossible(bool possible, int i, int j) {
    i = correct(i, h);
    j = correct(j, w);
    cells[i][j].setPossible(possible);
}

void Field::winner() {
    status = true;
}

void Field::generate(PlayerInterface *player) {
    cells[0][1].setEvent(new EventSub(player), obs);
    cells[4][4].setEvent(new EventWin(this, player), obs);
    cells[3][1].setEvent(new EventKey(player), obs);
    cells[2][0].setEvent(new EventLock(this), obs);
    cells[1][2].setEvent(new EventHealth(player), obs);
}

bool Field::gameStat() const {
    return status;
}

Field::~Field() {
    if(cells != nullptr) {
        for(int i = 0; i < h; i++) {
            if(cells[i] != nullptr) {
                delete [] cells[i];
            }
        }
        delete cells;
    }
}

void Field::setEvent(int i, int j, Event *event) {
    i = correct(i, h);
    j = correct(j, w);
    cells[i][j].setEvent(event, obs);
}

int Field::getType(int i, int j) {
    i = correct(i, h);
    j = correct(j, w);
    return cells[i][j].getType();
}


/*
Cell ** cells = nullptr;
int h = 3;
int w = 3;
bool status = false;*/