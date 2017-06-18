#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include <vector>

using namespace std;

class Queen : public Piece
{
public:
    Queen();
    Queen(int pos, bool black);
    Queen(int pos, bool black, bool unicode);
    virtual ~Queen();
    bool moveEnabled(int newPos);
    vector<int> getStepsBetween(int newPos) ;
protected:

private:
};

#endif // QUEEN_H
