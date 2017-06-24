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
    King(const int pos, const bool black);
    /** \brief
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    King(const int pos, const bool black, const bool unicode);
    /** \brief
     *
     * \param _rhs
     * \return King(const King& _rhs):
     *
     */
    King(const King& _rhs);
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
    virtual ~King();
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
    vector<int> getStepsBetween(const int) const override;
protected:

private:
};

#endif // KING_H
