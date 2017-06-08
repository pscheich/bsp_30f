#include "Knight.h"
#include <cmath>
using namespace std;
Knight::Knight()
{
    //ctor
}

Knight::~Knight()
{
    //dtor
}
bool Knight::moveEnabled(vector<int> newPos)
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(!(((abs(newPos.at(0)-_position.at(0)))==1 ) ||( abs(newPos.at(1)-_position.at(1)) == 1)) )//Immer nur ein Schritt für den König
            ret = false;
    }
    return ret;
}
ostream& Knight::operator<<(ostream& s , const Piece& rhs ){
s << "k"
return s;
}
