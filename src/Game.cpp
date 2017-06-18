#include "Game.h"
#include <string>
#include <iostream>

using namespace std;


Game::Game():_player1("name1"),_player2("name2"),_board(false),_player1turn(true)
{
    //ctor
    _init();
}

Game::~Game()
{
    //dtor
}
void Game::_init()
{

    string unicode;
    cout << "Using Unicode Characters [Y/n]"<<endl;
    cin >> unicode;
    bool unicodebool=false;
    if(unicode=="Y" || unicode=="y" ) unicodebool=true;
    _board.initTest(unicodebool);
    string np1;
    cout << "Choose a name for Player1 (white). Choose wisely, as it can't be changed later."<<endl;
    cin >> np1;
    string np2;
    cout << "Choose a name for Player2 (black). Choose wisely, as it can't be changed later."<<endl;
    cin >> np2;

    _player1=np1;
    _player2=np2;

}

void Game::play()
{

    while(_board.getWinner()==0)
    {
        cout << _board;
        string player = ((_player1turn)?_player1:_player2 )+ ((_player1turn)?"(white)":"(black)");

        cout << player <<", it's your turn. Enter the Start X Position" << endl;
        int startPos;
        int endPos;
        int inputStartX;
        while(!((cin >> inputStartX)&&(inputStartX<9&&inputStartX>0)))
        {

            cin.clear();
            cin.ignore( 1000, '\n' );
            cout << "Bad value! Input an integer between 1 and 8. \n";
        }
        // es wird mit 0-7 gerechnet
        cout << "Enter the Start Y Position" << endl;
        int inputStartY;
        while(!((cin >> inputStartY)&&(inputStartY<9&&inputStartY>0)))
        {

            cin.clear();
            cin.ignore( 1000, '\n' );
            cout << "Bad value! Input an integer between 1 and 8. \n";
        }
        // es wird mit 0-7 gerechnet

        cout << "Enter the End X Position" << endl;
        int inputEndX;
        while(!((cin >> inputEndX)&&(inputEndX<9&&inputEndX>0)))
        {

            cin.clear();
            cin.ignore( 1000, '\n' );
            cout << "Bad value! Input an integer between 1 and 8. \n";
        }
        // es wird mit 0-7 gerechnet
        cout << "Enter the End Y Position" << endl;
        int inputEndY;
        while(!((cin >> inputEndY)&&(inputEndY<9&&inputEndY>0)))
        {

            cin.clear();
            cin.ignore( 1000, '\n' );
            cout << "Bad value! Input an integer between 1 and 8. \n";
        }
        inputStartX--;
        inputStartY--;
        inputEndX--;
        inputEndY--;
        startPos=inputStartX+inputStartY*8 ;
        endPos=inputEndX+inputEndY*8 ;

        cout << startPos << " +++ " << endPos << endl;
        clearOutput();
        if(_board.move(startPos,endPos,!_player1turn))
        {
            _player1turn=!_player1turn;

        }
        else
        {
            cout << "Invalid movement. Please try it again." << endl;

        }
    }

}
ostream& operator<<(ostream& s, const Game& rhs )
{
    s<<rhs._board;
    return s;
}
void Game::clearOutput()
{
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#else
    system("clear");
#endif
}
