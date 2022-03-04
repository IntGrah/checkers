#ifndef EVALUATION_H
#define EVALUATION_H

#include "bitboard.h"

constexpr U64 diagonals[15] = {
    0b0000000000000001, // A1-A1 diagonal
    0x0000000000000102, // B1-A2 diagonal
    0x0000000000010204, // C1-A3 diagonal
    0x0000000001020408, // D1-A4 diagonal
    0x0000000102040810, // E1-A5 diagonal
    0x0000010204081020, // F1-A6 diagonal
    0x0001020408102040, // G1-A7 diagonal
    0x0102040810204080, // H1-A8 diagonal
    0x0204081020408000, // H2-B8 diagonal
    0x0408102040800000, // H3-C8 diagonal
    0x0810204080000000, // H4-D8 diagonal
    0x1020408000000000, // H5-E8 diagonal
    0x2040800000000000, // H6-F8 diagonal
    0x4080000000000000, // H7-G8 diagonal
    0x8000000000000000, // H8-H8 diagonal
};

#endif // #ifndef EVALUATION_H
