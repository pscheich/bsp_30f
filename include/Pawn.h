#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <vector>

using namespace std;

class Pawn : public Piece
{
public:
    Pawn();
    Pawn(int pos, bool black);
    Pawn(int pos, bool black, bool unicode);
    virtual ~Pawn();
    bool moveEnabled(int newPos);
protected:

private:
    bool _unMoved;
};

#endif // PAWN_H
