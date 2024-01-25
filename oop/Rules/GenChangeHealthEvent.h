//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_GENCHANGEHEALTHEVENT_H
#define OOP_GENCHANGEHEALTHEVENT_H
#include "../Field.h"
#include "../PlayerInteface.h"
#include "../Events/EventHealth.h"
#include "../Events/EventSub.h"
#include "random"
template <int level>
class GenChangeHealthEvent{
public:
    static void fill(Field & field, PlayerInterface * player){
        int h = field.getH();
        int w = field.getW();
        int count = level * 5;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(rand() % count != 0) {
                    int hq = rand() + i;
                    int wq = rand() + j;
                    if((char)field.getType(hq, wq) != '57') {
                        field.setEvent(hq + level, wq + level, new EventHealth(player));
                        field.setEvent(hq - level, wq - level, new EventSub(player));
                    }
                }
            }
        }
    }
};
#endif //OOP_GENCHANGEHEALTHEVENT_H
