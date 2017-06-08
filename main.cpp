#include <iostream>
#include "Board.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rock.h"
#include "Pawn.h"
#include "Piece.h"

using namespace std;

int main()
{
    Board game;
    vector<Piece> blacks(16);
    King k;
    vector<int> pos(3,3);
    k.setPosition(pos);

    blacks.at(0)=k;
    game.setBlack(blacks);
    cout << game << endl;
    return 0;
}
