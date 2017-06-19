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
        // cout << (std::abs(newPos/8-_position/8)>0) << "--" << (std::abs(newPos%8-_position%8) > 0);
        if(!((std::abs(newPos/8-_position/8)>0)  != (std::abs(newPos%8-_position%8) > 0)) )//Immer nur in eine richtung für den Turm
            ret = false;
    }
    return ret;
}
bool Rock::captureKing(int newPos)
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        // cout << (std::abs(newPos/8-_position/8)>0) << "--" << (std::abs(newPos%8-_position%8) > 0);
        if(!((std::abs(newPos/8-_position/8)>0)  != (std::abs(newPos%8-_position%8) > 0)) )//Immer nur in eine richtung für den Turm
            ret = false;
    }
    return ret;
}
vector<int> Rock::getStepsBetween(int newPos)
{
    vector<int> ret;
    ret = {-1};
    int p1 = _position>newPos?newPos:_position;
    int p2 = _position<newPos?newPos:_position;
    bool vertical=(_position/8 - newPos/8)!=0;
    if (vertical)
    {
        ret.clear();
        for (int i =p1+8; i<=p2-8; i+=8)
        {
            ret.push_back(i);
        }
    }
    else
    {
        ret.clear();
        for (int i =p1+1; i<=p2-1; i+=1)
        {
            ret.push_back(i);
        }
    }


    return ret;
}

