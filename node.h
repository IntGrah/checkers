#ifndef GAMENODE_H
#define GAMENODE_H

#include <vector>

#include "bitboard.h"

class Node
{
public:
    U64 x;     // Player X's pieces
    U64 o;     // Player O's pieces
    U64 u;     // Union, all pieces
    bool turn; // True: X's turn, false: O's turn

public:
    Node(const U64 x, const U64 o, const bool turn); // node.cpp
    int evaluate(const int depth);                   // search.cpp

public:
    U64 minorMoves(const U64 piece); // movegen.cpp
    U64 majorMoves(const U64 piece); // movegen.cpp
    U64 pieceMoves(const U64 piece); // movegen.cpp
    std::vector<Node> children();    // movegen.cpp
    int tailX();                     // evaluation.cpp
    int tailO();                     // evaluation.cpp
    int heuristicEvaluate();         // evaluation.cpp
};

#endif // #ifndef GAMENODE_H
