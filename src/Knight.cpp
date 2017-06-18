#include "Knight.h"
#include <cmath>
using namespace std;
Knight::Knight()
{
    //ctor
}
Knight::Knight(int pos, bool black):Piece(pos,black? "N" : "n",black)
{
    //ctor
}
Knight::Knight(int pos, bool black,bool unicode):Piece(pos,unicode?black? "\u265E" : "\u2658":black? "N" : "n",black)
{
    //ctor
}
Knight::~Knight()
{
    //dtor
}
bool Knight::moveEnabled(int newPos)
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
vector<int> Knight::getStepsBetween(int newPos)
{
    newPos++; //damit warnung verschwindet
    vector<int> ret = {-1};
    return ret;
}
