#include <iostream>

#include "evaluation.h"
#include "node.h"

constexpr U64 START_X = 0x000000000103070f;
constexpr U64 START_O = 0xf0e0c08000000000;
constexpr U64 START_U = START_X & START_O;

int main()
{
    Node START(START_X, START_O, true, 0);
    std::cout << START.evaluate(3);
}
