//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_GENPLAYER_H
#define OOP_GENPLAYER_H
#include "../Field.h"
#include "../PlayerInteface.h"
template <int level>
class GenPlayer{
public:
    static void fill(Field & field, PlayerInterface * player){
        int h = field.getH(), w = field.getW(), x = player->getX(), y = player->getY(), count = level * 5;
        for(int i = 0; i < level; i++) {
            field.setCellsPossible((x + i) % count, (y - i)%count, true);
        }
    }
};
#endif //OOP_GENPLAYER_H
