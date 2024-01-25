#include "Controller.h"
#include "ConsolePlayer.h"
#include <iostream>
#include "Rules/GeneratorRules.h"
#include "Rules/GenChangeHealthEvent.h"
#include "Rules/GenKeyEvent.h"
#include "Rules/GenLockEvent.h"
#include "Rules/GenWinRule.h"
#include "Rules/GenWithLock.h"
#include "Rules/GenUnlockEvent.h"
#include "Rules/GenPlayer.h"

Controller::Controller() {
    player = new ConsolePlayer;
}

Controller::~Controller() {
    delete player;
}

int Controller::getStatus() {
    return gameStatus;
}

void Controller::game(int level) {

}

void Controller::start(int h, int w, Observer * obs) {
    field = Field(h, w);
    field.addObs(obs);
    player->addObs(obs);
    if(player->getHealth() != 100)
        player->changeHealth(100 - player->getHealth());
    if(gameStatus == 1 || gameStatus == 0)  {
        GeneratorRules <GenChangeHealthEvent<1>, GenKeyEvent<1>, GenLockEvent<1>, GenWithLock<1>, GenPlayer<1>, GenWinEvent<1>, GenUnlockEvent<1>> g;
        g.generate(field, player);
    } else {
        GeneratorRules <GenChangeHealthEvent<2>, GenKeyEvent<2>, GenLockEvent<2>, GenWithLock<2>, GenPlayer<2>, GenWinEvent<2>, GenUnlockEvent<2>> g;
        g.generate(field, player);
    }
    gameStatus = 1;
    player->setWin(false);
    fieldViewer.viewField(field, player);
}

void Controller::makeMove(Move move) {
    field.makeMove(player, move);
    fieldViewer.viewField(field, player);
    if(field.gameStat()) {
        gameStatus = 2;
    }
    if(player->getHealth() == 0) {
        gameStatus = 0;
    }
}


