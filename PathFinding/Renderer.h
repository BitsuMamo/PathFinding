#pragma once
#include <vector>
#include <utility>
#include <string>
namespace Renderer {
void RenderMap(std::vector<std::vector<int>> map,
               std::pair<int, int> map_dimension, std::pair<int, int> start_pos,
               std::vector<std::vector<int>> visited,
               std::string& directionPointer, bool debug);


void Debug(std::vector<std::vector<int>> &visited, std::pair<int, int> &pos);
} // namespace Renderer
