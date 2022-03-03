#include <iostream>

#include "evaluation.h"
#include "gamenode.h"

int main()
{
    GameNode start(START_X, START_O, true);
    for (auto child : start.children())
    {
        print(child.x);
    }
}
