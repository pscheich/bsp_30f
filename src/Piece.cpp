/**
 * Piece Source
 * @author Patrick Scheich
 */

#include "Piece.h"
#include <vector>
#include <array>
using namespace std;
Piece::Piece():_position(),_symbol(""),_black(false),_unMoved(true)
{
    //ctor
}

Piece::Piece(const int pos,  string sym,const bool black):_position(pos),_symbol(sym),_black(black),_unMoved(true)
{
}

Piece::~Piece()
{
    //dtor
}
bool Piece::moveEnabled4Capture(const int newPos)  const
{
    return moveEnabled(newPos);
}
int Piece::getPosition() const
{
    return _position;
}


bool Piece::checkInField(const int newPos) const
{
    return newPos<64;
}

void Piece::printOnBoard(std::array<string, 64> &board) const
{
    board[_position] = _symbol;
}
string const Piece::getSymbol() const
{
    return _symbol;
}
bool  Piece::getBlack() const
{
    return _black;
}
bool Piece::promotionPossible() const
{
    return false;
}

bool Piece::unmoved() const
{
    return _unMoved;
}
void Piece::setPosition(const int newPos)
{
    _unMoved = false;
    _position = newPos;
}
void Piece::setPosition4Test(const int newPos)
{
    _position = newPos;
}
