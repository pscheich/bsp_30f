#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : Piece
{
public:
    Queen();
    virtual ~Queen();
    bool moveEnabled(vector<int> newPos);
protected:

private:
};

#endif // QUEEN_H
