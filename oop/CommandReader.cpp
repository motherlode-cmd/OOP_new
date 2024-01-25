#include "CommandReader.h"
#include <iostream>
#include <cctype>


bool isStrNumber(std::string s) {
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

CommandReader::CommandReader(std::string filePath) {
    mover = new FileMove(filePath);
}

Move CommandReader::readMove() {
    bool flag = true;
    Move move(0,0);
    while(flag) {
        std::cout << "write your move: " << std::endl;
        std::string m;
        std::cin>>m;
        move = mover->getMove(m);
        if(!(move == Move(0,0))) {
            flag = false;
        }
    }
    return move;
}

int CommandReader::startNewLevel() {
    std::string continue_game;
    std::cin>>continue_game;
    if(continue_game == exit) {
        return 0;
    } else {
        return 1;
    }
}

bool CommandReader::isProcess() {
    return process;
}

std::pair<int, int> CommandReader::getFieldSize() {
    int h = 0;
    int w = 0;
    std::string he, we;
    bool flag = true;
    while(flag) {
        std::cout<<"Write your size h w"<<std::endl;
        std::cin >> he >> we;
        if (isStrNumber(he) && isStrNumber(we)) {
            h = std::stoi(he);
            w = std::stoi(we);
            flag = false;
        } else {
            flag = true;
            std::cout<<"expected int int"<<std::endl;
        }
    }
    std::pair<int, int> sizes;
    sizes.first = h;
    sizes.second = w;
    return sizes;
}

Observer *CommandReader::readObserver() {
    Observer * obs = new ConcreteObserver();
    std::cout<<"Нужно ли логирование в файл? y/n"<<std::endl;
    char c;
    int logCounter = 0;
    std::cin>>c;
    while(c == 'y'){
        logCounter++;
        std::cout<< "Введите название файла"<<std::endl;
        std::string filePath;
        std::cin>>filePath;
        Logger * fileLogger = new FileLogger(filePath);
        obs->addLogger(fileLogger);
        std::cout<<"Нужно ли eще логирование в файл? y/n"<<std::endl;
        std::cin>>c;
    }
    std::cout<<"Нужно ли логирование в консоль? y/n"<<std::endl;
    std::cin>>c;
    if(c == 'y') {
        logCounter++;
        Logger * consoleLogger = new ConsoleLogger();
        obs->addLogger(consoleLogger);
    }
    if(logCounter > 0) {
        int inf, chng, err;
        std::cout << "Нужно ли логирование информации? y/n" << std::endl;
        std::cin >> c;
        if (c == 'y') {
            inf = 1;
        }
        std::cout << "Нужно ли логирование изменений? y/n" << std::endl;
        std::cin >> c;
        if (c == 'y') {
            chng = 1;
        }
        std::cout << "Нужно ли логирование ошибок? y/n" << std::endl;
        std::cin >> c;
        if (c == 'y') {
            err = 1;
        }
        obs->setLevel(inf, chng, err);
    }
    return obs;
}

CommandReader::~CommandReader() {
    if(mover != nullptr) {
        delete mover;
    }
}

bool CommandReader::nextLevel(std::string s) {
    std::cout<<"Хотите "<< s <<"уровень? y/n";
    char c;
    std::cin>>c;
    if(c == 'y') return true;
    else return false;
}


