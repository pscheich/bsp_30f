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
vector<int> Queen::getStepsBetween(int newPos) //todo
{
    newPos++; //damit warnung verschwindet
    vector<int> ret = {-1};
    return ret;
}
