#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;

class Queen : public Piece
{
public:
    /** \brief
     *
     *
     */
    Queen();
    /** \brief
     *
     * \param pos int
     * \param black bool
     *
     */
    Queen(int pos, bool black);
    /** \brief
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    Queen(int pos, bool black, bool unicode);
    /** \brief
     *
     * \param _rhs
     * \return Queen(const Queen& _rhs):
     *
     */
    Queen(const Queen& _rhs) : Piece(_rhs) {}
    /** \brief
     *
     * \return std::unique_ptr<Piece>
     *
     */
    std::unique_ptr<Piece> clone() const
    {
        return std::unique_ptr<Piece>(new Queen(*this));
    }
    /** \brief
     *
     * \return virtual
     *
     */
    virtual ~Queen();
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

#endif // QUEEN_H
