#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <vector>

using namespace std;
class Knight : public Piece
{
public:
    Knight();
    Knight(int pos, bool black);
    Knight(int pos, bool black, bool unicode);
    virtual ~Knight();
    bool moveEnabled(int newPos);
    bool captureKing(int newPos);
    vector<int> getStepsBetween(int newPos) ;
protected:

private:
};

#endif // KNIGHT_H
