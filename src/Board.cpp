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
Board::Board(bool unicode):_black(),_white(),_unicode(unicode),_winner(0),_remiscounter50(0),_lastwasdouble(-1),_positionsBlack(),_positionsWhite()
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

int Board::getWinner() const
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

    std::unique_ptr<Rock> R1 (new Rock(1*8+6, true,_unicode));
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
    std::unique_ptr<King> K (new King(7*8+3, true,_unicode));
    _black.emplace_back(std::move(K));
    std::unique_ptr<Pawn> P1 (new Pawn(3*8+1, true,_unicode));
    _black.emplace_back(std::move(P1));
    std::unique_ptr<Pawn> P2 (new Pawn(6*8+7, true,_unicode));
    _black.emplace_back(std::move(P2));
    std::unique_ptr<Pawn> P3 (new Pawn(6*8+1, true,_unicode));
    _black.emplace_back(std::move(P3));
    std::unique_ptr<Pawn> P4 (new Pawn(6*8+3, true,_unicode));
    _black.emplace_back(std::move(P4));
    std::unique_ptr<Pawn> P5 (new Pawn(1*8+7, true,_unicode));
    _black.emplace_back(std::move(P5));

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
    std::unique_ptr<King> k (new King(0*8+3, false,_unicode));
    _white.emplace_back(std::move(k));
    std::unique_ptr<Pawn> p1 (new Pawn(1*8+0, false,_unicode));
    _white.emplace_back(std::move(p1));
    std::unique_ptr<Pawn> p4 (new Pawn(6*8+2, false,_unicode));
    _white.emplace_back(std::move(p4));
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
    std::unique_ptr<Queen> Q (new Queen(7*8+4, true,_unicode));
    _black.emplace_back(std::move(Q));
    std::unique_ptr<King> K (new King(7*8+3, true,_unicode));
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
    std::unique_ptr<Queen> q (new Queen(0*8+4, false,_unicode));
    _white.emplace_back(std::move(q));
    std::unique_ptr<King> k (new King(0*8+3, false,_unicode));
    _white.emplace_back(std::move(k));

}
bool Board::CheckFreeWay(std::unique_ptr<Piece>& figure, const int posEnd)  //check ob weg frei
{
    bool ret=true;
    const bool black = figure->getBlack();
    auto &figurenSpieler = (black?_black:_white);
    auto &figurenGegner = (black?_white:_black);
    vector <int> toCheck = figure->getStepsBetween(posEnd);
    if(toCheck[0]!=-1)
    {
        for(int n : toCheck)
        {
            auto  gegnerFigur = std::find_if( figurenGegner.begin(), figurenGegner.end(), [&](std::unique_ptr<Piece> & piece)
            {
                return piece->getPosition() == n;
            });

            if(gegnerFigur != figurenGegner.end())  //TODO ABfrage ob da schon andere figur von spieler
                ret = false;
            auto  eigeneFigur = std::find_if( figurenSpieler.begin(), figurenSpieler.end(), [&](std::unique_ptr<Piece> & piece)
            {
                return piece->getPosition() == n;
            });

            if(eigeneFigur != figurenSpieler.end())  //TODO ABfrage ob da schon andere figur von spieler
                ret = false;
        }
    }

    return ret;
}
bool Board::checkIfMovesPossible(const bool black)
{
    bool ret = false;
    auto &figurenSpieler = (black?_black:_white);
    auto  figureB = std::find_if(figurenSpieler.begin(),figurenSpieler.end(), [&](std::unique_ptr<Piece> & piece)
    {
        bool retLambda = false;
        for (int i = 0; i<64; i++)
        {
            if(piece->moveEnabled(i))
            {
                retLambda=true;
            }
        }
        return retLambda;
    });
    if(figureB!=figurenSpieler.end())
    {
        ret = true;
    }
    return ret;
}
bool Board::checkIfFree(vector<int> const & pos)
{
    bool ret=true;
    auto  figureB = std::find_if(_black.begin(),_black.end(), [&](std::unique_ptr<Piece> & piece)
    {
        return find(pos.begin(), pos.end(),  piece->getPosition() )!= pos.end();
//        return piece->getPosition() == pos;
    });
    if(figureB!=_black.end())
    {
        ret = false;
    }
    auto  figureW = std::find_if(_white.begin(),_white.end(), [&](std::unique_ptr<Piece> & piece)
    {
        return find(pos.begin(), pos.end(),  piece->getPosition() )!= pos.end();
    });
    if(figureW!=_white.end())
    {
        ret = false;
    }
    return ret;
}
bool Board::checkIfOwnPiece( int posEnd,const bool black)
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

