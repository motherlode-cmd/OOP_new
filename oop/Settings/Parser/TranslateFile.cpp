//
// Created by motherlode on 09.12.22.
//

#include "TranslateFile.h"
#include <iostream>
bool isSNumber(std::string s) {
    if(s.length() < 1 || s.length() == 1 && !std::isdigit(s[0])) {
        return false;
    }
    if(s[0] != '-' && !std::isdigit(s[0])) {
        return false;
    }
    for(int i = 1; i < s.length(); i++) {
        if(!std::isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

void TranslateFile::setMovers(std::vector<std::string> input, std::vector<std::string> &commands,
                              const std::vector<Move> movers) {
    std::vector <std::string> tmp_commands;
    tmp_commands.push_back("d");
    tmp_commands.push_back("a");
    tmp_commands.push_back("s");
    tmp_commands.push_back("w");
    commands.push_back("");
    commands.push_back("");
    commands.push_back("");
    commands.push_back("");
    for(int i = 0; i < input.size() - 2; i+=3) {
        if(isSNumber(input[i]) && isSNumber(input[i + 1]) && input[i + 2].length() > 0) {
            int y = std::stoi(input[i]), x = std::stoi(input[i + 1]);
            Move currentMove = Move(y, x);
            std::string command = input[i + 2];
            for(int i = 0; i < 4; i++) {
                if(currentMove == movers[i]) {
                    for(int j = 0; j < 4; j++) {
                        if(command == commands[j]) {
                            std::cout << "Equal command, use default"<<std::endl;
                            command = "";
                            commands[i] = tmp_commands[i];
                        }
                    }
                    if(command != "") {
                        commands[i] = command;
                    }
                }
            }
            for(int i = 0; i < 4; i++) {
                if(commands[i] == ""){
                    commands[i] = tmp_commands[i];
                }
                for(int j = 0; j < i; j++) {
                    if(commands[i] == commands[j]) {
                        commands[i] = tmp_commands[i];
                    }
                }
            }

        }
    }
    for(int i = 0; i < 4; i++) {
        if(commands[i] == ""){
            commands[i] = tmp_commands[i];
        }
        for(int j = 0; j < i; j++) {
            if(commands[i] == commands[j]) {
                commands[i] = tmp_commands[i];
            }
        }
    }
    tmp_commands.clear();
}
