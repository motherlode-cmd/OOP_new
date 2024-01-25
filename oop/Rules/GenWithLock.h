//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_GENWITHLOCK_H
#define OOP_GENWITHLOCK_H
#include "../Field.h"
#include "../PlayerInteface.h"
template <int level>
class GenWithLock{
public:
    static void fill(Field & field, PlayerInterface * player){
        int h = field.getH(), w = field.getW(), x = player->getX(), y = player->getY(), count = level * 5;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++){
                if(rand() % count != 0 && count * i * j % 3 == 0 &&
                   (char)field.getType(i, j) != 'W' &&
                   (char)field.getType(i, j) != '%' &&
                   (i != y || j != x)) {
                    field.setCellsPossible(i, j, false);
                }
            }
        }
    }
};
#endif //OOP_GENWITHLOCK_H
