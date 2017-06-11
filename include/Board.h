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
    bool checkIfFigure(int pos, bool black)const;
    void setUnicode(bool unicode);

    void init(bool unicode =false);
    int const & getWinner() const;

protected:

private:
        std::vector<std::unique_ptr<Piece>> _black;
    std::vector<std::unique_ptr<Piece>> _white;

    bool _unicode;
    int _winner;
};

#endif // BOARD_H
