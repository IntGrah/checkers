#ifndef EVALUATION_H
#define EVALUATION_H

#include "bitboard.h"

constexpr U64 diagonals[15] = {
    0b0000000000000001,
    0x0000000000000102,
    0x0000000000010204,
    0x0000000001020408,
    0x0000000102040810,
    0x0000010204081020,
    0x0001020408102040,
    0x0102040810204080,
    0x0204081020408000,
    0x0408102040800000,
    0x0810204080000000,
    0x1020408000000000,
    0x2040800000000000,
    0x4080000000000000,
    0x8000000000000000,
};

#endif // #ifndef EVALUATION_H
