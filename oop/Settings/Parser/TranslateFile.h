//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_TRANSLATEFILE_H
#define OOP_TRANSLATEFILE_H
#include "vector"
#include "string"
#include "../../Move.h"
#include <iostream>
class TranslateFile {
public:
    TranslateFile() = default;
    void setMovers(std::vector <std::string> input,std::vector<std::string> & commands,const std::vector<Move> movers);
    void dflt(std::vector <std::string> & commands) {
        std::cout<<"Bad file, Default moves"<<std::endl;
        commands.push_back("d");
        commands.push_back("a");
        commands.push_back("s");
        commands.push_back("w");
    }
};


#endif //OOP_TRANSLATEFILE_H
