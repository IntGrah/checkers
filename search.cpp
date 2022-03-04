#include <algorithm>
#include <vector>

#include "evaluation.h"
#include "node.h"
#include "search.h"

int Node::evaluate(const int depth)
{
    if (!turn)
    {
        if (tailX() == 11)
        {
            return 1000 + depth;
        }
        if (tailO() == 3)
        {
            return -1000 - depth;
        }
    }
    if (depth == 0)
    {
        return heuristicEvaluate();
    }
    int size = (*populate()).size();
    std::vector<int> evaluations(size);
    for (int i = 0; i < size; ++i)
    {
        evaluations[i] = children[i].evaluate(depth - 1);
    }
    return turn ? *max_element(evaluations.begin(), evaluations.end()) : *min_element(evaluations.begin(), evaluations.end());
}
