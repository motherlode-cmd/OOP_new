//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_FILELOGGER_H
#define OOP_FILELOGGER_H
#include "Logger.h"
#include <fstream>
class FileLogger: public Logger{
public:
    explicit FileLogger(std::string filePath);
    ~FileLogger() override;
    void update(Message & message) override;
    std::string getName() const override;
protected:
    std::string filePath;
    std::ofstream fileWriter;
};


#endif //OOP_FILELOGGER_H
