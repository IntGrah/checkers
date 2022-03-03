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
    std::vector<int> evaluations = {};
    std::vector<Node> chn = children();
    int size = chn.size();
    int evaluation;
    if (turn)
    {
        evaluation = -10000;
        for (int i = 0; i < size; i++)
        {
            int childEvaluation = chn[i].evaluate(depth - 1);
            if (childEvaluation > evaluation)
            {
                evaluation = childEvaluation;
            }
        }
    }
    else
    {
        evaluation = 10000;
        for (int i = 0; i < size; i++)
        {
            int childEvaluation = chn[i].evaluate(depth - 1);
            if (childEvaluation < evaluation)
            {
                evaluation = childEvaluation;
            }
        }
    }
    return evaluation;
}
