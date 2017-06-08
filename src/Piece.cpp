#include "Piece.h"
using namespace std;
Piece::Piece():_position()
{
    //ctor
}

Piece::Piece(vector<int> pos):_position(pos)
{
}

Piece::~Piece()
{
    //dtor
}

vector<int> Piece::getPosition()
{
    return _position;
}
void Piece::setPosition(vector<int> pos)
{
    _position = pos;
}
//bool Piece::moveEnabled(vector<int> newPos)
//{
//    return false;
//}
bool Piece::checkInField(vector<int> newPos)
{
    return newPos.at(0)<=7 && newPos.at(1)<= 7;
}
ostream& Piece::operator<<(ostream& s , const Piece& rhs ){
s << " "
return s;
}
