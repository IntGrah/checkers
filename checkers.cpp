#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * 11110000 8
 * 11100000 7
 * 11000000 6
 * 10000000 5
 * 00000001 4
 * 00000011 3
 * 00000111 2
 * 00001111.1
 * hgfedcba
 */

typedef unsigned long long U64;

constexpr int magicSquare[64] = {
    0, 1, 48, 2, 57, 49, 28, 3,
    61, 58, 50, 42, 38, 29, 17, 4,
    62, 55, 59, 36, 53, 51, 43, 22,
    45, 39, 33, 30, 24, 18, 12, 5,
    63, 47, 56, 27, 60, 41, 37, 16,
    54, 35, 52, 21, 44, 32, 23, 11,
    46, 26, 40, 15, 34, 20, 31, 10,
    25, 14, 19, 9, 13, 8, 7, 6};

constexpr U64 deBruijn64 = 0x03f79d71b4cb0a89;

int bitScanForward(const U64 bb) // Find index of least significant set bit
{
    return magicSquare[((bb & -bb) * deBruijn64) >> 58];
}

int score(const U64 piece, const bool turn)
{
    int index = bitScanForward(piece);
    int file = index % 8;
    int rank = (index - file) / 8;
    return 2 * (file + rank) + (turn ? -1 : 1) * abs(file - rank);
}

/*
         o
        o o
       o o o
      o o o o
     # # # # #
    # # # # # #
   # # # # # # #
  # # # # # # # #
   # # # # # # #
    # # # # # #
     # # # # #
      x x x x
       x x x
        x x
         x
*/

constexpr U64 NOT_A = 0xfefefefefefefefe;
constexpr U64 NOT_H = 0x7f7f7f7f7f7f7f7f;
constexpr U64 NOT_AB = 0xfcfcfcfcfcfcfcfc;
constexpr U64 NOT_GH = 0x3f3f3f3f3f3f3f3f;

constexpr U64 diagonals[15] = {
    0x0000000000000001,
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
    0x8000000000000000
};

struct Node
{
    U64 one;                 // Player one's pieces
    U64 two;                 // Player two's pieces
    U64 all;                 // All pieces
    bool turn;               // Player one/two: true/false
    int sum;                 // Sum of magnitude of all pieces
    vector<int> evaluations; // Evaluations of child nodes

    Node(const U64 one, const U64 two, const bool turn, const int sum)
    {
        this->one = one;
        this->two = two;
        this->all = one | two;
        this->turn = turn;
        this->sum = sum;
    }
    void print() const
    {
        for (int row = 0; row < 8; ++row)
        {
            for (int sp = 0; sp < 7 - row; ++sp)
            {
                cout << " ";
            }
            for (int column = 0; column < row + 1; ++column)
            {
                int i = (63 - 8 * row + column * 7);
                cout << ((all >> i) & 1 ? ((one >> i) & 1) ? "x " : "o " : "- ");
            }
            cout << "\n";
        }
        for (int row = 8; row < 15; ++row)
        {
            for (int sp = 0; sp < row - 7; ++sp)
            {
                cout << " ";
            }
            for (int column = 0; column < 15 - row; ++column)
            {
                int i = (14 - row + column * 7);
                cout << ((all >> i) & 1 ? ((one >> i) & 1) ? "x " : "o " : "- ");
            }
            cout << "\n";
        }
        cout << "\n";
    }
    int evaluate(const int depth)
    {
        if (turn && tailTwo() == 3)
        {
            return -1000 - depth;
        }
        if (!turn && tailOne() == 11)
        {
            return 1000 + depth;
        }
        if (depth == 0)
        {
            return heuristic();
        }
        evaluations.clear();
        vector<Node> children = populate();
        int size = children.size();
        for (int i = 0; i < size; ++i)
        {
            evaluations.push_back(children[i].evaluate(depth - 1));
        }
        return turn
                   ? *max_element(evaluations.begin(), evaluations.end())
                   : *min_element(evaluations.begin(), evaluations.end());
    }
    Node &bestMove(const int depth)
    {
        int evaluation = evaluate(depth);
        int index = 0;
        while (index < evaluations.size())
        {
            if (evaluations[index] == evaluation)
            {
                break;
            }
            index++;
        }
        return populate()[index];
    }
    bool terminated() const
    {
        return tailOne() == 11 || tailTwo() == 3;
    }

    U64 minorMoves(const U64 p) const
    {
        return (p >> 8 |
                (p >> 7 & NOT_A) |
                (p >> 1 & NOT_H) |
                (p << 1 & NOT_A) |
                (p << 7 & NOT_H) |
                p << 8) &
               ~all;
    }
    U64 majorMoves(const U64 p) const
    {
        U64 d = p;
        U64 previous = 0;
        while (previous != d) // Repeat until no further change
        {
            previous = d; // Store the result of the previous iteration
            d |= ((d >> 16 & all >> 8) |
                  (d >> 14 & all >> 7 & NOT_AB) |
                  (d >> 2 & all >> 1 & NOT_GH) |
                  (d << 2 & all << 1 & NOT_AB) |
                  (d << 14 & all << 7 & NOT_GH) |
                  (d << 16 & all << 8)) &
                 ~all;
        }
        return d & ~p; // The starting position of the piece is not a valid destination
    }
    U64 pieceMoves(const U64 p) const
    {
        return minorMoves(p) | majorMoves(p);
    }
    vector<Node> populate()
    {
        vector<Node> children;
        U64 pieces = turn ? one : two;
        while (pieces)
        {
            U64 piece = pieces & -pieces;
            pieces ^= piece;
            U64 moves = pieceMoves(piece);
            while (moves)
            {
                U64 move = moves & -moves;
                moves ^= move;
                int sumChange = score(move, turn) - score(piece, turn);
                if ((turn && sumChange < -2) || (!turn && sumChange > 2)) // Filter out moves which move backwards too much.
                {
                    continue;
                }
                U64 one_ = one;
                U64 two_ = two;
                if (turn)
                {
                    one_ ^= piece | move; // Flip the bits of the piece and its destination.
                }
                else
                {
                    two_ ^= piece | move;
                }
                children.push_back(Node(one_, two_, !turn, sum + sumChange));
            }
        }
        return children; // Sort by magnitude?
    }

    int tailOne() const
    {
        for (int i = 0; i < 15; ++i)
        {
            if (one & diagonals[i])
            {
                return i;
            }
        }
        return -1;
    }
    int tailTwo() const
    {
        {
            for (int i = 14; i >= 0; --i)
            {
                if (two & diagonals[i])
                {
                    return i;
                }
            }
            return -1;
        }
    }
    int heuristic() const
    {
        return sum + 3 * tailOne() + 3 * tailTwo() - 28;
    }
};

constexpr U64 START_PLAYER_ONE = 0x000000000103070f;
constexpr U64 START_PLAYER_TWO = 0xf0e0c08000000000;

int main()
{
    Node game(START_PLAYER_ONE, START_PLAYER_TWO, true, 0);
    while (!game.terminated())
    {
        game.print();
        game = game.bestMove(5);
    }
    game.print();
}
