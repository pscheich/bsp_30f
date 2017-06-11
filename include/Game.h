#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include <string>
#include <iostream>

using namespace std;
class Game
{
public:
    Game();
    virtual ~Game();
    friend    ostream& operator<<(ostream& s, const Game& rhs ) ;
    void play();
protected:

private:
    string _player1;
    string _player2;
    Board _board;
    bool _player1turn;
    void _init();

};

#endif // GAME_H
