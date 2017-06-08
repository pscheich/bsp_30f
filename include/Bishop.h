#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : Piece
{
    public:
        Bishop();
        virtual ~Bishop();
    bool moveEnabled(vector<int> newPos);
    protected:

    private:
};

#endif // BISHOP_H
