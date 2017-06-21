#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;

class Bishop : public Piece
{
public:
    Bishop();
    Bishop(int pos, bool black);
    Bishop(int pos, bool black, bool unicode);
    Bishop(const Bishop& _rhs) : Piece(_rhs) {};
    std::unique_ptr<Piece> clone() const
    {
        return std::unique_ptr<Piece>(new Bishop(*this));
    }
    virtual ~Bishop();
    bool moveEnabled(int newPos);
    bool captureKing(int newPos);
    vector<int> getStepsBetween(int newPos) ;
protected:

private:
};

#endif // BISHOP_H
