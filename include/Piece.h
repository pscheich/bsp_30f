#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <iostream>
using namespace std;
class Piece
{
public:
    Piece();
    Piece(vector<int> pos);
    virtual ~Piece();
    virtual bool moveEnabled(vector<int> newPosition)=0;
    virtual vector<int> getPosition();
    virtual void setPosition(vector<int> posPiece);
    friend ostream& operator<<(ostream& s , const Piece& rhs );
protected:
 bool checkInField(vector<int> newPos);
    vector<int> _position;
private:



};

#endif // PIECE_H
