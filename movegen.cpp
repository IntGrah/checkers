#include "movegen.h"
#include "node.h"

U64 Node::minorMoves(const U64 p)
{
    return (p >> 8 | (p >> 7 & NOT_A) | (p >> 1 & NOT_H) | (p << 1 & NOT_A) | (p << 7 & NOT_H) | p << 8) & ~u;
}

U64 Node::majorMoves(const U64 p)
{
    U64 d = p;
    U64 previous;
    while (previous != d)
    {
        previous = d;
        d |= ((d >> 16 & u >> 8) | (d >> 14 & u >> 7 & NOT_AB) | (d >> 2 & u >> 1 & NOT_GH) | (d << 2 & u << 1 & NOT_AB) | (d << 14 & u << 7 & NOT_GH) | (d << 16 & u << 8)) & ~u;
    }
    return d & ~p; // The starting position of the piece is not a valid destination
}

U64 Node::pieceMoves(const U64 p)
{
    return minorMoves(p) | majorMoves(p);
}

std::vector<Node> Node::children()
{
    std::vector<Node> children{};
    U64 pieces = turn ? x : o;
    while (pieces)
    {
        U64 piece = pieces & -pieces; // Handy trick to isolate the least significant bit
        pieces ^= piece;
        U64 moves = pieceMoves(piece);
        while (moves)
        {
            U64 move = moves & -moves;
            moves ^= move;
            // Filter out moves which move backwards too much?
            U64 _x = x;
            U64 _o = o;
            if (turn)
            {
                _x ^= piece | move; // Flip the bits of the piece and its destination
            }
            else
            {
                _o ^= piece | move;
            }
            children.push_back(Node(_x, _o, !turn));
        }
    }
    return children; // Sort by magnitude?
}
