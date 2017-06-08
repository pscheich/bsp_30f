#include "Board.h"

Board::Board()
{
    //ctor
}

Board::~Board()
{
    //dtor
}


ostream& operator<<(ostream& s, const Board& rhs )
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(rhs.getWhite().at(i,j)!=nullptr)
                s << rhs.getWhite().at(i,j) else if(rhs.getBlack().at(i,j)!=nullptr)
                      s << rhs.getBlack().at(i,j);
        }
        s << endl;
    }


    return s;
}
