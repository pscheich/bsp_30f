#include "Rock.h"
#include <cmath>
using namespace std;
Rock::Rock()
{
    //ctor
}

Rock::~Rock()
{
    //dtor
}
bool Rock::moveEnabled(vector<int> newPos)
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(!((std::abs(newPos.at(0)-_position.at(0))>0)  != (std::abs(newPos.at(1)-_position.at(1)) > 0)) )//Immer nur ein Schritt für den Turm
            ret = false;
    }
    return ret;
}
ostream& Rock::operator<<(ostream& s , const Piece& rhs ){
s << "R"
return s;
}
