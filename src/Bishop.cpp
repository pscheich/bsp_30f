#include "Bishop.h"
#include <cmath>
using namespace std;
Bishop::Bishop()
{
    //ctor
}

Bishop::~Bishop()
{
    //dtor
}
bool Bishop::moveEnabled(vector<int> newPos)
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(!
                (
                    ((std::abs(newPos.at(0)-_position.at(0))>0)  == (std::abs(newPos.at(1)-_position.at(1)) > 0))
                    !=
                    (  (abs(newPos.at(0)-_position.at(0))>0)  != (abs(newPos.at(1)-_position.at(1)) > 0))
                )
          ) //Immer nur ein Schritt für die Dame
            ret = false;
    }
    return ret;
}
ostream& operator<<(ostream& s , const Piece& rhs ){
s << "B";
return s;
}
