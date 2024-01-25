//
// Created by motherlode on 09.12.22.
//

#include "ConsoleLogger.h"
#include <iostream>
ConsoleLogger::~ConsoleLogger() {
    logName.erase();
}

void ConsoleLogger::update(Message &message) {
    std::cout<<message<<std::endl;
}

std::string ConsoleLogger::getName() const {
    return logName;
}
