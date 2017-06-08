#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : Piece
{
public:
    King();
    virtual ~King();
    bool moveEnabled(vector<int> newPos);
friend    ostream& operator<<(ostream& s , const King& rhs );
protected:

private:
};

#endif // KING_H
