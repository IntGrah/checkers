#ifndef GAMENODE_H
#define GAMENODE_H

#include <vector>
#include <cstdint>
#include <iostream>

#include "bitboard.h"

class GameNode
{
public:
    U64 x; // Player X's pieces
    U64 o; // Player O's pieces
    U64 u; // Union, all pieces
    bool turn; // True: X's turn, false: O's turn

public:
    GameNode(const U64 x, const U64 o, const bool turn);
    int evaluate(const int depth);
private:
    U64 minorMoves(const U64 piece);
    U64 majorMoves(const U64 piece);
    U64 pieceMoves(const U64 piece);
    std::vector<GameNode> children();
};

#endif // #ifndef GAMENODE_H
