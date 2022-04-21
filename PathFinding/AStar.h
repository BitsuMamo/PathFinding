#pragma once
#include <vector>
namespace AStar{

  struct Cell{
    int x, y;
    double f, g, h;
  };

  double CalculateHValue(int row, int col, std::pair<int, int> destination);
  bool FindPath(std::vector<std::vector<int>> map, std::pair<int,int> pos, std::pair<int,int> dest_pos);
}

