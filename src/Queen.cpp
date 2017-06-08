#include "Queen.h"
#include <cmath>
using namespace std;
Queen::Queen()
{
    //ctor
}

Queen::~Queen()
{
    //dtor
}
bool Queen::moveEnabled(vector<int> newPos)
{

    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(!(((std::abs(newPos.at(0)-_position.at(0)))==1)||((std::abs(newPos.at(1)-_position.at(1))) == 1))) //Immer nur ein Schritt für den König
            ret = false;
    }
    return ret;
}
ostream& Queen::operator<<(ostream& s , const Piece& rhs ){
s << "Q"
return s;
}
