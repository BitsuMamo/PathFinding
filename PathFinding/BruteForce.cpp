#include "BruteForce.h"
#include "Renderer.h"
#include "Utility.h"
#include <iostream>
#include <vector>

namespace BruteForce {

// All the allowed direction for the movment from current position
std::vector<std::pair<int, int>> directions = {
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

std::string render_map;
std::string directionPointer;

bool FindPath(std::vector<std::vector<int>> map,
              std::pair<int, int> map_dimension,
              std::vector<std::vector<int>> &visited, std::pair<int, int> pos,
              int &count, bool render,
              bool debug) {

  // Checks to see if we don't pass the bounds of the array.
  if (pos.first >= map_dimension.first || pos.second >= map_dimension.second ||
      pos.first < 0 || pos.second < 0) {
    return false;
  }

  // Checks if the current postion has been visitied or not
  if (visited[pos.first][pos.second] == 1) {
    return false;
  }

  // Checkes to see if current position is a wall
  if (map[pos.first][pos.second] == WALL) {
    return false;
  }

  // Checks to see if current position is the end
  if (map[pos.first][pos.second] == END) {
    return true;
  }

  // If render is wanted we can render the map to the console screen
  /* if (render)
    Renderer::RenderMap(map, map_dimension, pos, visited, directionPointer,
                        debug); */

  // Adds current postion to visited array
  visited[pos.first][pos.second] = 1;

  for (auto direction : directions) {
    // Changing the postion indication based on direction it is going
      if (render) {
          if (direction.first == 0 && direction.second == -1) {
              directionPointer = "^";
          }
          else if (direction.first == 0 && direction.second == 1) {

              directionPointer = "v";
          }
          else if (direction.first == -1 && direction.second == 0) {
              directionPointer = "<";
          }
          else if (direction.first == 1 && direction.second == 0) {
              directionPointer = ">";
          }
          else if ((direction.first == 1 && direction.second == 1) ||
              (direction.first == -1 && direction.second == -1)) {
              directionPointer = "\\";
          }
          else {
              directionPointer = "/";
          }

          Renderer::RenderMap(map, map_dimension, pos, visited, directionPointer,
              debug);
      }
    // Returning true at the end if there is a path to the end
    if (FindPath(map, map_dimension, visited,
                 {pos.first + direction.first, pos.second + direction.second},
                 count = count + 1, render, debug)) {
      return true;
    }
  }

  // Just incase everything fails and I need to quit
  return false;
}
} // namespace BruteForce
