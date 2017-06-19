#include "Bishop.h"
#include <cmath>
using namespace std;
Bishop::Bishop()
{
    //ctor
}
Bishop::Bishop(int pos, bool black):Piece(pos,black? "B" : "b",black)
{
    //ctor
}
Bishop::Bishop(int pos, bool black,bool unicode):Piece(pos,unicode?black? "\u265D" : "\u2657":black? "B" : "b",black)
{
    //ctor
}
Bishop::~Bishop()
{
    //dtor
}
bool Bishop::moveEnabled(int newPos)
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(!((std::abs(newPos/8-_position/8))==(std::abs(newPos%8-_position%8))))
            ret = false;
    }
    return ret;
}
bool Bishop::captureKing(int newPos)
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(!((std::abs(newPos/8-_position/8))==(std::abs(newPos%8-_position%8))))
            ret = false;
    }
    return ret;
}
vector<int> Bishop::getStepsBetween(int newPos)
{
    vector<int> ret;

    int p1 = _position>newPos?newPos:_position;
    int p2 = _position<newPos?newPos:_position;
        int steps=p2%8-p1%8;
    if (steps>1)
    {
        for (int i =p1+9; i<=p2-9; i+=9)
        {
            ret.push_back(i);
        }
    }
    else if (steps<-1)
    {
        for (int i =p1+7; i<=p2-7; i+=7)
        {
            ret.push_back(i);
        }
    }
    else
    {
        ret = {-1};
    }

    return ret;
}
