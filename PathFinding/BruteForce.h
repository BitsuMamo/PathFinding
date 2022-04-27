#include <vector>
#include <stack>
#include <string>
#pragma once

namespace BruteForce {

bool FindPath(std::vector<std::vector<int>> map,
              std::pair<int, int> map_dimension,
              std::vector<std::vector<int>> &visited, std::pair<int, int> pos,
              int &count, bool render, bool debug);

} // namespace BruteForce
