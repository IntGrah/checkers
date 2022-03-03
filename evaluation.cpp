#include "evaluation.h"

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
