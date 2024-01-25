//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_GENUNLOCKEVENT_H
#define OOP_GENUNLOCKEVENT_H
#include "../Field.h"
#include "../PlayerInteface.h"

template <int level>
class GenUnlockEvent{
public:
    static void fill(Field & field, PlayerInterface * player){
        int h = field.getH(), w = field.getW(), x = player->getX(), y = player->getY(), count = level * 5;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++){
                if( (char )field.getType(i, j) == 'W' ||
                    (char )field.getType(i, j) == '%' ||
                    (i == y && j == x)) {
                    field.setCellsPossible(i, j, true);
                } else {
                    if(rand() % count == 0) {
                        field.setCellsPossible(i, j, true);
                    }
                }
            }
        }
    }
};
#endif //OOP_GENUNLOCKEVENT_H
