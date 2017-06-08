#include "Pawn.h"
#include <cmath>
using namespace std;
Pawn::Pawn()
{
    //ctor
}

Pawn::~Pawn()
{
    //dtor
}
bool Pawn::moveEnabled(vector<int> newPos)
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(unMoved)
        {
            if(!((std::abs(newPos.at(0)-_position.at(0))==0)
                    && ((std::abs(newPos.at(1)-_position.at(1)) == 1) !=(std::abs(newPos.at(1)-_position.at(1)) == 2) ))) //Zweischritte Bauer
                    ret = false;
        }
    else
    {
        if(!(std::abs(newPos.at(0)-_position.at(0))==0  && std::abs(newPos.at(1)-_position.at(1)) == 1)) //Ein schritt bauer
                ret = false;
        }

    }
    return ret;
}
ostream& Pawn::operator<<(ostream& s , const Piece& rhs ){
s << "P"
return s;
}
