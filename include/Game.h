#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include <string>
#include <iostream>

using namespace std;
class Game
{
public:
    /** \brief
     *
     *
     */
    Game();
    /** \brief
     *
     * \return virtual
     *
     */
    virtual ~Game();
    /** \brief
     *
     * \param s ostream&
     * \param rhs const Game&
     * \return friend    ostream&
     *
     */
    friend    ostream& operator<<(ostream& s, const Game& rhs ) ;
    /** \brief
     *
     * \return void
     *
     */
    void play();
protected:

private:
    /** \brief
     *
     * \return void
     *
     */
    void _init();
    /** \brief
     *
     * \return void
     *
     */
    void clearOutput();

    string _player1;
    string _player2;
    Board _board;
    bool _player1turn;



};

#endif // GAME_H
