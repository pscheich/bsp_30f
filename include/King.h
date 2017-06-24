#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;
class King : public  Piece
{
public:
    /** \brief
     *
     *
     */
    King();

    /** \brief
     *
     * \param pos int
     * \param black bool
     *
     */
    King(int pos, bool black);
    /** \brief
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    King(int pos, bool black, bool unicode);
    /** \brief
     *
     * \param _rhs
     * \return King(const King& _rhs):
     *
     */
    King(const King& _rhs) : Piece(_rhs) {}
    /** \brief
     *
     * \return std::unique_ptr<Piece>
     *
     */
    std::unique_ptr<Piece> clone() const
    {
        return std::unique_ptr<Piece>(new King(*this));
    }
    /** \brief
     *
     * \return virtual
     *
     */
    virtual ~King();
    /** \brief
     *
     * \param newPos int
     * \return bool
     *
     */
    bool moveEnabled(int newPos);
    /** \brief
     *
     * \param newPos int
     * \return bool
     *
     */
    bool captureKing(int newPos);
    /** \brief
     *
     * \param newPos int
     * \return vector<int>
     *
     */
    vector<int> getStepsBetween(int newPos) ;
protected:

private:
};

#endif // KING_H
