//
// Created by motherlode on 09.12.22.
//

#ifndef OOP_GENERATORRULES_H
#define OOP_GENERATORRULES_H
#include "../Field.h"
#include "../PlayerInteface.h"
template <typename ... Rules>
class GeneratorRules{
public:
    void generate(Field & field, PlayerInterface * player){
        (Rules::fill(field, player),...);
    }
};
#endif //OOP_GENERATORRULES_H
