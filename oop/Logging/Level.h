//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_LEVEL_H
#define OOP_LEVEL_H
#include "string"

enum Level
{
    Info,
    Change,
    Error
};

constexpr const char* LevelToString(Level e) throw()
{
    switch (e)
    {
        case Level::Info:
            return "[INFO]";
        case Level::Change:
            return "[CHANGED]";
        case Level::Error:
            return "[ERROR]";
        default:
            return "[NO LEVEL]";
    }
}


#endif //OOP_LEVEL_H
