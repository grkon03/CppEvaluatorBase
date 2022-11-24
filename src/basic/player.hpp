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
        NonePlayer = -1,
        FirstP,
        SecondP,
        PlayerLimit,
    };

    inline Player operator!(Player);
    inline Player operator++(Player);
    inline Player operator++(Player, int);
}