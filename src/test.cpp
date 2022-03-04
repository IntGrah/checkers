#include <iostream>

#include "evaluation.h"
#include "node.h"

constexpr U64 START_PLAYER_ONE = 0x000000000103070f;
constexpr U64 START_PLAYER_TWO = 0xf0e0c08000000000;
constexpr U64 START_PLAYER_ALL = START_PLAYER_ONE & START_PLAYER_TWO;

int main()
{
    Node START(START_PLAYER_ONE, START_PLAYER_TWO, true, 0);
    for (auto child : *START.populate())
    {
        std::cout << child << child.evaluate(2) << "\n\n";
    }
    std::cout << START.evaluate(3);
}
