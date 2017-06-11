#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <iostream>
#include <array>
using namespace std;
class Piece
{
public:
    Piece();
    Piece(int pos, string sym);
    Piece(int x,int y, string sym);
    Piece(int pos);
    virtual ~Piece();
   virtual  bool moveEnabled(int newPos)=0;
    int getPosition();
    void setPosition(int posPiece);
    friend ostream& operator<<(ostream& s, const Piece& rhs );
    void printOnBoard(std::array<string, 64> &board) const;

protected:
    bool checkInField(int newPos);
    int _position;
    string _symbol;
private:



};

#endif // PIECE_H
