
#ifndef OOP_MOVE_H
#define OOP_MOVE_H
#include "string"

class Move {
private:
    int x = 0;
    int y = 0;

public:
    Move(int y, int x):x(x), y(y){}

    int getY() const;

    void setY(int y);

    int getX() const;

    void setX(int x);

    std::string toString();

    bool operator == (const Move & other) {
        return this->x == other.x && this->y == other.y;
    };

    bool equal(const Move& other);

};


#endif //OOP_MOVE_H
