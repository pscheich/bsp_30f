#ifndef ROCK_H
#define ROCK_H
#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;
class Rock : public Piece
{
public:
    Rock();
    Rock(int pos, bool black);
    Rock(int pos, bool black, bool unicode);
    Rock(const Rock& _rhs) : Piece(_rhs) {}
    std::unique_ptr<Piece> clone() const
    {
        return std::unique_ptr<Piece>(new Rock(*this));
    }
    virtual ~Rock();
    bool moveEnabled(int newPos);
    bool captureKing(int newPos);
    vector<int> getStepsBetween(int newPos) ;
protected:

private:
};

#endif // ROCK_H
