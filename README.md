# checkers
### Simplifications:
- The board is 8x8, not 9x9 in order to fit one board into a 64 bit integer.
- There are only two players.
- A move which moves backwards too much is not considered by the engine.

### The structure of bitboards is shown below.
```
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

  Bottom right (least significant bit): Player one, who goes first.
  Top left (most significant bit): Player two, who goes second.
```
