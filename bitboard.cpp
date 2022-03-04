#include <iostream>

#include "bitboard.h"

void print(const U64 bb) // A debug function which pretty prints a bitboard
{
  U64 comparator = 1ULL << 63;
  int line = 0;
  while (comparator)
  {
    std::cout << !!(bb & comparator);
    comparator >>= 1;
    if (++line == 8)
    {
      line = 0;
      std::cout << "\n";
    }
  }
  std::cout << "\n";
}

const int index[64] = {
    0,  1, 48,  2, 57, 49, 28,  3,
   61, 58, 50, 42, 38, 29, 17,  4,
   62, 55, 59, 36, 53, 51, 43, 22,
   45, 39, 33, 30, 24, 18, 12,  5,
   63, 47, 56, 27, 60, 41, 37, 16,
   54, 35, 52, 21, 44, 32, 23, 11,
   46, 26, 40, 15, 34, 20, 31, 10,
   25, 14, 19,  9, 13,  8,  7,  6
};

inline int bitScanForward(U64 bb)
{
  constexpr U64 deBruijn64 = 0x03f79d71b4cb0a89;
  return index[((bb & -bb) * deBruijn64) >> 58];
}

inline int magnitude(U64 bb)
{
  int index = bitScanForward(bb);
  int file = index % 8;
  int rank = (index - file) / 8;
  return file + rank;
}
