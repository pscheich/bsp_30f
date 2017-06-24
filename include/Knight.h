#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;
class Knight : public Piece
{
public:
    /** \brief
     *
     *
     */
    Knight();
    /** \brief
     *
     * \param pos int
     * \param black bool
     *
     */
    Knight(int pos, bool black);
    /** \brief
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    Knight(int pos, bool black, bool unicode);
    /** \brief
     *
     * \param _rhs
     * \return Knight(const Knight& _rhs):
     *
     */
    Knight(const Knight& _rhs) : Piece(_rhs) {}
    /** \brief
     *
     * \return std::unique_ptr<Piece>
     *
     */
    std::unique_ptr<Piece> clone() const
    {
        return std::unique_ptr<Piece>(new Knight(*this));
    }
    /** \brief
     *
     * \return virtual
     *
     */
    virtual ~Knight();
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

#endif // KNIGHT_H
