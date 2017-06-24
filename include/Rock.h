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
    Rock(int pos, bool black);
    /** \brief
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    Rock(int pos, bool black, bool unicode);
    /** \brief
     *
     * \param _rhs
     * \return Rock(const Rock& _rhs):
     *
     */
    Rock(const Rock& _rhs) : Piece(_rhs) {}
    /** \brief
     *
     * \return std::unique_ptr<Piece>
     *
     */
    std::unique_ptr<Piece> clone() const
    {
        return std::unique_ptr<Piece>(new Rock(*this));
    }
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

#endif // ROCK_H
