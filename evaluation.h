#ifndef EVALUATION_H
#define EVALUATION_H

#include "bitboard.h"

const U64 diagonals[15] = {
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

// int GameNode::heuristicEvaluate()
// {
//     int value = -176;
//     int lastX = 13;
//     int lastO = 3;
//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             char piece = board[i][j];
//             if (piece != 0)
//             {
//                 value += i + j + (piece - 1.5) * abs(i - j);
//                 if (piece == 1)
//                 {
//                     if (i + j < lastX)
//                     {
//                         lastX = i + j;
//                     }
//                 }
//                 else
//                 {
//                     if (i + j > lastO)
//                     {
//                         lastO = i + j;
//                     }
//                 }
//             }
//         }
//     }
//     return value + lastX + lastO;
// }

int head(U64 bb)
{
    {
        for (int i = 14; i >= 0; --i)
        {
            if (!!(bb & diagonals[i]))
            {
                return i;
            }
        }
        return -1;
    }
}

int tail(U64 bb)
{
    for (int i = 0; i < 15; ++i)
    {
        if (!!(bb & diagonals[i]))
        {
            return i;
        }
    }
    return -1;
}

#endif // #ifndef EVALUATION_H
