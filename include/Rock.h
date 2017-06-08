#ifndef ROCK_H
#define ROCK_H

#include "Piece.h"

class Rock : Piece
{
public:
    Rock();
    Rock(int x, int y);
    virtual ~Rock();
    bool moveEnabled(vector<int> newPos);
protected:

private:
};

#endif // ROCK_H
