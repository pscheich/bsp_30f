#include "Bishop.h"
#include <cmath>
using namespace std;
Bishop::Bishop()
{
    //ctor
}
Bishop::Bishop(int pos, bool black):Piece(pos,black? "B" : "b")
{
    //ctor
}
Bishop::Bishop(int pos, bool black,bool unicode):Piece(pos,unicode?black? "\u265D" : "\u2657":black? "B" : "b")
{
    //ctor
}
Bishop::~Bishop()
{
    //dtor
}
bool Bishop::moveEnabled(int newPos)
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(!
                (
                    ((std::abs(newPos/8-_position/8)>0)  == (std::abs(newPos%8-_position%8) > 0))
                    !=
                    (  (abs(newPos/8-_position/8)>0)  != (abs(newPos%8-_position%8) > 0))
                )
          ) //Immer nur ein Schritt f�r die Dame
            ret = false;
    }
    return ret;
}

