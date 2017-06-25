/**
 * Game Header
 * @author Patrick Scheich
 */

#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include <string>
#include <iostream>

using namespace std;
class Game
{
public:
    /** \brief Constructor
     *
     *
     */
    Game();
    /** \brief Destructor
     *
     * \return virtual
     *
     */
    virtual ~Game();
    /** \brief Override << Operator
     *
     * \param s ostream&
     * \param rhs const Game&
     * \return friend    ostream&
     *
     */
    friend    ostream& operator<<(ostream& s, const Game& rhs ) ;
    /** \brief Start the Game
     *
     * \return void
     *
     */
    void play();
protected:

private:
    /** \brief Init Game
     *
     * \return void
     *
     */
    void _init();
    /** \brief Clear Output in Terminal
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
