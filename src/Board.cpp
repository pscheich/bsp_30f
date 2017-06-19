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
//}-
Board::Board(bool unicode):_black(),_white(),_unicode(unicode),_winner(0),_remiscounter50(0)
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

void Board::initTest(bool unicode)
{
    _unicode = unicode;
    for(int i =0; i<8; i++)
    {
        int pos;
        pos=1*8+i;
        std::unique_ptr<Pawn> bauer(new Pawn(pos, true,_unicode));
        _black.emplace_back(std::move(bauer));
    }
    std::unique_ptr<Rock> R1 (new Rock(7*8+0, true,_unicode));
    _black.emplace_back(std::move(R1));
    std::unique_ptr<Rock> R2 (new Rock(7*8+7, true,_unicode));
    _black.emplace_back(std::move(R2));
    std::unique_ptr<Knight> N1 (new Knight(7*8+1, true,_unicode));
    _black.emplace_back(std::move(N1));
    std::unique_ptr<Knight> N2 (new Knight(5*8+6, true,_unicode));
    _black.emplace_back(std::move(N2));
    std::unique_ptr<Bishop> B1 (new Bishop(5*8+2, true,_unicode));
    _black.emplace_back(std::move(B1));
    std::unique_ptr<Bishop> B2 (new Bishop(5*8+5, true,_unicode));
    _black.emplace_back(std::move(B2));
    std::unique_ptr<Queen> Q (new Queen(5*8+3, true,_unicode));
    _black.emplace_back(std::move(Q));
    std::unique_ptr<King> K (new King(7*8+4, true,_unicode));
    _black.emplace_back(std::move(K));
    for(int i =0; i<8; i++)
    {
        int pos;
        pos=6*8+i;
        std::unique_ptr<Pawn> bauer(new Pawn(pos,false,_unicode));
        _white.emplace_back(std::move(bauer));
    }
    std::unique_ptr<Rock> r1 (new Rock(0*8+0, false,_unicode));
    _white.emplace_back(std::move(r1));
    std::unique_ptr<Rock> r2 (new Rock(0*8+7, false,_unicode));
    _white.emplace_back(std::move(r2));
    std::unique_ptr<Knight> n1 (new Knight(2*8+1, false,_unicode));
    _white.emplace_back(std::move(n1));
    std::unique_ptr<Knight> n2 (new Knight(2*8+6, false,_unicode));
    _white.emplace_back(std::move(n2));
    std::unique_ptr<Bishop> b1 (new Bishop(2*8+2, false,_unicode));
    _white.emplace_back(std::move(b1));
    std::unique_ptr<Bishop> b2 (new Bishop(2*8+5, false,_unicode));
    _white.emplace_back(std::move(b2));
    std::unique_ptr<Queen> q (new Queen(2*8+3, false,_unicode));
    _white.emplace_back(std::move(q));
    std::unique_ptr<King> k (new King(0*8+4, false,_unicode));
    _white.emplace_back(std::move(k));

}

void Board::init(bool unicode)
{
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

}
bool Board::CheckFreeWay(int const &  posStart, int const & posEnd,bool const & black)  //check ob weg frei
{
    bool ret=true;
    auto  figure = std::find_if((black?_black:_white).begin(),(black?_black:_white).end(), [&](std::unique_ptr<Piece> & piece)
    {
        return piece->getPosition() == posStart;
    });
    bool found = figure != (black?_black:_white).end(); //check ob figur an position
    if(found)
    {
        vector <int> toCheck = (*figure)->getStepsBetween(posEnd);
        if(toCheck[0]!=-1)
        {
            for(int n : toCheck)
            {
                auto  gegnerFigur = std::find_if( (black?_white:_black).begin(), (black?_white:_black).end(), [&](std::unique_ptr<Piece> & piece)
                {
                    return piece->getPosition() == n;
                });

                if(gegnerFigur != (black?_white:_black).end())  //TODO ABfrage ob da schon andere figur von spieler
                    ret = false;
                auto  eigeneFigur = std::find_if( (black?_black:_white).begin(), (black?_black:_white).end(), [&](std::unique_ptr<Piece> & piece)
                {
                    return piece->getPosition() == n;
                });

                if(eigeneFigur != (black?_black:_white).end())  //TODO ABfrage ob da schon andere figur von spieler
                    ret = false;
            }
        }
    }
    return ret;
}
bool Board::checkIfFree(int const & pos)
{
    bool ret=true;
    auto  figureB = std::find_if(_black.begin(),_black.end(), [&](std::unique_ptr<Piece> & piece)
    {
        return piece->getPosition() == pos;
    });
    if(figureB!=_black.end())
    {
        ret = false;
    }
    auto  figureW = std::find_if(_white.begin(),_white.end(), [&](std::unique_ptr<Piece> & piece)
    {
        return piece->getPosition() == pos;
    });
    if(figureW!=_white.end())
    {
        ret = false;
    }
    return ret;
}
bool Board::checkIfOwnPiece( int const & posEnd,bool const & black)
{
    bool ret=true;
    auto  figure = std::find_if((black?_black:_white).begin(),(black?_black:_white).end(), [&](std::unique_ptr<Piece> & piece)
    {
        return piece->getPosition() == posEnd;
    });
    bool found = figure != (black?_black:_white).end(); //check ob figur an position
    if(found)
    {
        ret = false;
    }
    return ret;
}

