/*
board.hpp

Defining abstract class of game board
*/
#pragma once

#include "error.hpp"
#include "player.hpp"

namespace CEB
{
    // MoveRep is a type to store ONE move.
    template <typename MoveRep>
    class Board
    {
    protected:
        // variables

        Player player;
        int turnSpent;

        MoveRep trace[200];
        int traceLength;

    public:
        // constructors

        Board();
        Board(Player, int);

        // functions

        CEBError Move(MoveRep);
        CEBError MoveForce(MoveRep);

        // virtuals

        // pures
        virtual CEBError _Move(MoveRep) = 0;
        virtual CEBError _MoveForce(MoveRep) = 0;
        virtual CEBError LegalMoves(MoveRep *, int *) const = 0;
        virtual Player JudgeWinner() const = 0;

        // not pures

        virtual void InitBoard();
        virtual CEBError MoveBack();
        virtual int HashCode() const;

        // get variables

        Player getPlayer() const;
        int getTurnSpent() const;
    };

    // Board

    template <typename T>
    Board<T>::Board() : player(FirstP), turnSpent(0) { InitBoard(); }
    template <typename T>
    Board<T>::Board(Player _player, int _turnSpent) : player(_player), turnSpent(_turnSpent) { InitBoard(); }

    template <typename T>
    CEBError Board<T>::Move(T move)
    {
        trace[traceLength++] = move;
        ++turnSpent;
        return (this->_Move(move));
    }

    template <typename T>
    CEBError Board<T>::MoveForce(T move)
    {
        trace[traceLength++] = move;
        ++turnSpent;
        return (this->_MoveForce(move));
    }

    template <typename T>
    CEBError Board<T>::MoveBack()
    {
        if (traceLength)
            return cebet::MoveBackErr("There is no move before this board.");

        CEBError err;
        int i;

        InitBoard();

        --traceLength;
        for (i = 0; i < traceLength; i++)
        {
            err = this->_Move(trace[i]);
            // if error occurs here, there may be fatal bugs.
            if (err != cebet::NoErr)
                return err;
        }

        return cebet::NoErr;
    }

    template <typename T>
    void Board<T>::InitBoard(){};

    // 0 is a special value which means no hash code.
    template <typename T>
    int Board<T>::HashCode() const { return 0; }

    template <typename T>
    Player Board<T>::getPlayer() const { return player; }
    template <typename T>
    int Board<T>::getTurnSpent() const { return turnSpent; }
}