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

        virtual void InitBoard() = 0;
        virtual CEBError _Move(MoveRep) = 0;
        virtual CEBError _MoveForce(MoveRep) = 0;
        virtual CEBError LegalMoves(Board *, int *) const = 0;

        // not pures

        virtual CEBError MoveBack();
        virtual int HashCode() const;

        // get variables

        Player getPlayer() const;
        int getTurnSpent() const;
    };
}