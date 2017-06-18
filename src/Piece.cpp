#include "Piece.h"
#include <vector>
#include <array>
using namespace std;
Piece::Piece():_position(),_symbol(""),_black(false)
{
    //ctor
}
//Piece::Piece(int pos):_position(pos),_symbol("")
//{
//}
Piece::Piece(int pos,  string sym,bool black):_position(pos),_symbol(sym),_black(black)
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
void Piece::setPosition(int pos)
{
    _position = pos;
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
