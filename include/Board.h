#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"
#include <vector>

using namespace std;
class Board
{
public:
    Board();
    virtual ~Board();
    vector<Piece> getBlack();
    void setBlack(vector<Piece>);
    vector<Piece> getWhite();
    void setWhite(vector<Piece>);
friend    ostream& operator<<(ostream& s , const Board& rhs ) ;
protected:

private:
    vector<Piece> _black;
    vector<Piece> _white;
};

#endif // BOARD_H
