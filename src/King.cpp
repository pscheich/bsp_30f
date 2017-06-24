#include "King.h"
#include <cmath>
using namespace std;
King::King()
{
    //ctor
}
King::King(const int pos, const bool black):Piece(pos,black? "K" : "k",black)
{
}
King::King(const int pos, const bool black,const bool unicode):Piece(pos,unicode?black? "\u265A" : "\u2654":black? "K" : "k",black)
{
    //ctor
}
King::King(const King& _rhs) : Piece(_rhs) {}
King::~King()
{
    //dtor
}
std::unique_ptr<Piece> King::clone() const
{
    return std::unique_ptr<Piece>(new King(*this));
}
bool King::moveEnabled(const int newPos) const
{
    bool ret= false;
    if(checkInField(newPos))
    {
        if((std::abs(newPos/8-_position/8)==1)  && (std::abs(newPos%8-_position%8) == 1))// diagonal//Immer nur ein Schritt für den König
            ret = true;
        else if((std::abs(newPos/8-_position/8)==0)  && (std::abs(newPos%8-_position%8) == 1))// vor zuruck //Immer nur ein Schritt für den König
            ret = true;
        else if((std::abs(newPos/8-_position/8)==1)  && (std::abs(newPos%8-_position%8) == 0))// links rechts //Immer nur ein Schritt für den König
            ret = true;
    }
    return ret;
}
bool King::captureKing(const int newPos) const
{
    bool ret= false;
    if(checkInField(newPos))
    {
        if((std::abs(newPos/8-_position/8)==1)  && (std::abs(newPos%8-_position%8) == 1))// diagonal//Immer nur ein Schritt für den König
            ret = true;
        else if((std::abs(newPos/8-_position/8)==0)  && (std::abs(newPos%8-_position%8) == 1))// vor zuruck //Immer nur ein Schritt für den König
            ret = true;
        else if((std::abs(newPos/8-_position/8)==1)  && (std::abs(newPos%8-_position%8) == 0))// links rechts //Immer nur ein Schritt für den König
            ret = true;
    }
    return ret;
}
vector<int> King::getStepsBetween(const int ) const
{
 //   newPos++; //damit warnung verschwindet
    vector<int> ret = {-1};
    return ret;
}
