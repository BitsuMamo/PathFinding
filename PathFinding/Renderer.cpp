#include "Renderer.h"
#include <iostream>
#include "Utility.h"
#include <chrono>
#include <thread>

namespace Renderer {

void RenderMap(std::vector<std::vector<int>> map,
               std::pair<int, int> map_dimension, std::pair<int, int> start_pos,
               std::vector<std::vector<int>> visited,
               std::string directionPointer, bool debug) {

  // This Formula is need to make a fast renderer using just one loop.
  // Formula = row_size * i + j = N
  int col_size = map.size();
  int row_size = map[0].size();
  int N = row_size * col_size;
  int row = 0;
  int col, value;

  std::string map_render = "";
  for (int n = 0; n < N; n++) {
    // Determinging the row number and increasing it if it is reached
    if (n % row_size == 0 && n != 0) {
      map_render += "\n";
      row++;
    }
    
    // Getting column size
    col = abs((row_size * row) - n);

    value = map[row][col];

    if (row == start_pos.first && col == start_pos.second) {
      map_render += " " + directionPointer + " ";
      continue;
    }

    if (visited[row][col] == 1) {
      map_render += " . ";
      continue;
    }

    if (value == -1) {
      map_render += "XXX";
    } else if (value == 0) {
      map_render += "   ";
    } else {
      map_render += " E ";
    }
  }
  
  std::cout << map_render << std::endl;
  
  // Going to print debug info and pause the screen if true
  if (debug) {
    Debug(visited, start_pos);
  }else{
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    system("cls");
  }
}

void Debug(std::vector<std::vector<int>> &visited, std::pair<int, int> &pos) {
  std::printf("CUR_POS: {%d, %d}, Visited: %d", pos.first, pos.second,
              visited[pos.first][pos.second]);
  system("pause");
}

} // namespace Renderer
