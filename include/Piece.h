#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <iostream>
#include <array>
#include <memory>
#include <string>
using namespace std;

class Piece
{
public:
    Piece();
    Piece(int pos, string sym,bool black);
    Piece(int x,int y, string sym,bool black);
    Piece(int pos);
//    Piece(const Piece& _rhs){}; // copy constructor
    virtual std::unique_ptr<Piece> clone() const = 0;

    virtual ~Piece();
    virtual  bool moveEnabled(int newPos)=0;
    virtual  bool captureKing(int newPos)=0;
    virtual  bool promotionPossible() const ;
    int getPosition();
    bool  getBlack() const;
    void setPosition(int newPos);
    bool unmoved() const;

    void printOnBoard(std::array<string, 64> &board) const;
    string const getSymbol() const;
    virtual vector<int> getStepsBetween(int newPos) =0;


    friend ostream& operator<<(ostream& s, const Piece& rhs );
protected:
    bool checkInField(int newPos);
    int _position;
    string _symbol;
    bool _black;
    bool _unMoved;
private:



};

#endif // PIECE_H
