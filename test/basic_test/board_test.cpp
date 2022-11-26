#include <gtest/gtest.h>
#include "../../src/basic/board.hpp"
#include "../testcase/boardcase.hpp"
#include "../testutil/testutil.hpp"

using namespace CEB;
using namespace CEB::testcase;
using namespace CEB::testutil;

TicTacToe game;

// verifing correctness of definition of TicTacToe class

TEST(TicTacToeTest, InitializingTest)
{

    // definition verification
    EXPECT_EQ(game.getCircleBit(), 0b000000000);
    EXPECT_EQ(game.getCrossBit(), 0b000000000);
    EXPECT_EQ(game.getPlayer(), FirstP);
    EXPECT_EQ(game.getTurnSpent(), 0);
}

// board test

TEST(BoardTestCaseTTT, MoveTest1)
{
    EXPECT_EQ(game.Move(S22), cebet::NoErr);
    EXPECT_EQ(game.getCircleBit(), 0b000010000);
    EXPECT_EQ(game.getCrossBit(), 0b000000000);
    EXPECT_EQ(game.getPlayer(), SecondP);
    EXPECT_EQ(game.getTurnSpent(), 1);

    EXPECT_EQ(game.Move(S33), cebet::NoErr);
    EXPECT_EQ(game.getCircleBit(), 0b000010000);
    EXPECT_EQ(game.getCrossBit(), 0b100000000);
    EXPECT_EQ(game.getPlayer(), FirstP);
    EXPECT_EQ(game.getTurnSpent(), 2);

    EXPECT_EQ(game.Move(S13), cebet::NoErr);
    EXPECT_EQ(game.getCircleBit(), 0b000010100);
    EXPECT_EQ(game.getCrossBit(), 0b100000000);
    EXPECT_EQ(game.getPlayer(), SecondP);
    EXPECT_EQ(game.getTurnSpent(), 3);
}

TEST(BoardTestCaseTTT, MoveBackTest)
{
    EXPECT_EQ(game.MoveBack(), cebet::NoErr);
    EXPECT_EQ(game.getCircleBit(), 0b000010000);
    EXPECT_EQ(game.getCrossBit(), 0b100000000);
    EXPECT_EQ(game.getPlayer(), FirstP);
    EXPECT_EQ(game.getTurnSpent(), 2);

    // re-take a move
    EXPECT_EQ(game.Move(S13), cebet::NoErr);
    EXPECT_EQ(game.getCircleBit(), 0b000010100);
    EXPECT_EQ(game.getCrossBit(), 0b100000000);
    EXPECT_EQ(game.getPlayer(), SecondP);
    EXPECT_EQ(game.getTurnSpent(), 3);
}

TEST(BoardTestCaseTTT, IllegalMoveTest)
{
    EXPECT_EQ(game.Move(S13), cebet::MoveErr);
}

TEST(BoardTestCaseTTT, LegalMovesTest)
{
    Square s[9];
    int len;
    game.LegalMoves(s, &len);

    Square cor[6] = {S11, S12, S21, S23, S31, S32};

    ASSERT_EQ(len, 6);

    EXPECT_TRUE(SameAsSet(s, cor, 6));
}

TEST(BoardTestCaseTTT, JudgeWinnerTest1)
{
    EXPECT_EQ(game.JudgeWinner(), NoPlayer);
}

TEST(BoardTestCaseTTT, JudgeWinnerTest2)
{
    game.Move(S21);
    game.Move(S31);
    /*
    memo: position here, so FirstP winning
      * * *
    * o   x
    * x o
    *     o
    */
    EXPECT_EQ(game.JudgeWinner(), FirstP);
}