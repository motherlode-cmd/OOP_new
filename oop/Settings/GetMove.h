//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_GETMOVE_H
#define OOP_GETMOVE_H
#include "string"
#include "../Move.h"
class GetMove {
public:
    virtual Move getMove(std::string s) = 0;
    virtual ~GetMove() = default;
};
#endif //OOP_GETMOVE_H
