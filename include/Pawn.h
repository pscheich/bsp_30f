#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;

class Pawn : public Piece
{
public:

    /** \brief Constructor
     *
     *
     */
    Pawn();
    /** \brief Constructor
     *
     * \param pos int
     * \param black bool
     *
     */
    Pawn(const int pos, const bool black);
    /** \brief Constructor
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    Pawn(const int pos, const bool black, const bool unicode);
    /** \brief Constructor Copy
     *
     * \param _rhs const Pawn&
     *
     */
    Pawn(const Pawn& _rhs);
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
    virtual ~Pawn();
    /** \brief check if move enabled
     *
     * \param newPos int
     * \return bool
     *
     */
    bool moveEnabled(const int newPos) const override;
    /** \brief check if move enabled for capturing, the same as moveEnabled, exception is pawn
     *
     * \param newPos int
     * \return bool
     *
     */
    bool moveEnabled4Capture(const int newPos) const override;
    /** \brief check if piece can capture an other field
     *
     * \param newPos int
     * \return bool
     *
     */
    bool captureKing(const int newPos) const override;
    /** \brief get all stepps beween pos now and end pos, move has to be correct
     *
     * \param newPos int
     * \return vector<int>
     *
     */
    vector<int> getStepsBetween(const int newPos) const override;
    /** \brief check Promotion
     *
     * \return bool
     *
     */
    bool promotionPossible() const override;

protected:

private:

};

#endif // PAWN_H
