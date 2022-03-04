/*
  BITBOARD ARCHITECTURE

  11110000 8
  11100000 7
  11000000 6
  10000000 5 (Ranks)
  00000001 4
  00000011 3
  00000111 2
  00001111.1
  hgfedcba
  (Files)

  Represented by the 64 bit integer 0xf0e0c0800103070f, or 0b1111000011100000110000001000000000000001000000110000011100001111

  Bottom right (least significant bit): Player X, who goes first.
  Top left (most significant bit): Player O, who goes second.
*/

#ifndef BITBOARD_H
#define BITBOARD_H

typedef unsigned long long U64;

#define isolateBit(ibb, bb) \
  U64 ibb = bb & -bb;       \
  bb ^= ibb

inline void print(const U64 bb); // A debug function which pretty prints a bitboard.

inline int bitScanForward(U64 bb); // Returns the index of the least significant set bit. This algorithm uses de Bruijn sequences to achieve constant time complexity.

inline int magnitude(U64 bb); // Computes the taxicab distance of a piece from (0, 0).

#endif // #ifndef BITBOARD_H
