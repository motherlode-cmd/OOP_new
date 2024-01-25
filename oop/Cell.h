//
// Created by motherlode on 08.12.22.
//

#ifndef OOP_CELL_H
#define OOP_CELL_H
#include "./Events/Event.h"

class Cell {
public:
    Cell():event(nullptr), isPossible(true){}
    Cell(Event * event, bool isPossible):event(event), isPossible(isPossible){}
    Cell(Cell const &newCell);
    Cell(Cell && newCell);
    Cell & operator = (Cell const & newCell);
    Cell & operator = (Cell && newCell);
    ~Cell();
    void callEvent();
    bool getIsPossible() const;
    void setPossible(bool isPossible);
    void setEvent(Event * event, Observer * obs);
    int getType() const;
private:
    Event * event;
    bool isPossible = false;
};


#endif //OOP_CELL_H
