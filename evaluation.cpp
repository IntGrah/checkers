#include "evaluation.h"
#include "node.h"

int Node::heuristicEvaluate()
{
    return sum + tailX() + tailO() - 14;
}

int Node::tailX()
{
    for (int i = 0; i < 15; ++i)
    {
        if (!!(x & diagonals[i]))
        {
            return i;
        }
    }
    return -1;
}

int Node::tailO()
{
    {
        for (int i = 14; i >= 0; --i)
        {
            if (!!(o & diagonals[i]))
            {
                return i;
            }
        }
        return -1;
    }
}
