#include <iostream>

#include "node.h"

Node::Node(const U64 playerOne, const U64 playerTwo, const bool turn, const int sum)
{
    this->playerOne = playerOne;
    this->playerTwo = playerTwo;
    this->playerAll = playerOne | playerTwo;
    this->turn = turn;
    this->sum = sum;
}

/*
         O
        O O
       O O O
      O O O O
     # # # # #
    # # # # # #
   # # # # # # #
  # # # # # # # #
   # # # # # # #
    # # # # # #
     # # # # #
      X X X X
       X X X
        X X
         X
*/

void Node::print() const
{
    for (int row = 0; row < 8; ++row)
    {
        for (int sp = 0; sp < 7 - row; ++sp)
        {
            std::cout << " ";
        }
        for (int column = 0; column < row + 1; ++column)
        {
            int i = (63 - 8 * row + column * 7);
            std::cout << ((playerAll >> i) & 1 ? ((playerOne >> i) & 1) ? "X " : "O " : "- ");
        }
        std::cout << "\n";
    }
    for (int row = 8; row < 15; ++row)
    {
        for (int sp = 0; sp < row - 7; ++sp)
        {
            std::cout << " ";
        }
        for (int column = 0; column < 15 - row; ++column)
        {
            int i = (14 - row + column * 7);
            std::cout << ((playerAll >> i) & 1 ? ((playerOne >> i) & 1) ? "X " : "O " : "- ");
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
