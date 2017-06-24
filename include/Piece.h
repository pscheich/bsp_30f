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
    /** \brief
     *
     *
     */
    Piece();
    /** \brief
     *
     * \param pos int
     * \param sym string
     * \param black bool
     *
     */
    Piece(const int pos, const string sym,const bool black);
    /** \brief
     *
     * \param x int
     * \param y int
     * \param sym string
     * \param black bool
     *
     */
    Piece(const int x,const int y,const  string sym,const bool black);
    /** \brief
     *
     * \param pos int
     *
     */
    Piece(const int pos);
    /** \brief
     *
     * \return virtual std::unique_ptr<Piece>
     *
     */
    virtual std::unique_ptr<Piece> clone() const = 0;

    /** \brief
     *
     * \return virtual
     *
     */
    virtual ~Piece();
    /** \brief
     *
     * \param newPos int
     * \return virtual  bool
     *
     */
    virtual  bool moveEnabled(const int newPos)const =0 ;
    /** \brief
     *
     * \param newPos int
     * \return virtual  bool
     *
     */
    virtual  bool moveEnabled4Capture(const int newPos)  const;
    /** \brief
     *
     * \param newPos int
     * \return virtual  bool
     *
     */
    virtual  bool captureKing(const int newPos) const =0;
    /** \brief
     *
     * \return virtual  bool
     *
     */
    virtual  bool promotionPossible() const ;
    /** \brief
     *
     * \return int
     *
     */
    int getPosition() const;
    /** \brief
     *
     * \return bool
     *
     */
    bool  getBlack() const;
    /** \brief
     *
     * \param newPos int
     * \return void
     *
     */
    void setPosition(const int newPos);
    /** \brief
    *
    * \param newPos int
    * \return void
    *
    */
    void setPosition4Test(const int newPos);
    /** \brief
     *
     * \return bool
     *
     */
    bool unmoved() const;

    /** \brief
     *
     * \param std::array<string
     * \param board 64>&
     * \return void
     *
     */
    void printOnBoard(std::array<string, 64> &board) const;
    /** \brief
     *
     * \return string const
     *
     */
    string const getSymbol() const;
    /** \brief
     *
     * \param newPos int
     * \return virtual vector<int>
     *
     */
    virtual vector<int> getStepsBetween(const int newPos) const =0 ;


    /** \brief
     *
     * \param s ostream&
     * \param rhs const Piece&
     * \return friend ostream&
     *
     */
    friend ostream& operator<<(ostream& s, const Piece& rhs );
protected:
    /** \brief
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
