#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include <vector>
#include <memory>
using namespace std;

class Queen : public Piece
{
public:
    /** \brief Constructor
     *
     *
     */
    Queen();
    /** \brief Constructor
     *
     * \param pos int
     * \param black bool
     *
     */
    Queen(const int pos, const bool black);
    /** \brief Constructor
     *
     * \param pos int
     * \param black bool
     * \param unicode bool
     *
     */
    Queen(const int pos, const bool black, const bool unicode);
    /** \brief Constructor Copy
     *
     * \param _rhs
     * \return Queen(const Queen& _rhs):
     *
     */
    Queen(const Queen& _rhs);
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
    virtual ~Queen();
    /** \brief check if move enabled
     *
     * \param newPos int
     * \return bool
     *
     */
    bool moveEnabled(const int newPos) const override;
    /** \brief check if piece can capture an other field
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

#endif // QUEEN_H
