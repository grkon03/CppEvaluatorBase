/*
player.hpp

Defining player type
*/
#pragma once

namespace CEB
{
    // player type
    enum Player : int
    {
        NoPlayer = -1,
        FirstP,
        SecondP,
        PlayerLimit,
    };

    inline Player operator!(Player p) { return (p == NoPlayer || p == PlayerLimit) ? p : Player(1 - (int)p); }
    inline Player &operator++(Player &p) { return (p = !p); }
}