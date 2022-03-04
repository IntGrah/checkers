#include "evaluation.h"
#include "node.h"

int Node::heuristicEvaluate()
{
    return sum + tailPlayerOne() + tailPlayerTwo() - 14;
}

int Node::tailPlayerOne()
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

int Node::tailPlayerTwo()
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
