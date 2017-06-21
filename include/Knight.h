#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;
class Knight : public Piece
{
public:
    Knight();
    Knight(int pos, bool black);
    Knight(int pos, bool black, bool unicode);
    Knight(const Knight& _rhs) : Piece(_rhs) {}
    std::unique_ptr<Piece> clone() const
    {
        return std::unique_ptr<Piece>(new Knight(*this));
    }
    virtual ~Knight();
    bool moveEnabled(int newPos);
    bool captureKing(int newPos);
    vector<int> getStepsBetween(int newPos) ;
protected:

private:
};

#endif // KNIGHT_H
