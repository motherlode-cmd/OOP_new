//
// Created by motherlode on 08.12.22.
//

#ifndef OOP_COMMANDREADER_H
#define OOP_COMMANDREADER_H
#include "Move.h"
#include "string"
#include "Observer/Observer.h"
#include "Logging/FileLogger.h"
#include "Logging/ConsoleLogger.h"
#include "Observer/ConcreteObserver.h"
#include "Settings/GetMove.h"
#include "Settings/FileMove.h"
class CommandReader {
public:
    explicit CommandReader(std::string filePath);
    ~CommandReader();
    Move readMove();
    int startNewLevel();
    bool isProcess();
    std::pair <int, int> getFieldSize();
    Observer * readObserver();
    bool nextLevel(std::string s);
    //void readExit();
private:
    std::string exit = "exit";
    bool process = true;
    GetMove * mover;
};


#endif //OOP_COMMANDREADER_H
