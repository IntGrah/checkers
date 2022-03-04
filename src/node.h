#ifndef GAMENODE_H
#define GAMENODE_H

#include <ostream>
#include <vector>

#include "bitboard.h"

class Node
{
public:
    U64 playerOne;              // Player one's pieces
    U64 playerTwo;              // Player two's pieces
    U64 playerAll;              // All pieces
    bool turn;                  // True: player one's turn, false: player two's turn
    int sum;                    // Sum of magnitude of all pieces
    std::vector<Node> children; // Child nodes

public:
    constexpr Node(const U64 x, const U64 o, const bool turn, const int sum); // node.cpp
    int evaluate(const int depth);                                            // search.cpp

public:
    constexpr U64 minorMoves(const U64 piece) const; // movegen.cpp
    constexpr U64 majorMoves(const U64 piece) const; // movegen.cpp
    constexpr U64 pieceMoves(const U64 piece) const; // movegen.cpp
    std::vector<Node> *populate();                   // movegen.cpp
    
    constexpr int tailPlayerOne() const;             // evaluation.cpp
    constexpr int tailPlayerTwo() const;             // evaluation.cpp
    constexpr int heuristicEvaluate() const;         // evaluation.cpp
};

std::ostream &operator<<(std::ostream &stream, Node &node);

#endif // #ifndef GAMENODE_H
