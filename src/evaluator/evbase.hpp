/*
evbase.hpp

Defining a base class of evaluator.
*/

#include "../basic/board.hpp"

namespace CEB
{
    namespace evaluator
    {
        constexpr int BESTMOVES_LENGTH = 64;

        template <typename MoveRep>
        class evaluatorBase
        {
        private:
            // infomation of the latest analysis

            Board<MoveRep> *nowAnalyzed;
            double evaluation;
            MoveRep bestMoves[BESTMOVES_LENGTH];

        public:
            // constructor

            evaluatorBase();

            // evaluator

            virtual double evaluate(Board<MoveRep> *) = 0;
        };

        template <typename T>
        evaluatorBase<T>::evaluatorBase() : Board(), evaluation(0);
    }
}