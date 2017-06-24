#ifndef ROCK_H
#define ROCK_H
#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;
class Rock : public Piece
{
public:
    /** \brief
     *
     *
     */
    Rock();
    /** \brief
     *
     * \param pos int
     * \param black bool
     *
     */
    Rock(const int pos, const bool black);
    /** \brief
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    Rock(const int pos, const bool black, const bool unicode);
    /** \brief
     *
     * \param _rhs
     * \return Rock(const Rock& _rhs):
     *
     */
    Rock(const Rock& _rhs);
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
    virtual ~Rock();
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
    bool captureKing(const int newPos) const override;
    /** \brief
     *
     * \param newPos int
     * \return vector<int>
     *
     */
    vector<int> getStepsBetween(const int newPos) const override;
protected:

private:
};

#endif // ROCK_H
