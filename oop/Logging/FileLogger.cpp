//
// Created by motherlode on 09.12.22.
//

#include "FileLogger.h"

FileLogger::FileLogger(std::string filePath):filePath(filePath) {
    fileWriter.open(filePath, std::ios::binary);
}

void FileLogger::update(Message &message) {
    fileWriter<<message<<std::endl;
    fileWriter.flush();
}

FileLogger::~FileLogger() {
    fileWriter.flush();
    fileWriter.close();
}

std::string FileLogger::getName() const {
    return filePath;
}
