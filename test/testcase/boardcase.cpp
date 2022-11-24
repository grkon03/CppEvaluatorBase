#include "boardcase.hpp"

namespace CEB
{
    namespace testcase
    {
        TicTacToe::TicTacToe() : Board(){};

        void TicTacToe::InitBoard()
        {
            Circle = 0;
            Cross = 0;
        }

        CEBError TicTacToe::_Move(Square s)
        {
            Bitboard move = 1 << (int)s;

            if (((Circle | Cross) & move) != 0)
                return cebet::MoveErr("This square already has a piece");

            switch (player)
            {
            case FirstP:
                Circle |= move;
                break;
            case SecondP:
                Cross |= move;
                break;
            default:
                return cebet::MoveErr("Invalid player");
            }

            ++player;

            return cebet::NoErr;
        }

        CEBError TicTacToe::_MoveForce(Square s)
        {
            _Move(s);
            return cebet::NoErr;
        }

        CEBError TicTacToe::LegalMoves(Square s[9], int *num) const
        {
            Bitboard exists = Circle | Cross;
            int i = 0;
            int bs = 1;

            *num = 0;

            for (i = 0; i < 9; i++)
            {
                if ((bs & exists) == 0)
                    s[(*num)++] = (Square)i;
                bs = bs << 1;
            }

            return cebet::NoErr;
        }

        Player TicTacToe::JudgeWinner() const
        {
            Bitboard patterns[] = {
                0b111000000,
                0b000111000,
                0b000000111,
                0b100100100,
                0b010010010,
                0b001001001,
                0b100010001,
                0b001010100,
            };

            for (Bitboard pt : patterns)
            {
                if ((pt & Circle) == pt)
                    return FirstP;
                if ((pt & Cross) == pt)
                    return SecondP;
            }

            return NoPlayer;
        }

        Bitboard TicTacToe::getCircleBit() { return Circle; }
        Bitboard TicTacToe::getCrossBit() { return Cross; }

    }
}