//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_MESSAGE_H
#define OOP_MESSAGE_H
#include "string"
#include "Level.h"
#include <ostream>
class Message{
public:
    Message(std::string s, Level l):what(s), level(l){}

    std::string outLog() const{
        std::string s = "";
        s += what;
        return s;
    }
    int getLevelNum(){
        return (int)level;
    }
    friend std::ostream& operator<<(std::ostream &os, const Message &m)  {
        os << LevelToString(m.level)<< m.outLog();
        return os;
    }
private:

    std::string what = "";
    Level level = Level::Error;
};


#endif //OOP_MESSAGE_H
