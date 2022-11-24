#include "board.hpp"

namespace CEB
{
    // Board

    template <typename T>
    Board<T>::Board() : player(FirstP), turnSpent(0) { InitBoard(); }
    template <typename T>
    Board<T>::Board(Player _player, int _turnSpent) : player(_player), turnSpent(_turnSpent) { InitBoard(); }

    template <typename T>
    CEBError Board<T>::Move(T move)
    {
        trace[traceLength] = move;
        return (this->_Move(move));
    }

    template <typename T>
    CEBError Board<T>::MoveForce(T move)
    {
        trace[traceLength] = move;
        return (this->_MoveForce(move));
    }

    template <typename T>
    CEBError Board<T>::MoveBack()
    {
        if (traceLength)
            return MoveBackErr("There is no move before this board.");

        CEBError err;
        int i;

        --traceLength;
        for (i = 0; i < traceLength; i++)
        {
            err = this->_Move(trace[i]);
            // if error occurs here, there may be fatal bugs.
            if (err != NoErr)
                return err;
        }

        return NoErr;
    }

    // 0 is a special value which means no hash code.
    template <typename T>
    int Board<T>::HashCode() const { return 0; }
}