#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;

class Bishop : public Piece
{
public:
    /** \brief
     *
     *
     */
    Bishop();
    /** \brief
     *
     * \param pos int
     * \param black bool
     *
     */
    Bishop(int pos, bool black);
    /** \brief
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    Bishop(int pos, bool black, bool unicode);
    /** \brief
     *
     * \param _rhs
     * \return Bishop(const Bishop& _rhs):
     *
     */
    Bishop(const Bishop& _rhs) : Piece(_rhs) {};
    /** \brief
     *
     * \return std::unique_ptr<Piece>
     *
     */
    std::unique_ptr<Piece> clone() const
    {
        return std::unique_ptr<Piece>(new Bishop(*this));
    }
    /** \brief
     *
     * \return virtual
     *
     */
    virtual ~Bishop();
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

#endif // BISHOP_H
