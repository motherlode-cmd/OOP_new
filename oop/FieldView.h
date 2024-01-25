//
// Created by motherlode on 08.12.22.
//

#ifndef OOP_FIELDVIEW_H
#define OOP_FIELDVIEW_H
#include "Field.h"
#include "PlayerInteface.h"
#include "CellView.h"
class FieldView {
public:
    void viewField(const Field & field, const PlayerInterface * playerInterface);
private:
    CellView cellView;
};


#endif //OOP_FIELDVIEW_H
