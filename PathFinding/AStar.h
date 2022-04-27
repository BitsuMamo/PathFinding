#pragma once
#include <vector>
#include <cmath>
#include <set>
#include "Utility.h"
#include "Renderer.h"
namespace AStar{

  struct Cell{
    int x, y;
    double f, g, h;
  };

  double CalculateHValue(int row, int col, std::pair<int, int> destination);
  bool FindPath(std::vector<std::vector<int>> map, std::pair<int,int> map_dimensions, std::pair<int,int> pos, std::pair<int,int> dest_pos, std::vector<std::vector<int>> &visited, int& count, bool render, bool debug);
}

