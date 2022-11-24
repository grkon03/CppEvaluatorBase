#include "../../src/basic/board.hpp"

namespace CEB
{
    namespace testcase
    {
        enum Square
        {
            S11,
            S12,
            S13,
            S21,
            S22,
            S23,
            S31,
            S32,
            S33,
        };

        typedef uint16_t Bitboard;

        class TicTacToe : public Board<Square>
        {
        private:
            Bitboard Circle; // first player
            Bitboard Cross;  // second player

        public:
            // Constructor
            TicTacToe();

            // pure virtuals

            virtual void InitBoard() override;
            virtual CEBError _Move(Square) override;
            virtual CEBError _MoveForce(Square) override;
            virtual CEBError LegalMoves(Square[9], int *) const override;
            virtual Player JudgeWinner() const override;

            // additionals

            Bitboard getCircleBit();
            Bitboard getCrossBit();
        };
    }

}