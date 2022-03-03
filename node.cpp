#include "node.h"

Node::Node(const U64 x, const U64 o, const bool turn)
{
    this->x = x;
    this->o = o;
    this->u = x | o;
    this->turn = turn;
}
