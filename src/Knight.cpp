#include "Knight.h"
#include <cmath>
using namespace std;
Knight::Knight()
{
    //ctor
}
Knight::Knight(const int pos, const bool black):Piece(pos,black? "N" : "n",black)
{
    //ctor
}
Knight::Knight(const int pos, const bool black,const bool unicode):Piece(pos,unicode?black? "\u265E" : "\u2658":black? "N" : "n",black)
{
    //ctor
}
Knight::Knight(const Knight& _rhs) : Piece(_rhs) {}
Knight::~Knight()
{
    //dtor
}
std::unique_ptr<Piece> Knight::clone() const
{
    return std::unique_ptr<Piece>(new Knight(*this));
}
bool Knight::moveEnabled(const int newPos) const
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(!(
            (((abs(newPos/8-_position/8))==1 ) &&( abs(newPos%8-_position%8) == 2))
            !=
            (((abs(newPos/8-_position/8))==2) &&( abs(newPos%8-_position%8) == 1))
                ))
            ret = false;
    }
    return ret;
}
bool Knight::captureKing(const int newPos) const
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(!(
            (((abs(newPos/8-_position/8))==1 ) &&( abs(newPos%8-_position%8) == 2))
            !=
            (((abs(newPos/8-_position/8))==2) &&( abs(newPos%8-_position%8) == 1))
                ))
            ret = false;
    }
    return ret;
}
vector<int> Knight::getStepsBetween(const int) const
{
 //   newPos++; //damit warnung verschwindet
    vector<int> ret = {-1};
    return ret;
}
