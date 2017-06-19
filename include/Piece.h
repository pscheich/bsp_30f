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
    Piece(int pos, string sym,bool black);
    Piece(int x,int y, string sym,bool black);
    Piece(int pos);
    virtual ~Piece();
    virtual  bool moveEnabled(int newPos)=0;
    virtual  bool captureKing(int newPos)=0;
    int getPosition();
     bool  getBlack() const;
    void setPosition(int newPos);
    friend ostream& operator<<(ostream& s, const Piece& rhs );
    void printOnBoard(std::array<string, 64> &board) const;
    string const getSymbol() const;
    virtual vector<int> getStepsBetween(int newPos) =0;
    virtual  bool promotionPossible() const;
    bool unmoved() const;
protected:
    bool checkInField(int newPos);
    int _position;
    string _symbol;
    bool _black;
    bool _unMoved;
private:



};

#endif // PIECE_H
