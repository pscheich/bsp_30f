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
    Knight(const int pos, const bool black);
    /** \brief
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    Knight(const int pos, const bool black, const bool unicode);
    /** \brief
     *
     * \param _rhs
     * \return Knight(const Knight& _rhs):
     *
     */
    Knight(const Knight& _rhs);
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
    virtual ~Knight();
    /** \brief
     *
     * \param newPos int
     * \return bool
     *
     */
    bool moveEnabled(const int newPos)const override;
    /** \brief
     *
     * \param newPos int
     * \return bool
     *
     */
    bool captureKing(const int newPos)const override;
    /** \brief
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
