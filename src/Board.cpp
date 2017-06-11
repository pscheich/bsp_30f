#include "Board.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rock.h"
#include "Pawn.h"
#include "Piece.h"
#include "Empty.h"
#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <array>
using namespace std;

Board::Board():_black(),_white(),_unicode(false)
{
    //ctor
    init();
}
Board::Board(bool unicode):_black(),_white(),_unicode(unicode)
{
    //ctor
    init();
}
Board::~Board()
{
    //dtor
}

std::vector<std::unique_ptr<Piece>> const & Board::getBlack() const
{
    return _black;
}

std::vector<std::unique_ptr<Piece>> const & Board::getWhite() const
{
    return _white;
}
void Board::print()
{
    //system("clear");
    std::array<string, 64> printedBoard;
    std::fill(std::begin(printedBoard), std::end(printedBoard), _unicode?"\u25A1":"0");
    std::for_each(_black.begin(), _black.end(), [&](std::unique_ptr<Piece> &p)
    {
        p->printOnBoard(printedBoard);
        // cout << p->getPosition() << " ";
    });
    std::for_each(_white.begin(), _white.end(), [&](std::unique_ptr<Piece> &p)
    {
        p->printOnBoard(printedBoard);
        //      cout << p->getPosition()<<" ";
    });
 //   for(int i = 0; i <8; ++i)
  // {//            for(std::string::iterator it = s.begin(); it != s.end(); ++it)
//            {
//                cout << *it;
//            }
//  std::copy_n(s.data(), s.size(), std::ostreambuf_iterator<char>(std::cout));


            // std::copy_n(printedBoard.data() + i * 8, 8, std::ostreambuf_iterator<char>(std::cout));




        int count =0;
        for_each(printedBoard.begin(),printedBoard.end(), [&](string &s)
        {
            cout << s;
            if ((count+1)%8==0) cout << endl;
            count++;

        });

    std::cout << "\n";

    cout << endl;
}

ostream& operator<<(ostream& s, const Board& rhs )
{

//    rhs.print(); //TODO

    return s;
}
void Board::init()
{
//    for(int i=0; i<8; i++)
//    {
//        for(int j=0; j<8; j++)
//        {
//        int pos;
//        pos[0]=i; pos[1]=j;
//        std::unique_ptr<Empty> p(new Empty(pos));
//        _black.emplace_back(std::move(p));
//        }
//
//    }
    for(int i =0; i<8; i++)
    {
        int pos;
        pos=6*8+i;
        std::unique_ptr<Pawn> bauer(new Pawn(pos, false,_unicode));
        _black.emplace_back(std::move(bauer));
    }
    std::unique_ptr<Rock> R1 (new Rock(7*8+0, false,_unicode));
    _black.emplace_back(std::move(R1));
    std::unique_ptr<Rock> R2 (new Rock(7*8+7, false,_unicode));
    _black.emplace_back(std::move(R2));
    std::unique_ptr<Knight> N1 (new Knight(7*8+1, false,_unicode));
    _black.emplace_back(std::move(N1));
    std::unique_ptr<Knight> N2 (new Knight(7*8+6, false,_unicode));
    _black.emplace_back(std::move(N2));
    std::unique_ptr<Bishop> B1 (new Bishop(7*8+2, false,_unicode));
    _black.emplace_back(std::move(B1));
    std::unique_ptr<Bishop> B2 (new Bishop(7*8+5, false,_unicode));
    _black.emplace_back(std::move(B2));
    std::unique_ptr<Queen> Q (new Queen(7*8+4, false,_unicode));
    _black.emplace_back(std::move(Q));
    std::unique_ptr<King> K (new King(7*8+3, false,_unicode));
    _black.emplace_back(std::move(K));
    for(int i =0; i<8; i++)
    {
        int pos;
        pos=1*8+i;
        std::unique_ptr<Pawn> bauer(new Pawn(pos,true,_unicode));
        _white.emplace_back(std::move(bauer));
    }
    std::unique_ptr<Rock> r1 (new Rock(0*8+0, true,_unicode));
    _white.emplace_back(std::move(r1));
    std::unique_ptr<Rock> r2 (new Rock(0*8+7, true,_unicode));
    _white.emplace_back(std::move(r2));
    std::unique_ptr<Knight> n1 (new Knight(0*8+1, true,_unicode));
    _white.emplace_back(std::move(n1));
    std::unique_ptr<Knight> n2 (new Knight(0*8+6, true,_unicode));
    _white.emplace_back(std::move(n2));
    std::unique_ptr<Bishop> b1 (new Bishop(0*8+2, true,_unicode));
    _white.emplace_back(std::move(b1));
    std::unique_ptr<Bishop> b2 (new Bishop(0*8+5, true,_unicode));
    _white.emplace_back(std::move(b2));
    std::unique_ptr<Queen> q (new Queen(0*8+4, true,_unicode));
    _white.emplace_back(std::move(q));
    std::unique_ptr<King> k (new King(0*8+3, true,_unicode));
    _white.emplace_back(std::move(k));
}

//bool is_odd(int pos)
//{
//  return piece->getPosition() == pos;
//}
bool Board::move(int const &  posStart, int const & posEnd,bool black)
{

    bool ret=false;


    auto  figure = std::find_if((black?_black:_white).begin(), (black?_black:_white).end(), [&](std::unique_ptr<Piece> & piece)
    {
        return piece->getPosition() == posStart;
    });
    bool found = figure != (black?_black:_white).end();
    if(found)
    {
        //int p = (*figure)->getPosition();
        if((*figure)->moveEnabled(posEnd))
        {
            (*figure)->setPosition(posEnd);
            auto  figureGeschlagen = std::find_if((black?_white:_black).begin(), (black?_white:_black).end(), [&](std::unique_ptr<Piece> & piece)
            {
                return piece->getPosition() == posEnd;
            });

            if(figureGeschlagen != (black?_white:_black).end())  //TODO ABfrage ob da schon andere figur von spieler
                (black?_white:_black).erase(figureGeschlagen);

//            std::remove_if((black?_white:_black).begin(), (black?_white:_black).end(), [&](std::unique_ptr<Piece> & piece)
//            {
//                return piece->getPosition() == posEnd;
//            });
//            (black?_white:_black).erase(black?_white:_black).end());
            ret=true;

        }

    }



    return ret;
}
