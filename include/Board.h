#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"
#include <memory>
#include <vector>

using namespace std;
class Board
{
public:
    /** \brief Constructor
     *
     * \param unicode bool
     *
     */
    Board(bool unicode);
    /** \brief Destructor
     *
     * \return virtual
     *
     */
    virtual ~Board();
    /** \brief getter black list
     *
     * \return std::vector<std::unique_ptr<Piece>>  const&
     *
     */
    std::vector<std::unique_ptr<Piece>>  const & getBlack() const;
    /** \brief getter white list
     *
     * \return std::vector<std::unique_ptr<Piece>>  const&
     *
     */
    std::vector<std::unique_ptr<Piece>>  const &  getWhite() const;
    /** \brief Override << Operator
     *
     * \param s ostream&
     * \param rhs const Board&
     * \return friend    ostream&
     *
     */
    friend    ostream& operator<<(ostream& s, const Board& rhs ) ;
    /** \brief move function
     *
     * \param posStart int const&
     * \param posEnd int const&
     * \param black bool const&
     * \return bool
     *
     */
    bool move(const int  posStart, const int posEnd, const bool black);

    /** \brief setter unicode
     *
     * \param unicode bool
     * \return void
     *
     */
    void setUnicode(bool unicode);

    /** \brief init regular field
     *
     * \param =false bool unicode
     * \return void
     *
     */
    void init(bool unicode =false);
    /** \brief init Test field
     *
     * \param =false bool unicode
     * \return void
     *
     */
    void initTest(bool unicode =false);
    /** \brief Getter Winner
     *
     * \return int const&
     *
     */
    int getWinner() const;

protected:

private:

    /** \brief check if way to endpos for figure is free
     *
     * \param figure std::unique_ptr<Piece>&
     * \param posEnd int
     * \return bool
     *
     */
    bool CheckFreeWay(std::unique_ptr<Piece>& figure, const int posEnd);
    /** \brief check and do rochade
     *
     * \param figure std::vector<std::unique_ptr<Piece>>::iterator&
     * \param black bool
     * \param ret bool
     * \param posStart int
     * \param posEnd int
     * \return void
     *
     */
    void rochade(std::vector<std::unique_ptr<Piece>>::iterator & figure,const bool black, bool& ret, const int posStart, const int posEnd);
    /** \brief check and do enpassant pawns
     *
     * \param figure std::vector<std::unique_ptr<Piece>>::iterator&
     * \param black bool
     * \param ret bool
     * \param posStart int
     * \param posEnd int
     * \return void
     *
     */
    void enPassant(std::vector<std::unique_ptr<Piece>>::iterator & figure,const bool black, bool& ret, const int posStart, const int posEnd);
    /** \brief check and do Pawn promotion
     *
     * \param figure std::vector<std::unique_ptr<Piece>>::iterator&
     * \param black bool
     * \return void
     *
     */
    void pawnPromotion(std::vector<std::unique_ptr<Piece>>::iterator & figure,const bool black);
    /** \brief check if more moves are possible, remis
     *
     * \param black bool
     * \return bool
     *
     */
    bool checkIfMovesPossible(const bool black)  ;
    /** \brief Check if King is save on fields
     *
     * \param black bool
     * \param fields const vector<int>&
     * \return bool
     *
     */
    bool kingIsSafe(const bool black, const vector<int>& fields) ;
    /** \brief check if fields are free
     *
     * \param pos vector<int> const&
     * \return bool
     *
     */
    bool checkIfFree(vector<int> const & pos) ;
    /** \brief Check if own Figure on endfield
     *
     * \param posEnd int const&
     * \param black bool const&
     * \return bool
     *
     */
    bool checkIfOwnPiece( int posEnd,const bool black) ;

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
