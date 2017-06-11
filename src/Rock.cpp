#include "Rock.h"
#include <cmath>
using namespace std;
Rock::Rock()
{
    //ctor
}
Rock::Rock(int pos, bool black):Piece(pos,black? "R" : "r",black)
{
    //ctor
}
Rock::Rock(int pos, bool black,bool unicode):Piece(pos,unicode?black? "\u265C" : "\u2656":black? "R" : "r",black)
{
    //ctor
}
Rock::~Rock()
{
    //dtor
}
bool Rock::moveEnabled(int newPos)
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
       cout << (std::abs(newPos/8-_position/8)>0) << "--" << (std::abs(newPos%8-_position%8) > 0);
        if(!((std::abs(newPos/8-_position/8)>0)  != (std::abs(newPos%8-_position%8) > 0)) )//Immer nur in eine richtung für den Turm
            ret = false;
    }
    return ret;
}

