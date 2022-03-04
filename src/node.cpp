#include "node.h"

Node::Node(const U64 playerOne, const U64 playerTwo, const bool turn, const int sum)
{
    this->playerOne = playerOne;
    this->playerTwo = playerTwo;
    this->playerAll = playerOne | playerTwo;
    this->turn = turn;
    this->sum = sum;
}
