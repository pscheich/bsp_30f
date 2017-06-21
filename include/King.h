#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;
class King : public  Piece
{
public:
    King();

    King(int pos, bool black);
    King(int pos, bool black, bool unicode);
    King(const King& _rhs) : Piece(_rhs) {}
    std::unique_ptr<Piece> clone() const
    {
        return std::unique_ptr<Piece>(new King(*this));
    }
    virtual ~King();
    bool moveEnabled(int newPos);
    bool captureKing(int newPos);
//   friend    ostream& operator<<(ostream& s, const King& rhs );
    vector<int> getStepsBetween(int newPos) ;
protected:

private:
};

#endif // KING_H
