#include <gtest/gtest.h>
#include "../../src/basic/player.hpp"

using namespace CEB;

TEST(PlayerTest, PlayerSwitchTest)
{
    Player p = NoPlayer;
    EXPECT_EQ(!p, NoPlayer);
    p = PlayerLimit;
    EXPECT_EQ(!p, PlayerLimit);

    p = FirstP;
    EXPECT_EQ(!p, SecondP);
    EXPECT_EQ(++p, SecondP);
    EXPECT_EQ(p, SecondP);
}