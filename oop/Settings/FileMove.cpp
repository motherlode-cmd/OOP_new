//
// Created by motherlode on 09.12.22.
//

#include "FileMove.h"
#include <fstream>
#include <iostream>
#include "Parser/TranslateFile.h"
FileMove::FileMove(std::string filePath) {
    movers.emplace_back(Move(0,1));
    movers.emplace_back(Move(0,-1));
    movers.emplace_back(Move(1,0));
    movers.emplace_back(Move(-1,0));
    std::ifstream reader;
    reader.open(filePath, std::ios::binary);
    if(!reader.is_open() ) {
        TranslateFile().dflt(commands);
    } else {
        std::string s;
        std::vector<std::string> allFile;
        while (reader >> s) {
            allFile.push_back(s);
        }
        if(!allFile.empty()) {
            TranslateFile().setMovers(allFile, commands, movers);
        } else {
            TranslateFile().dflt(commands);
        }
    }
    std::cout<<"settings:"<<std::endl;
    for(int i = 0; i < 4; i++) {
        std::cout << movers[i].toString() + " " + commands[i]<<std::endl;
    }
    reader.close();
}

Move FileMove::getMove(std::string command) {
    for(int i = 0; i < commands.size(); i++) {
        if(commands[i] == command) {
            return movers[i];
        }
    }
    Move def(0,0);
    return def;
}

FileMove::~FileMove() {
    commands.clear();
    movers.clear();
}
