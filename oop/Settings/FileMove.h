//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_FILEMOVE_H
#define OOP_FILEMOVE_H
#include "GetMove.h"
#include "vector"
class FileMove: public GetMove{
public:
    explicit FileMove(std::string filePath);
    ~FileMove() override;
    Move getMove(std::string command) override;
private:
    std::vector <std::string> commands;
    std::vector <Move> movers;
};


#endif //OOP_FILEMOVE_H
