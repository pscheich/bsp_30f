#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : Piece
{
public:
    Knight();
    virtual ~Knight();
    bool moveEnabled(vector<int> newPos);
protected:

private:
};

#endif // KNIGHT_H
