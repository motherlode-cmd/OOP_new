//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_GENWINRULE_H
#define OOP_GENWINRULE_H
#include "../Field.h"
#include "../PlayerInteface.h"
#include "../Events/EventWin.h"
template <int level>
class GenWinEvent{
public:
    static void fill(Field & field, PlayerInterface * player){
        int h = field.getH(), w = field.getW(), x = player->getX(), y = player->getY(), count = level * 5;
        bool gen = true;
        while (gen) {
            int yWin = abs(rand() + x + count) % h;
            int xWin = abs(rand() + y + count) % w;
            if(xWin != x && yWin != y && (char)field.getType(xWin, yWin) != '%') {
                gen = false;
                field.setEvent(yWin, xWin, new EventWin(&field, player));
                field.setCellsPossible(true, yWin, xWin);
            }
        }
    }
};
#endif //OOP_GENWINRULE_H
