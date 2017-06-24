#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <iostream>
#include <array>
#include <memory>
#include <string>
using namespace std;

class Piece
{
public:
    /** \brief Constructor
     *
     *
     */
    Piece();
    /** \brief Constructor
     *
     * \param pos int
     * \param sym string
     * \param black bool
     *
     */
    Piece(const int pos, const string sym,const bool black);
    /** \brief Constructor
     *
     * \param x int
     * \param y int
     * \param sym string
     * \param black bool
     *
     */
    Piece(const int x,const int y,const  string sym,const bool black);
    /** \brief Constructor
     *
     * \param pos int
     *
     */
    Piece(const int pos);
    /** \brief clone function
     *
     * \return virtual std::unique_ptr<Piece>
     *
     */
    virtual std::unique_ptr<Piece> clone() const = 0;

    /** \brief Destructor
     *
     * \return virtual
     *
     */
    virtual ~Piece();
    /** \brief check if move enabled
     *
     * \param newPos int
     * \return virtual  bool
     *
     */
    virtual  bool moveEnabled(const int newPos)const =0 ;
    /** \brief check if move enabled for capturing, the same as moveEnabled, exception is pawn
     *
     * \param newPos int
     * \return virtual  bool
     *
     */
    virtual  bool moveEnabled4Capture(const int newPos)  const;
    /** \brief check if piece can capture an other field
     *
     * \param newPos int
     * \return virtual  bool
     *
     */
    virtual  bool captureKing(const int newPos) const =0;
    /** \brief check if promotion is possible = false, just pawns with real check
     *
     * \return virtual  bool
     *
     */
    virtual  bool promotionPossible() const ;
    /** \brief Getter Position
     *
     * \return int
     *
     */
    int getPosition() const;
    /** \brief Getter Black
     *
     * \return bool
     *
     */
    bool  getBlack() const;
    /** \brief Setter Position
     *
     * \param newPos int
     * \return void
     *
     */
    void setPosition(const int newPos);
    /** \brief change position without manupulate _moved
    *
    * \param newPos int
    * \return void
    *
    */
    void setPosition4Test(const int newPos);
    /** \brief check if unmoved
     *
     * \return bool
     *
     */
    bool unmoved() const;

    /** \brief Print piece
     *
     * \param std::array<string
     * \param board 64>&
     * \return void
     *
     */
    void printOnBoard(std::array<string, 64> &board) const;
    /** \brief getter symbol
     *
     * \return string const
     *
     */
    string const getSymbol() const;
    /** \brief get all stepps beween pos now and end pos, move has to be correct
     *
     * \param newPos int
     * \return virtual vector<int>
     *
     */
    virtual vector<int> getStepsBetween(const int newPos) const =0 ;


    /** \brief Override << Operator
     *
     * \param s ostream&
     * \param rhs const Piece&
     * \return friend ostream&
     *
     */
    friend ostream& operator<<(ostream& s, const Piece& rhs );
protected:
    /** \brief check if newPos<64
     *
     * \param newPos int
     * \return bool
     *
     */
    bool checkInField(const int newPos) const;
    int _position;
    string _symbol;
    bool _black;
    bool _unMoved;
private:



};

#endif // PIECE_H
