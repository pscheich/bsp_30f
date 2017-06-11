#ifndef EMPTY_H
#define EMPTY_H


#include "Piece.h"
#include <vector>

using namespace std;

class Empty : public Piece
{
public:
    Empty();
Empty(int pos);
    virtual ~Empty();
    bool moveEnabled(int newPos);
protected:

private:
    bool unMoved= 0;
};

#endif // EMPTY_H
