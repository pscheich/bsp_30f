#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"
#include <memory>
#include <vector>

using namespace std;
class Board
{
public:
    /** \brief
     *
     * \param unicode bool
     *
     */
    Board(bool unicode);
    /** \brief
     *
     * \return virtual
     *
     */
    virtual ~Board();
    /** \brief
     *
     * \return std::vector<std::unique_ptr<Piece>>  const&
     *
     */
    std::vector<std::unique_ptr<Piece>>  const & getBlack() const;
    /** \brief
     *
     * \return std::vector<std::unique_ptr<Piece>>  const&
     *
     */
    std::vector<std::unique_ptr<Piece>>  const &  getWhite() const;
    /** \brief
     *
     * \param s ostream&
     * \param rhs const Board&
     * \return friend    ostream&
     *
     */
    friend    ostream& operator<<(ostream& s, const Board& rhs ) ;
    /** \brief
     *
     * \param posStart int const&
     * \param posEnd int const&
     * \param black bool const&
     * \return bool
     *
     */
    bool move(int const &  posStart, int const & posEnd, bool const&  black);

    /** \brief
     *
     * \param unicode bool
     * \return void
     *
     */
    void setUnicode(bool unicode);

    /** \brief
     *
     * \param =false bool unicode
     * \return void
     *
     */
    void init(bool unicode =false);
    /** \brief
     *
     * \param =false bool unicode
     * \return void
     *
     */
    void initTest(bool unicode =false);
    /** \brief
     *
     * \return int const&
     *
     */
    int const & getWinner() const;

protected:

private:

    /** \brief
     *
     * \param figure std::unique_ptr<Piece>&
     * \param posEnd const int&
     * \return bool
     *
     */
    bool CheckFreeWay(std::unique_ptr<Piece>& figure, const int& posEnd);
    /** \brief
     *
     * \param figure std::vector<std::unique_ptr<Piece>>::iterator&
     * \param black const bool&
     * \param ret bool&
     * \param posStart const int&
     * \param posEnd const int&
     * \return void
     *
     */
    void rochade(std::vector<std::unique_ptr<Piece>>::iterator & figure,const bool& black, bool & ret, const int & posStart, const int & posEnd);
    /** \brief
     *
     * \param figure std::vector<std::unique_ptr<Piece>>::iterator&
     * \param black const bool&
     * \param ret bool&
     * \param posStart const int&
     * \param posEnd const int&
     * \return void
     *
     */
    void enPassant(std::vector<std::unique_ptr<Piece>>::iterator & figure,const bool& black, bool & ret, const int & posStart, const int & posEnd);
    /** \brief
     *
     * \param figure std::vector<std::unique_ptr<Piece>>::iterator&
     * \param black const bool&
     * \return void
     *
     */
    void pawnPromotion(std::vector<std::unique_ptr<Piece>>::iterator & figure,const bool & black);
    /** \brief
     *
     * \param black const bool&
     * \return bool
     *
     */
    bool checkIfMovesPossible(const bool& black) ;
    /** \brief
     *
     * \param black const bool&
     * \param fields const vector<int>&
     * \return bool
     *
     */
    /** \brief
     *
     * \param black const bool&
     * \param fields const vector<int>&
     * \return bool
     *
     */
    bool kingIsSafe(const bool & black, const vector<int>& fields);
    /** \brief
     *
     * \param pos vector<int> const&
     * \return bool
     *
     */
    bool checkIfFree(vector<int> const & pos);
    /** \brief
     *
     * \param posEnd int const&
     * \param black bool const&
     * \return bool
     *
     */
    bool checkIfOwnPiece( int const & posEnd,bool const & black);

    std::vector<std::unique_ptr<Piece>> _black;
    std::vector<std::unique_ptr<Piece>> _white;
    bool _unicode;
    int _winner; //0 , 1schwarz,2weis,3remis
    int _remiscounter50;
    int _lastwasdouble;

    vector<vector<std::unique_ptr<Piece>>> _positionsBlack;
    vector<vector<std::unique_ptr<Piece>>> _positionsWhite;
};

#endif // BOARD_H