bool Board::move(int const &  posStart, int const & posEnd,bool const & black)
{
    _remiscounter50++;
    auto &figurenSpieler = (black?_black:_white) ;
    auto &figurenGegner = (black?_white:_black);
    bool ret=false;
    auto  figure = std::find_if(figurenSpieler.begin(),figurenSpieler.end(), [&](std::unique_ptr<Piece> & piece)
    {
        return piece->getPosition() == posStart;
    });
    bool found = figure != figurenSpieler.end(); //check ob figur an position
    if(found)
    {
        if((*figure)->moveEnabled(posEnd)&&(CheckFreeWay(posStart,posEnd,black))&&checkIfOwnPiece(posEnd,black))
        {
            ret=true;
            (*figure)->setPosition(posEnd);

            auto  figureGeschlagen = std::find_if( figurenGegner.begin(), figurenGegner.end(), [&](std::unique_ptr<Piece> & piece)
            {
                return piece->getPosition() == posEnd;
            });

            if(figureGeschlagen != figurenGegner.end())
            {
                if(dynamic_cast<Pawn *>(figure->get()) != nullptr) // wenn bauer geraudeaus schlagen will
                {
                    (*figure)->setPosition(posStart);
                    ret=false;
                }
                else
                {
                    figurenGegner.erase(figureGeschlagen);
                }
                _remiscounter50=0;
            }
            if(dynamic_cast<Pawn *>(figure->get()) != nullptr) //schachmatt
            {
                _remiscounter50=0;
            }

            //Bauernumwandlung
            pawnPromotion(figure,black);

            if(dynamic_cast<King *>(figureGeschlagen->get()) != nullptr) //schachmatt
            {
                black?_winner=2:_winner=1;
            }


        }
        else
        {
            //rochade
            rochade(figure, black, ret,posStart,posEnd);
        }
    }
    if(_remiscounter50 ==50)
        _winner=3;
    return ret;
}
void Board::rochade(std::vector<std::unique_ptr<Piece>>::iterator & figure, const bool& black, bool & ret, const int & posStart, const int & posEnd)
{
    auto &figurenSpieler = (black?_black:_white) ;
    if(dynamic_cast<King *>(figure->get()) != nullptr)
    {
        if((*figure)->unmoved())
        {
            int foo = posEnd - posStart;

            switch(foo)
            {
            case 2:
            {
                if (!black)
                {
                    auto  turm = std::find_if(figurenSpieler.begin(),figurenSpieler.end(), [&](std::unique_ptr<Piece> & piece)
                    {
                        return piece->getPosition() == 7;
                    });
                    if (turm!=figurenSpieler.end())
                    {
                        if ((*turm)->unmoved()&&checkIfFree(5)&&checkIfFree(6))
                        {
                            (*turm)->setPosition(5);
                            (*figure)->setPosition(6);
                            ret=true;
                        }
                    }
                }
                else
                {

                    auto  turm = std::find_if(figurenSpieler.begin(),figurenSpieler.end(), [&](std::unique_ptr<Piece> & piece)
                    {
                        return piece->getPosition() == 63;
                    });
                    if (turm!=figurenSpieler.end())
                    {
                        if ((*turm)->unmoved()&&checkIfFree(61)&&checkIfFree(62))
                        {
                            (*turm)->setPosition(61);
                            (*figure)->setPosition(62);
                            ret=true;
                        }
                    }
                }
                break;
            }

            case -2:
            {
                if (!black)
                {
                    auto  turm = std::find_if(figurenSpieler.begin(),figurenSpieler.end(), [&](std::unique_ptr<Piece> & piece)
                    {
                        return piece->getPosition() == 0;
                    });
                    if (turm!=figurenSpieler.end())
                    {
                        if ((*turm)->unmoved()&&checkIfFree(1)&&checkIfFree(2)&&checkIfFree(3))
                        {
                            (*turm)->setPosition(3);
                            (*figure)->setPosition(2);
                            ret=true;
                        }
                    }
                }
                else
                {
                    auto  turm = std::find_if(figurenSpieler.begin(),figurenSpieler.end(), [&](std::unique_ptr<Piece> & piece)
                    {
                        return piece->getPosition() == 56;
                    });
                    if (turm!=figurenSpieler.end())
                    {
                        if ((*turm)->unmoved()&&checkIfFree(57)&&checkIfFree(58)&&checkIfFree(59))
                        {
                            (*turm)->setPosition(59);
                            (*figure)->setPosition(58);
                            ret=true;
                        }
                    }
                }
                break;
            }
            default:
            {
                break;
            }

            }
        }
    }



}
void Board::pawnPromotion(std::vector<std::unique_ptr<Piece>>::iterator & figure,const bool & black)
{
    if((*figure)->promotionPossible())
    {
        cout << "Promote your Pawn: \n Please choose: \n";
        cout << "1: Queen \n";
        cout << "2: Rock \n";
        cout << "3: Knight \n";
        cout << "4: Bishop \n";

        int choose;
        while(!((cin >> choose)&&(choose>0&&choose<5)))
        {

            cin.clear();
            cin.ignore( 1000, '\n' );
            cout << "Bad value! Input an integer between 1 and 4. \n";
        }
        int posAkt = (*figure)-> getPosition();
        (black?_black:_white).erase(figure);
        switch (choose)
        {
        case 1:
        {
            std::unique_ptr<Queen> foo (new Queen(posAkt, black,_unicode));
            (black?_black:_white).emplace_back(std::move(foo));
            break;
        }
        case 2:
        {
            std::unique_ptr<Rock> foo (new Rock(posAkt, black,_unicode));
            (black?_black:_white).emplace_back(std::move(foo));
            break;
        }
        case 3:
        {
            std::unique_ptr<Knight> foo (new Knight(posAkt, black,_unicode));
            (black?_black:_white).emplace_back(std::move(foo));
            break;
        }
        case 4:
        {
            std::unique_ptr<Bishop> foo (new Bishop(posAkt, black,_unicode));
            (black?_black:_white).emplace_back(std::move(foo));
            break;
        }
        default:
            break;
        }
    }

}
