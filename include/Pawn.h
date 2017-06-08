#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : Piece
{
public:
    Pawn();
    virtual ~Pawn();
    bool moveEnabled(vector<int> newPos);
protected:

private:
    bool unMoved= 0;
};

#endif // PAWN_H
