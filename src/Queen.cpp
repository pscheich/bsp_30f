#include "Queen.h"
#include <cmath>
using namespace std;
Queen::Queen()
{
    //ctor
}
Queen::Queen(int pos, bool black):Piece(pos,black? "Q" : "q",black)
{
    //ctor
}
Queen::Queen(int pos, bool black,bool unicode):Piece(pos,unicode?black? "\u265B" : "\u2655":black? "Q" : "q",black)
{
    //ctor
}
Queen::~Queen()
{
    //dtor
}
bool Queen::moveEnabled(int newPos)
{

    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(!(((std::abs(newPos/8-_position/8))  == (std::abs(newPos%8-_position%8) )) //diagonal
                !=
                (  (abs(newPos/8-_position/8)>0)  != (abs(newPos%8-_position%8) > 0)))) // gerade
            ret = false;
    }
    return ret;
}
bool Queen::captureKing(int newPos)
{
    bool ret= true;
    if(!checkInField(newPos))
        ret= false;
    else
    {
        if((!((std::abs(newPos/8-_position/8)>0)  != (std::abs(newPos%8-_position%8) > 0))) || (!((std::abs(newPos/8-_position/8))==(std::abs(newPos%8-_position%8)))))//Immer nur in eine richtung für den Turm
            ret = false;
    }
    return ret;
}
vector<int> Queen::getStepsBetween(int newPos)
{
    vector<int> ret;

    int p1 = _position>newPos?newPos:_position;
    int p2 = _position<newPos?newPos:_position;
    if((std::abs(newPos/8-_position/8)>0)  != (std::abs(newPos%8-_position%8) > 0))
    {
        ret = {-1};

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
    }
    else if((std::abs(newPos/8-_position/8))==(std::abs(newPos%8-_position%8)))
    {

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

    }


    return ret;
}
