//
// Created by motherlode on 08.12.22.
//

#include "FieldView.h"
#include <iostream>
void FieldView::viewField(const Field &field, const PlayerInterface *playerInterface) {
    int h = field.getH();
    int w = field.getW();
    std::cout<<"Player position is "<< playerInterface->getY() << " " << playerInterface->getX() << std::endl;
    for(int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cout<<cellView.cellViewer(field.getCell(i,j), i == playerInterface->getY() && j == playerInterface->getX())<<' ';
        }
        std::cout<<std::endl;
    }
}
