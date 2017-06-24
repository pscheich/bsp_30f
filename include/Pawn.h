#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;

class Pawn : public Piece
{
public:

    /** \brief
     *
     *
     */
    Pawn();
    /** \brief
     *
     * \param pos int
     * \param black bool
     *
     */
    Pawn(const int pos, const bool black);
    /** \brief
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    Pawn(const int pos, const bool black, const bool unicode);
    /** \brief
     *
     * \param _rhs const Pawn&
     *
     */
    Pawn(const Pawn& _rhs);
    /** \brief
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
    virtual ~Pawn();
    /** \brief
     *
     * \param newPos int
     * \return bool
     *
     */
    bool moveEnabled(const int newPos) const override;
    /** \brief
     *
     * \param newPos int
     * \return bool
     *
     */
    bool moveEnabled4Capture(const int newPos) const override;
    /** \brief
     *
     * \param newPos int
     * \return bool
     *
     */
    bool captureKing(const int newPos) const override;
    /** \brief
     *
     * \param newPos int
     * \return vector<int>
     *
     */
    vector<int> getStepsBetween(const int newPos) const override;
    /** \brief
     *
     * \return bool
     *
     */
    bool promotionPossible() const override;

protected:

private:

};

#endif // PAWN_H
