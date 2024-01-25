//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_GENKEYEVENT_H
#define OOP_GENKEYEVENT_H
#include "../Field.h"
#include "../PlayerInteface.h"
#include "../Events/EventKey.h"
template <int level>
class GenKeyEvent{
public:
    static void fill(Field & field, PlayerInterface * player){
        int h = field.getH(), w = field.getW(), x = player->getX(), y = player->getY(), count = level * 5;
        bool gen = true;
        while (gen) {
            int yKey = abs(rand() + x + count) % h;
            int xKey = abs(rand() + y + count) % w;
            if(xKey != x && yKey != y && (char)field.getType(xKey, yKey) != 'W') {
                gen = false;
                field.setEvent(yKey, xKey, new EventKey(player));
                field.setCellsPossible(true, yKey, xKey);
            }
        }
    }
};
#endif //OOP_GENKEYEVENT_H
