#include "Board.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rock.h"
#include "Pawn.h"
#include "Piece.h"

#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <array>

using namespace std;

//Board::Board():_black(),_white(),_unicode(false),_winner(0)
//{
//    //ctor
//    init();
//}
Board::Board(bool unicode):_black(),_white(),_unicode(unicode),_winner(0)
{
    //ctor
   // init();
}
Board::~Board()
{
    //dtor
}
void Board::setUnicode(bool unicode)
{

    _unicode = unicode;
}
std::vector<std::unique_ptr<Piece>> const & Board::getBlack() const
{
    return _black;
}

std::vector<std::unique_ptr<Piece>> const & Board::getWhite() const
{
    return _white;
}

int const & Board::getWinner() const
{
    return _winner;
}


ostream& operator<<(ostream& s, const Board& rhs )
{
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#else
    system("clear");
#endif

    array<string, 64> printedBoard;
    fill(begin(printedBoard), end(printedBoard), rhs._unicode?"\u25A1":".");
    for_each(rhs._black.begin(), rhs._black.end(), [&](const unique_ptr<Piece> &p)
    {
        p->printOnBoard(printedBoard);
    });
    for_each(rhs._white.begin(), rhs._white.end(), [&](const unique_ptr<Piece> &p)
    {
        p->printOnBoard(printedBoard);
    });

    s << "  ";
    for(int i =1; i<=17; i++)
    {
        (i%2==0)?s<<i/2:s<<" ";
    }
    s<<endl;
    int count =0;
    for_each(printedBoard.begin(),printedBoard.end(), [&](string &str)
    {

        if ((count)%8==0)
        {
            s << endl;
            s<< (count/8+1) << " ";
        }
        s << " "<<str;
        count++;

    });
    s<< endl;



    return s;
}
void Board::init(bool unicode)
{         std::vector<std::unique_ptr<Piece>>& playersList1 = _black;
    _unicode = unicode;
    for(int i =0; i<8; i++)
    {
        int pos;
        pos=6*8+i;
        std::unique_ptr<Pawn> bauer(new Pawn(pos, true,_unicode));
        _black.emplace_back(std::move(bauer));
    }
    std::unique_ptr<Rock> R1 (new Rock(7*8+0, true,_unicode));
    _black.emplace_back(std::move(R1));
    std::unique_ptr<Rock> R2 (new Rock(7*8+7, true,_unicode));
    _black.emplace_back(std::move(R2));
    std::unique_ptr<Knight> N1 (new Knight(7*8+1, true,_unicode));
    _black.emplace_back(std::move(N1));
    std::unique_ptr<Knight> N2 (new Knight(7*8+6, true,_unicode));
    _black.emplace_back(std::move(N2));
    std::unique_ptr<Bishop> B1 (new Bishop(7*8+2, true,_unicode));
    _black.emplace_back(std::move(B1));
    std::unique_ptr<Bishop> B2 (new Bishop(7*8+5, true,_unicode));
    _black.emplace_back(std::move(B2));
    std::unique_ptr<Queen> Q (new Queen(7*8+3, true,_unicode));
    _black.emplace_back(std::move(Q));
    std::unique_ptr<King> K (new King(7*8+4, true,_unicode));
    _black.emplace_back(std::move(K));
    for(int i =0; i<8; i++)
    {
        int pos;
        pos=1*8+i;
        std::unique_ptr<Pawn> bauer(new Pawn(pos,false,_unicode));
        _white.emplace_back(std::move(bauer));
    }
    std::unique_ptr<Rock> r1 (new Rock(0*8+0, false,_unicode));
    _white.emplace_back(std::move(r1));
    std::unique_ptr<Rock> r2 (new Rock(0*8+7, false,_unicode));
    _white.emplace_back(std::move(r2));
    std::unique_ptr<Knight> n1 (new Knight(0*8+1, false,_unicode));
    _white.emplace_back(std::move(n1));
    std::unique_ptr<Knight> n2 (new Knight(0*8+6, false,_unicode));
    _white.emplace_back(std::move(n2));
    std::unique_ptr<Bishop> b1 (new Bishop(0*8+2, false,_unicode));
    _white.emplace_back(std::move(b1));
    std::unique_ptr<Bishop> b2 (new Bishop(0*8+5, false,_unicode));
    _white.emplace_back(std::move(b2));
    std::unique_ptr<Queen> q (new Queen(0*8+3, false,_unicode));
    _white.emplace_back(std::move(q));
    std::unique_ptr<King> k (new King(0*8+4, false,_unicode));
    _white.emplace_back(std::move(k));
         std::vector<std::unique_ptr<Piece>>& playersList = _black;

}

bool Board::move(int const &  posStart, int const & posEnd,bool const & black)
{
    bool ret=false;
      std::vector<std::unique_ptr<Piece>>& playersList1 = (black?_black:_white);
      std::vector<std::unique_ptr<Piece>>& otherplayersList2 = (black?_white:_black);
    auto  figure = std::find_if((black?_black:_white).begin(),(black?_black:_white).end(), [&](std::unique_ptr<Piece> & piece)
    {
        return piece->getPosition() == posStart;
    });
    bool found = figure != (black?_black:_white).end(); //check ob figur an position
    if(found)
    {
        string bla = (*figure)->getSymbol();
        int bla2 = (*figure)->getPosition();
        if((*figure)->moveEnabled(posEnd))
        {
            (*figure)->setPosition(posEnd);
            auto  figureGeschlagen = std::find_if( (black?_white:_black).begin(), (black?_white:_black).end(), [&](std::unique_ptr<Piece> & piece)
            {
                return piece->getPosition() == posEnd;
            });

            if(figureGeschlagen != (black?_white:_black).end())  //TODO ABfrage ob da schon andere figur von spieler
                 (black?_white:_black).erase(figureGeschlagen);      //TODO Frage ob schachmatt
            ret=true;
        }
    }
     std::vector<std::unique_ptr<Piece>>& playersList = _black;
         std::vector<std::unique_ptr<Piece>>& otherplayersList = _white;
    return ret;
}
