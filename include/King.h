#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <vector>

using namespace std;
class King : public  Piece
{
public:
    King();

    King(int pos, bool black);
    King(int pos, bool black, bool unicode);
    virtual ~King();
    bool moveEnabled(int newPos);
 //   friend    ostream& operator<<(ostream& s, const King& rhs );
    vector<int> getStepsBetween(int newPos) ;
protected:

private:
};

#endif // KING_H
