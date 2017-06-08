#include "King.h"
#include <cmath>
using namespace std;
King::King()
{
    //ctor
}


King::~King()
{
    //dtor
}

bool King::moveEnabled(vector<int> newPos)
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(!((std::abs(newPos.at(0)-_position.at(0))==1)  || (std::abs(newPos.at(1)-_position.at(1)) == 1))) //Immer nur ein Schritt für den König
            ret = false;
    }
    return ret;
}
ostream& King::operator<<(ostream& s , const Piece& rhs ){
s << "K"
return s;
}
