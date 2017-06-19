#include "Piece.h"
#include <vector>
#include <array>
using namespace std;
Piece::Piece():_position(),_symbol(""),_black(false),_unMoved(true)
{
    //ctor
}
//Piece::Piece(int pos):_position(pos),_symbol("")
//{
//}
Piece::Piece(int pos,  string sym,bool black):_position(pos),_symbol(sym),_black(black),_unMoved(true)
{
}

Piece::~Piece()
{
    //dtor
}

int Piece::getPosition()
{
    return _position;
}

//bool Piece::moveEnabled(int[] newPos)
//{
//    return false;
//}
bool Piece::checkInField(int newPos)
{
    return newPos<64;
}
//ostream& operator<<(ostream& s, const Piece& rhs )
//{
//    s << rhs._symbol;
//    return s;
//}
void Piece::printOnBoard(std::array<string, 64> &board) const
{
//    cout << "---" << _position << "---" <<endl;
    board[_position] = _symbol;

}
string const Piece::getSymbol() const
{
    return _symbol;
}
bool Piece::promotionPossible() const
{
    return false;
}

bool Piece::unmoved() const
{

    return _unMoved;
}
void Piece::setPosition(int newPos)
{
    _unMoved = false;
    _position = newPos;
}
