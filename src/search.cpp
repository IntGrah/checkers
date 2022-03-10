#include <algorithm>
#include <iostream>

#include "evaluation.h"
#include "node.h"
#include "search.h"

inline int Node::evaluate(const int depth)
{
    if (turn && tailPlayerTwo() == 3)
    {
        return -1000 - depth;
    }
    if (!turn && tailPlayerOne() == 11)
    {
        return 1000 + depth;
    }
    if (depth == 0)
    {
        return heuristicEvaluate();
    }
    evaluations.clear();
    std::vector<Node> children = populate();
    int size = children.size();
    for (int i = 0; i < size; ++i)
    {
        evaluations.push_back(children[i].evaluate(depth - 1));
    }
    return turn ? max(evaluations) : min(evaluations);
}

Node &Node::bestMove(const int depth)
{
    return populate()[std::distance(evaluations.begin(), std::find(evaluations.begin(), evaluations.end(), evaluate(depth)))];
}
