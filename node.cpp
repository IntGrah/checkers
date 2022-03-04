#include "node.h"

Node::Node(const U64 x, const U64 o, const bool turn, const int sum)
{
    this->x = x;
    this->o = o;
    this->u = x | o;
    this->turn = turn;
    this->sum = sum;
}
