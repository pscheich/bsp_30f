#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;

class Pawn : public Piece
{
public:

    Pawn();
    Pawn(int pos, bool black);
    Pawn(int pos, bool black, bool unicode);
    Pawn(const Pawn& _rhs) : Piece(_rhs) {};
    std::unique_ptr<Piece> clone() const
    {
        return std::unique_ptr<Piece>(new Pawn(*this));
    }
    virtual ~Pawn();
    bool moveEnabled(int newPos);
    bool captureKing(int newPos);
    vector<int> getStepsBetween(int newPos) ;
    bool promotionPossible() const;
    bool unmoved() const;
protected:

private:

};

#endif // PAWN_H
