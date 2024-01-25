//
// Created by motherlode on 08.12.22.
//

#include "Move.h"

int Move::getX() const {
    return x;
}

void Move::setX(int x) {
    this->x = x;
}

int Move::getY() const {
    return y;
}

void Move::setY(int y) {
    this->y = y;
}

std::string Move::toString() {
    return "( " + std::to_string(y) + " : " + std::to_string(x) + " )";
}

bool Move::equal(const Move &other) {
    //x1/x2 == y1/y2
    //x1  y1
    //x2  y2
    return y * other.x == x * other.y;
}
