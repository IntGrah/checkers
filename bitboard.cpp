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
