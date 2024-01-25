//
// Created by motherlode on 08.12.22.
//

#include "CellView.h"

char CellView::cellViewer(const Cell &cell, bool isPlayerHere) {
    if(isPlayerHere) {
        return 'P';
    } else {
        if(cell.getIsPossible()) {
            return (char)cell.getType();
        } else {
            return '#';
        }
    }
}
