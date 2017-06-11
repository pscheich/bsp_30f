#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include <vector>

using namespace std;

class Bishop : public Piece
{
public:
    Bishop();
    Bishop(int pos, bool black);
    Bishop(int pos, bool black, bool unicode);
    virtual ~Bishop();
    bool moveEnabled(int newPos);
protected:

private:
};

#endif // BISHOP_H
