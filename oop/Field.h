#ifndef OOP_FIELD_H
#define OOP_FIELD_H
#include "Cell.h"
#include "PlayerInteface.h"
#include "Observable/ConcreteObservable.h"
class Field: public ConcreteObservable{
public:
    Field() = default;
    Field(int h = 3, int w = 3);
    Field(const Field & newField);
    Field(Field && field);
    Field & operator = (Field const &other);
    Field & operator = (Field && other);
    ~Field();
    void makeMove(PlayerInterface * player, Move & move);
    int getH() const;
    int getW() const;
    Cell & getCell(int i, int j) const;
    void setCellsPossible(bool possible, int i, int j);
    void winner();
    bool gameStat() const;
    void generate(PlayerInterface * player);
    void setEvent(int i, int j, Event * event);
    int getType(int i, int j);
private:
    int correct(int x, int w);
    bool isMoveCorrect(Move & move);
    Cell ** cells = nullptr;
    int h = 3;
    int w = 3;
    bool status = false;
};


#endif //OOP_FIELD_H
