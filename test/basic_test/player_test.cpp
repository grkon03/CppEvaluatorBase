#include <gtest/gtest.h>
#include "../../src/basic/player.hpp"

using namespace CEB;

TEST(PlayerTest, PlayerSwitchTest)
{
    Player p = NonePlayer;
    EXPECT_EQ(!p, NonePlayer);
    p = PlayerLimit;
    EXPECT_EQ(!p, PlayerLimit);

    p = FirstP;
    EXPECT_EQ(!p, SecondP);
    EXPECT_EQ(++p, FirstP);
    EXPECT_EQ(p, FirstP);
    EXPECT_EQ(p++, FirstP);
    EXPECT_EQ(p, SecondP);
}