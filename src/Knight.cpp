#include "Knight.h"
#include <cmath>
using namespace std;
Knight::Knight()
{
    //ctor
}
Knight::Knight(int pos, bool black):Piece(pos,black? "N" : "n")
{
    //ctor
}
Knight::Knight(int pos, bool black,bool unicode):Piece(pos,unicode?black? "\u265E" : "\u2659":black? "N" : "n")
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
        if(!(((abs(newPos/8-_position/8))==1 ) ||( abs(newPos%8-_position%8) == 1)) )//Immer nur ein Schritt für den König
            ret = false;
    }
    return ret;
}

