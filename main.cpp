#include <iostream>
#include "Board.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rock.h"
#include "Pawn.h"
#include "Piece.h"
#include "Game.h"

using namespace std;

int main()
{
    Game game;
    game.play();

//    Board game;
//    game.print();
//    Board gameUnicode(true);
//    gameUnicode.print();
//   game.move(7,55,false);
//   game.move(3,15,false);
//    game.print();
//std::wcout << "♔";

    return 0;
}
