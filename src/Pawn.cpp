#include "Pawn.h"
#include <cmath>
using namespace std;
Pawn::Pawn()
{
    //ctor2659
}
//Pawn::Pawn(int pos, bool black):Piece(pos,black? "P" : "p",black),_unMoved(true)
//{
//}
Pawn::Pawn(int pos, bool black,bool unicode):Piece(pos,unicode?black? "\u265F" : "\u2659":black? "P" : "p",black)
{
    //ctor
}
Pawn::~Pawn()
{
    //dtor
}
bool Pawn::moveEnabled(int newPos)
{
    bool ret= true;

    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(_black != !((newPos/8-_position/8)>0 ))  //tests ob rückwärtslaufen
        {
            ret= false;

        }

        else if(_unMoved)       //unbewegt für 2er schritt
        {

            if(!((std::abs(newPos%8-_position%8)==0)
                    && ((std::abs(newPos/8-_position/8) == 1) || (std::abs(newPos/8-_position/8) == 2) ))) //Zweischritte Bauer
                ret = false;
        }
        else
        {
            if(!(std::abs(newPos%8-_position%8)==0  && std::abs(newPos/8-_position/8) == 1)) //Ein schritt bauer
                ret = false;
        }

    }
    return ret;
}
bool Pawn::captureKing(int newPos)
{
    bool ret= true;

    if(!checkInField(newPos))
        ret= false;
    else
    {
        if(_black != !((newPos/8-_position/8)>0 ))  //tests ob rückwärtslaufen
        {
            ret= false;

        }

        else
        {
            if(!(std::abs(newPos%8-_position%8)==1  && std::abs(newPos/8-_position/8) == 1)) //Ein schritt bauer
                ret = false;
        }

    }
    return ret;
}
vector<int> Pawn::getStepsBetween(int newPos)
{
    vector<int> ret = {-1};

    if(std::abs(newPos/8-_position/8) == 2)  //Zweischritte Bauer
        ret = {_black?_position-8:_position+8};
    return ret;
}

bool Pawn::promotionPossible() const
{
    bool ret;
    if(_black && _position/8==0)
        ret = true;
    else if (!_black && _position/8==7)
        ret = true;
    return ret;
}
