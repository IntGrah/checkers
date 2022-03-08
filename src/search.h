#ifndef SEARCH_H
#define SEARCH_H

#include <algorithm>
#include <vector>

inline int max(const std::vector<int> &evaluations)
{
  return *max_element(evaluations.begin(), evaluations.end());
}

inline int min(const std::vector<int> &evaluations)
{
  return *min_element(evaluations.begin(), evaluations.end());
}

#endif // #ifndef SEARCH_H
