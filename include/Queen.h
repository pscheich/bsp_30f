#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;

class Queen : public Piece
{
public:
    Queen();
    Queen(int pos, bool black);
    Queen(int pos, bool black, bool unicode);
    Queen(const Queen& _rhs) : Piece(_rhs) {}
    std::unique_ptr<Piece> clone() const
    {
        return std::unique_ptr<Piece>(new Queen(*this));
    }
    virtual ~Queen();
    bool moveEnabled(int newPos);
    bool captureKing(int newPos);
    vector<int> getStepsBetween(int newPos) ;
protected:

private:
};

#endif // QUEEN_H