bool Board::move(const int  posStart, const int posEnd,const bool black)
{
    bool ret=false;
    _remiscounter50++;  //mindestens 50 Zuge lang weder eine Figur geschlagen noch ein Bauer gezogen wurde.

    auto &figurenSpieler = (black?_black:_white);
    auto &figurenGegner = (black?_white:_black);

    vector<std::unique_ptr<Piece>> aufstellung ;
    for_each(figurenSpieler.begin(),figurenSpieler.end(), [&](const unique_ptr<Piece>& p)
    {
        aufstellung.emplace_back(std::move(p->clone()));
    });
    for_each(figurenGegner.begin(),figurenGegner.end(), [&](const unique_ptr<Piece>& p)
    {
        aufstellung.emplace_back(std::move(p->clone()));
    });
    int aufstellungCounter = 0;  // zum mindestens dritten mal dieselbe Stellung mit demselben Spieler am Zug und denselben Zugm¨oglichkeiten vorliegt oder
    if(black)
    {
        aufstellungCounter = std::count_if(_positionsBlack.begin(),_positionsBlack.end(), [&](const vector<std::unique_ptr<Piece>>& p)
        {
            return p==aufstellung;
            _positionsBlack.push_back(std::move(aufstellung));
        });
    }
    else
    {
        aufstellungCounter = std::count_if(_positionsWhite.begin(),_positionsWhite.end(), [&](const vector<std::unique_ptr<Piece>>& p)
        {
            return p==aufstellung;
        });
        _positionsWhite.push_back(std::move(aufstellung));
    }

    if(aufstellungCounter < 3)
    {
        auto  kingPlayer = std::find_if(figurenSpieler.begin(),figurenSpieler.end(), [&](std::unique_ptr<Piece> & piece)
        {
            return dynamic_cast<King *>(piece.get()) != nullptr;
        });
        vector<int> kingPos = {(*kingPlayer)->getPosition()};
        if(checkIfMovesPossible(black)) // der am Zug befindliche Spieler keine Zugm¨oglichkeit hat, sein K¨onig sich jedoch nicht im Schach befindet (d.h. wenn der nicht bedrohter allein ubrig gebliebener ¨K¨onig nicht ziehen kann, ohne bedroht zu werden)
        {
            auto  figure = std::find_if(figurenSpieler.begin(),figurenSpieler.end(), [&](std::unique_ptr<Piece> & piece)
            {
                return piece->getPosition() == posStart;
            });
            bool found = figure != figurenSpieler.end(); //check ob figur an position
            if(found)
            {
                if((*figure)->moveEnabled(posEnd)&&(CheckFreeWay((*figure),posEnd))&&checkIfOwnPiece(posEnd,black))  //ZugRichtung eraubt, Weg ist frei, auf Endposition ist keine eigene Figur, die des Gegners würde geschlagen werden
                {
                    int endPosKing =  (dynamic_cast<King *>(figure->get()) != nullptr)?posEnd:(*kingPlayer)->getPosition();
                    (*figure)->setPosition4Test(posEnd); //Zuziehende Figur wird bewegt, um zu prüfen ob danach der König im Schach steht.
                    vector<int> kingFieldVec = {endPosKing};
                    if(kingIsSafe(black,kingFieldVec))
                    {
                        ret=true;
                        (*figure)->setPosition(posEnd); //der unmoves bool wird jetzt geändert, da der zug ok ist
                        auto  figureGeschlagen = std::find_if( figurenGegner.begin(), figurenGegner.end(), [&](std::unique_ptr<Piece> & piece)  //Gegner Figur wird entfernt
                        {
                            return piece->getPosition() == posEnd;
                        });

                        if(figureGeschlagen != figurenGegner.end())
                        {
                            if(dynamic_cast<Pawn *>(figure->get()) != nullptr) // wenn bauer geraudeaus schlagen will
                            {
                                (*figure)->setPosition(posStart);
                                ret=false;  //Ret ist doch falsch, Ausnahme zu zeile 352
                            }
                            else
                            {
                                figurenGegner.erase(figureGeschlagen);
                                _remiscounter50=0;  // Figur geschlagen, Zähler nullen
                                _positionsWhite.clear();
                                _positionsBlack.clear();//Die können hier geleert werden, da eine figur geshclagen wurde, und die alten situatuionen nicht mehr aufztreten können
                            }
                        }
                        if(dynamic_cast<Pawn *>(figure->get()) != nullptr)
                        {
                            _positionsWhite.clear();
                            _positionsBlack.clear();//Die können hier geleert werden, da einerin bauer gezogen wurde, und die alten situatuionen nicht mehr aufztreten können
                        }
                        if(dynamic_cast<Pawn *>(figure->get()) != nullptr) //remis
                        {
                            _remiscounter50=0;
                        }
                        if(dynamic_cast<Pawn *>(figure->get()) != nullptr && (std::abs(posStart/8-posEnd/8) == 2)) //en passant
                        {
                            _lastwasdouble=posEnd;
                        }
                        else
                            _lastwasdouble=-1;
                        //Bauernumwandlung
                        pawnPromotion(figure,black);  //Implementieren Sie die Verwandlung eines Bauers in eine andre Figur.
//                if(dynamic_cast<King *>(figureGeschlagen->get()) != nullptr) //schachmatt   ## unnötig, da der könig nie geschlagen werden kann, das spiel ist vorher fertig
//                {
//                    black?_winner=2:_winner=1;
//                }
                    }
                    else
                    {
                        (*figure)->setPosition(posStart); //Der König würde nach dem Zug im Schach stehen, die zuziehende FIgur wird zurückgesetzt
                    }
                }
                else
                {
                    //rochade
                    if(!ret)
                        rochade(figure, black, ret,posStart,posEnd); //Implementieren Sie die M¨oglichkeit einer Rochade,

                    //en passant
                    if(!ret&&_lastwasdouble>-1)  //Implementieren Sie die en-passant-Regel.
                    {
                        enPassant(figure, black, ret,posStart,posEnd);
                    }
                    //Bauer schlägt schräg
                    if(dynamic_cast<Pawn *>(figure->get()) != nullptr)
                    {
                        if((*figure)->moveEnabled4Capture(posEnd))
                        {
                            (*figure)->setPosition(posEnd); //der unmoves bool wird jetzt geändert, da der zug ok ist
                            auto  figureGeschlagen = std::find_if( figurenGegner.begin(), figurenGegner.end(), [&](std::unique_ptr<Piece> & piece)  //Gegner Figur wird entfernt
                            {
                                return piece->getPosition() == posEnd;
                            });

                            if(figureGeschlagen != figurenGegner.end())
                            {
                                ret=true;
                                figurenGegner.erase(figureGeschlagen);
                                _remiscounter50=0;  // Figur geschlagen, Zähler nullen
                                _positionsWhite.clear();
                                _positionsBlack.clear();//Die können hier geleert werden, da eine figur geshclagen wurde, und die alten situatuionen nicht mehr aufztreten können
                                pawnPromotion(figure,black);
                            }
                        }
                    }
                }
            }
            if(_remiscounter50 ==50)   //Unendschieden >=50 Züge
                _winner=3;
        }
        else  if(!checkIfMovesPossible(black) && kingIsSafe(black,kingPos))   //Unentschieden keine Zugmöglichkeit König nciht gefährdet
        {
            _winner=3;
            ret = true;
        }
        else  if(!checkIfMovesPossible(black) && !kingIsSafe(black,kingPos)) //Normaler Sieg
        {
            black?_winner=2:_winner=1;
            ret = true;
        }
    }
    else  //Unentschieden drei mal gleiche Aufstellung
    {
        _winner=3;
        ret = true;
    }
    return ret;
}
void Board::enPassant(std::vector<std::unique_ptr<Piece>>::iterator & figure, const bool black, bool& ret, const int posStart, const int posEnd)
{
    auto &figurenGegner = (black?_white:_black);
    if((std::abs(posStart/8-posEnd/8) == 1) && (std::abs(posStart%8-posEnd%8) == 1))
    {
        if(posEnd == _lastwasdouble-8)
        {
            (*figure)->setPosition(posEnd);
            auto  figureGeschlagen = std::find_if( figurenGegner.begin(), figurenGegner.end(), [&](std::unique_ptr<Piece> & piece)
            {
                return piece->getPosition() == _lastwasdouble;
            });

            if(figureGeschlagen != figurenGegner.end())
            {
                figurenGegner.erase(figureGeschlagen);
                _lastwasdouble=-1;
                ret=true;
            }
        }
    }
}
void Board::rochade(std::vector<std::unique_ptr<Piece>>::iterator & figure, const bool black, bool& ret, const int posStart, const int posEnd)
{
    auto &figurenSpieler = (black?_black:_white) ;
    if(dynamic_cast<King *>(figure->get()) != nullptr)
    {
        if((*figure)->unmoved())
        {
            int foo = posEnd - posStart;

            switch(foo)
            {
            case -2:
            {
                if (!black)
                {
                    auto  turm = std::find_if(figurenSpieler.begin(),figurenSpieler.end(), [&](std::unique_ptr<Piece> & piece)// Falls Sie die Rochade-Zusatzaufgabe gemacht haben, implementieren Sie auch alle Rochade-Voraussetzungen.
                    {
                        return piece->getPosition() == 0;
                    });
                    if (turm!=figurenSpieler.end())
                    {
                        vector<int> vec;
                        vec.push_back(1);
                        vec.push_back(2);
                        if ((*turm)->unmoved()&&checkIfFree(vec)&&kingIsSafe(black,vec))
                        {
                            (*turm)->setPosition(2);
                            (*figure)->setPosition(1);
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
                        vector<int> vec;
                        vec.push_back(57);
                        vec.push_back(58);
                        if ((*turm)->unmoved()&&checkIfFree(vec)&&kingIsSafe(black,vec))
                        {
                            (*turm)->setPosition(58);
                            (*figure)->setPosition(57);
                            ret=true;
                        }
                    }
                }
                break;
            }

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
                        vector<int> vec;
                        vec.push_back(6);
                        vec.push_back(5);
                        vec.push_back(4);
//                        bool fooo=(*turm)->unmoved();
//                        bool foooo= checkIfFree(vec);
//                        bool fooooo= kingIsSafeRochade(black,vec);
                        if ((*turm)->unmoved()&&checkIfFree(vec)&&kingIsSafe(black,vec))
                        {
                            (*turm)->setPosition(4);
                            (*figure)->setPosition(5);
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
                        vector<int> vec;
                        vec.push_back(62);
                        vec.push_back(61);
                        vec.push_back(60);

                        if ((*turm)->unmoved()&&checkIfFree(vec)&&kingIsSafe(black,vec))
                        {
                            (*turm)->setPosition(60);
                            (*figure)->setPosition(61);
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

bool Board::kingIsSafe(const bool black, const vector<int>& fields)
{
    bool ret = true;
    auto &figurenGegner = (black?_white:_black);
    auto  canCaptureKing = std::find_if( figurenGegner.begin(), figurenGegner.end(), [&](std::unique_ptr<Piece> & piece)
    {
        bool retLambda = false;
        for (int field : fields)
        {
            const int fieldConst = field;
            if (piece->captureKing(fieldConst) == true)
            {
                if (CheckFreeWay((piece),fieldConst))
                {
                    retLambda = true;
                }
            }
        }
        return retLambda;
    });
    if(canCaptureKing != figurenGegner.end())
    {
        ret = false;
    }
    return ret;
}

void Board::pawnPromotion(std::vector<std::unique_ptr<Piece>>::iterator & figure,const bool black)
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
