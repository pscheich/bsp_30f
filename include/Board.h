#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"
#include <memory>
#include <vector>

using namespace std;
class Board
{
public:
    Board(bool unicode);
//   Board();
    virtual ~Board();
    std::vector<std::unique_ptr<Piece>>  const & getBlack() const;
    //  void setBlack(std::vector<std::unique_ptr<Piece>> const &  b) ;
    std::vector<std::unique_ptr<Piece>>  const &  getWhite() const;
//   void setWhite(std::vector<std::unique_ptr<Piece>> const &  w) ;
    friend    ostream& operator<<(ostream& s, const Board& rhs ) ;
    bool move(int const &  posStart, int const & posEnd, bool const&  black);

    void setUnicode(bool unicode);

    void init(bool unicode =false);
    void initTest(bool unicode =false);
    int const & getWinner() const;

protected:

private:
    std::vector<std::unique_ptr<Piece>> _black;
    std::vector<std::unique_ptr<Piece>> _white;
    bool CheckFreeWay(std::unique_ptr<Piece>& figure, const int& posEnd);
    void rochade(std::vector<std::unique_ptr<Piece>>::iterator & figure,const bool& black, bool & ret, const int & posStart, const int & posEnd);
    void enPassant(std::vector<std::unique_ptr<Piece>>::iterator & figure,const bool& black, bool & ret, const int & posStart, const int & posEnd);
    bool checkIfMovesPosible(const bool& black) ;
    bool kingIsSafe(const bool & black, const vector<int>& fields);
    bool checkIfFree(vector<int> const & pos);
    bool checkIfOwnPiece( int const & posEnd,bool const & black);
    bool _unicode;
    int _winner; //0 , 1schwarz,2weis,3remis
    void pawnPromotion(std::vector<std::unique_ptr<Piece>>::iterator & figure,const bool & black);
    int _remiscounter50;
    int _lastwasdouble;

    vector<vector<std::unique_ptr<Piece>>> _positionsBlack;
    vector<vector<std::unique_ptr<Piece>>> _positionsWhite;
};

#endif // BOARD_H
