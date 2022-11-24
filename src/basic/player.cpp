#include "player.hpp"

namespace CEB
{
    inline Player operator!(Player p) { return (p == NonePlayer || p == PlayerLimit) ? p : Player(1 - p); }
    inline Player operator++(Player p) { return (p == NonePlayer || p == PlayerLimit) ? p : (p = Player(1 - p)); }
    inline Player operator++(Player p, int _)
    {
        p = Player(1 - p);
        return !p;
    }
}