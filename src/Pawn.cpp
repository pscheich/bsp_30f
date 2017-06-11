#include "Pawn.h"
#include <cmath>
using namespace std;
Pawn::Pawn()
{
    //ctor2659
}
Pawn::Pawn(int pos, bool black):Piece(pos,black? "P" : "p")
{
}
Pawn::Pawn(int pos, bool black,bool unicode):Piece(pos,unicode?black? "\u265F" : "\u2659":black? "P" : "p")
{
    //ctor
}
Pawn::~Pawn()
{
    //dtor
}
bool Pawn::moveEnabled(int newPos)
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(unMoved)
        {
            if(!((std::abs(newPos/8-_position/8)==0)
                    && ((std::abs(newPos%8-_position%8) == 1) !=(std::abs(newPos%8-_position%8) == 2) ))) //Zweischritte Bauer
                ret = false;
        }
        else
        {
            if(!(std::abs(newPos/8-_position/8)==0  && std::abs(newPos%8-_position%8) == 1)) //Ein schritt bauer
                ret = false;
        }

    }
    return ret;
}

