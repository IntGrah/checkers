#include "evaluation.h"
#include "node.h"

constexpr int Node::heuristicEvaluate() const
{
    return sum + tailPlayerOne() + tailPlayerTwo() - 14;
}

constexpr int Node::tailPlayerOne() const
{
    for (int i = 0; i < 15; ++i)
    {
        if (!!(playerOne & diagonals[i]))
        {
            return i;
        }
    }
    return -1;
}

constexpr int Node::tailPlayerTwo() const
{
    {
        for (int i = 14; i >= 0; --i)
        {
            if (!!(playerTwo & diagonals[i]))
            {
                return i;
            }
        }
        return -1;
    }
}
