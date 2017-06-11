#include "Empty.h"
#include <cmath>
using namespace std;
Empty::Empty()
{
    //ctor
}
Empty::Empty(int pos):Piece(pos,' '){
}
Empty::~Empty()
{
    //dtor
}
bool Empty::moveEnabled(int newPos)
{
    newPos/8=0;newPos%8=0;
return false;
}

