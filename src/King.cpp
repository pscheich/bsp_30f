#include "King.h"
#include <cmath>
using namespace std;
King::King()
{
    //ctor
}
King::King(int pos, bool black):Piece(pos,black? "K" : "k",black)
{
}
King::King(int pos, bool black,bool unicode):Piece(pos,unicode?black? "\u265A" : "\u2654":black? "K" : "k",black)
{
    //ctor
}
King::~King()
{
    //dtor
}

bool King::moveEnabled(int newPos)
{
    bool ret= false;
    if(checkInField(newPos))
    {
        if((std::abs(newPos/8-_position/8)==1)  && (std::abs(newPos%8-_position%8) == 1))// diagonal//Immer nur ein Schritt f�r den K�nig
            ret = true;
        else if((std::abs(newPos/8-_position/8)==0)  && (std::abs(newPos%8-_position%8) == 1))// vor zuruck //Immer nur ein Schritt f�r den K�nig
            ret = true;
        else if((std::abs(newPos/8-_position/8)==1)  && (std::abs(newPos%8-_position%8) == 0))// links rechts //Immer nur ein Schritt f�r den K�nig
            ret = true;
    }
    return ret;
}
bool King::captureKing(int newPos)
{
    bool ret= false;
    if(checkInField(newPos))
    {
        if((std::abs(newPos/8-_position/8)==1)  && (std::abs(newPos%8-_position%8) == 1))// diagonal//Immer nur ein Schritt f�r den K�nig
            ret = true;
        else if((std::abs(newPos/8-_position/8)==0)  && (std::abs(newPos%8-_position%8) == 1))// vor zuruck //Immer nur ein Schritt f�r den K�nig
            ret = true;
        else if((std::abs(newPos/8-_position/8)==1)  && (std::abs(newPos%8-_position%8) == 0))// links rechts //Immer nur ein Schritt f�r den K�nig
            ret = true;
    }
    return ret;
}
vector<int> King::getStepsBetween(int newPos)
{
    newPos++; //damit warnung verschwindet
    vector<int> ret = {-1};
    return ret;
}
