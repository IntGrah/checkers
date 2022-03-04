#include "movegen.h"
#include "node.h"

U64 Node::minorMoves(const U64 p) const // A minor move is a move which does not jump over a piece; it moves one square only.
{
  return (p >> 8 | (p >> 7 & NOT_A) | (p >> 1 & NOT_H) | (p << 1 & NOT_A) | (p << 7 & NOT_H) | p << 8) & ~playerAll;
  //                                                                                                      ^ make sure the destination is empty.
}

U64 Node::majorMoves(const U64 p) const // A major move is a move which jumps over a piece.
{
  U64 d = p;
  U64 previous = 0;
  while (previous != d) // If no more destinations were added, stop.
  {
    previous = d; // Store the result of the previous iteration.
    d |= ((d >> 16 & playerAll >> 8) | (d >> 14 & playerAll >> 7 & NOT_AB) | (d >> 2 & playerAll >> 1 & NOT_GH) | (d << 2 & playerAll << 1 & NOT_AB) | (d << 14 & playerAll << 7 & NOT_GH) | (d << 16 & playerAll << 8)) & ~playerAll;
  }
  return d & ~p; // The starting position of the piece is not a valid destination
}

constexpr U64 Node::pieceMoves(const U64 p) const // Combines minor and major moves;
{
  return minorMoves(p) | majorMoves(p);
}

std::vector<Node> *Node::populate() // Generates children with all possible child nodes.
{
  U64 pieces = turn ? playerOne : playerTwo;
  while (pieces)
  {
    isolateBit(piece, pieces);
    U64 moves = pieceMoves(piece);
    while (moves)
    {
      isolateBit(move, moves);
      int sumChange = magnitude(move) - magnitude(piece);
      if ((turn && sumChange < -2) || (!turn && sumChange > 2)) // Filter out moves which move backwards too much.
      {
        continue;
      }
      U64 _playerOne = playerOne;
      U64 _playerTwo = playerTwo;
      if (turn)
      {
        _playerOne ^= piece | move; // Flip the bits of the piece and its destination.
      }
      else
      {
        _playerTwo ^= piece | move;
      }
      children.push_back(Node(_playerOne, _playerTwo, !turn, sum + sumChange));
    }
  }
  return &children; // Sort by magnitude?
}
