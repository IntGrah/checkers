#ifndef SEARCH_H
#define SEARCH_H

#include <vector>

constexpr int max(const std::vector<int> &evaluations)
{
  return *max_element(evaluations.begin(), evaluations.end());
}

#endif // #ifndef SEARCH_H
