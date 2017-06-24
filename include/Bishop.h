#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;

class Bishop : public Piece
{
public:
    /** \brief Constructor
     *
     *
     */
    Bishop();
    /** \brief Constructor
     *
     * \param pos int
     * \param black bool
     *
     */
    Bishop(const int pos, const bool black);
    /** \brief Constructor
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    Bishop(const int pos, const bool black, const bool unicode);
    /** \brief Constructor Copy
     *
     * \param _rhs
     * \return Bishop(const Bishop& _rhs):
     *
     */
    Bishop(const Bishop& _rhs);
    /** \brief clone function
     *
     * \return std::unique_ptr<Piece>
     *
     */
    std::unique_ptr<Piece> clone() const override;
    /** \brief
     *
     * \return virtual
     *
     */
    virtual ~Bishop();
    /** \brief check if move enabled
     *
     * \param newPos int
     * \return bool
     *
     */
    bool moveEnabled(const int newPos)const override;
    /** \brief check if piece can capture an other field
     *
     * \param newPos int
     * \return bool
     *
     */
    bool captureKing(const int newPos)const override;
    /** \brief get all stepps beween pos now and end pos, move has to be correct
     *
     * \param newPos int
     * \return vector<int>
     *
     */
    vector<int> getStepsBetween(const int newPos) const override;
protected:

private:
};

#endif // BISHOP_H
