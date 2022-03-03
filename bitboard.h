// 11110000 8
// 11100000 7
// 11000000 6
// 10000000 5
// 00000001 4
// 00000011 3
// 00000111 2
// 00001111.1
// hgfedcba

#ifndef BITBOARD_H
#define BITBOARD_H

typedef unsigned long long U64;

constexpr U64 START_U = 0xf0e0c0800103070f;
constexpr U64 START_X = 0x000000000103070f;
constexpr U64 START_O = 0xf0e0c08000000000;
constexpr U64 NOT_A = 0xfefefefefefefefe;
constexpr U64 NOT_H = 0x7f7f7f7f7f7f7f7f;
constexpr U64 NOT_AB = 0xfcfcfcfcfcfcfcfc;
constexpr U64 NOT_GH = 0x3f3f3f3f3f3f3f3f;

void print(const U64 bb) // A debug function which pretty prints a bitboard

#endif // #ifndef BITBOARD_H
