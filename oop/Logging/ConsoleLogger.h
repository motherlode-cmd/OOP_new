//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_CONSOLELOGGER_H
#define OOP_CONSOLELOGGER_H
#include "Logger.h"

class ConsoleLogger: public Logger{
public:
    explicit ConsoleLogger() = default;
    ~ConsoleLogger() override;
    void update(Message & message) override;
    std::string getName() const override;
private:
    std::string logName = "C L";
};


#endif //OOP_CONSOLELOGGER_H
