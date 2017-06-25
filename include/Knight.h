/**
 * Knight Header
 * @author Patrick Scheich
 */

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;
class Knight : public Piece
{
public:
    /** \brief Constructor
     *
     *
     */
    Knight();
    /** \brief Constructor
     *
     * \param pos int
     * \param black bool
     *
     */
    Knight(const int pos, const bool black);
    /** \brief Constructor
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    Knight(const int pos, const bool black, const bool unicode);
    /** \brief Constructor Copy
     *
     * \param _rhs
     * \return Knight(const Knight& _rhs):
     *
     */
    Knight(const Knight& _rhs);
    /** \brief clone function
     *
     * \return std::unique_ptr<Piece>
     *
     */
    std::unique_ptr<Piece> clone() const override;
    /** \brief Destructor
     *
     * \return virtual
     *
     */
    virtual ~Knight();
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
    vector<int> getStepsBetween(const int ) const override;
protected:

private:
};

#endif // KNIGHT_H
