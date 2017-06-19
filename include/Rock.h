#ifndef ROCK_H
#define ROCK_H
#include "Piece.h"
#include <vector>

using namespace std;
class Rock : public Piece
{
public:
    Rock();
    Rock(int pos, bool black);
    Rock(int pos, bool black, bool unicode);
    virtual ~Rock();
    bool moveEnabled(int newPos);
    bool captureKing(int newPos);
    vector<int> getStepsBetween(int newPos) ;
protected:

private:
};

#endif // ROCK_H
