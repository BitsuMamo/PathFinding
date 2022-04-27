#include "AStar.h"

namespace AStar{

	std::string directionPointer = "*";
  double CalculateHValue(int row, int col, std::pair<int, int> destination){
	double hValue = 0;
	hValue = std::sqrt(std::pow(row - destination.first, 2) + std::pow(col - destination.second, 2));
	return hValue;
  }

  bool FindPath(std::vector<std::vector<int>> map,std::pair<int, int> map_dimensions, std::pair<int, int> pos, std::pair<int, int> dest_pos, std::vector<std::vector<int>>& visited, int& count, bool render , bool debug){
	  std::vector<std::vector<Cell>> cells;
	for (int i = 0; i < map_dimensions.first; i++) {
		std::vector<Cell> row;
		for (int j = 0; j < map_dimensions.second; j++) {
			Cell cell;
			cell.x = -1;
			cell.y = -1;
			cell.h = FLT_MAX;
			cell.f = FLT_MAX;
			cell.g = FLT_MAX;
			row.push_back(cell);
		}
		cells.push_back(row);
	}
	cells[pos.first][pos.second].f = 0.0;
	cells[pos.first][pos.second].g = 0.0;
	cells[pos.first][pos.second].h = 0.0;
	cells[pos.first][pos.second].x = pos.first;
	cells[pos.first][pos.second].y = pos.second;



	std::set<std::pair<float, std::pair<int, int>>> open_list;
	std::pair<float,std::pair<int, int>> current_cell;
	current_cell.first = cells[pos.first][pos.second].f;
	current_cell.second.first = pos.first;
	current_cell.second.second = pos.second;
	open_list.insert(current_cell);


	bool found = false;
	
	while (!open_list.empty() && !found) {
		count++;
		current_cell = *open_list.begin();

		open_list.erase(open_list.begin());
		
		if (current_cell.second.first == dest_pos.first && current_cell.second.second == dest_pos.second) {
			found = true;
			break;
		}
		
		int i = current_cell.second.first;
		int j = current_cell.second.second;
		visited[i][j] = 1;
		if (render) {
			Renderer::RenderMap(map, map_dimensions, { i,j }, visited, directionPointer, debug);
		}			

		double gNew, hNew, fNew;
		
		std::vector<std::pair<int, int>> directions = {
	{1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

		for (auto direction : directions) {
			if (i + direction.first >= 0 && i + direction.first < map_dimensions.first && j + direction.second >= 0 && j + direction.second < map_dimensions.second) {
				int next_i = i + direction.first;
				int next_j = j + direction.second;
				if (next_i == dest_pos.first && next_j == dest_pos.second) {
					found = true;
					cells[next_i][next_j].x = i;
					cells[next_i][next_j].y = j;
					break;
				}
				else if (visited[next_i][next_j] == 0 && map[next_i][next_j] != WALL) {
					gNew = cells[i][j].g + 1.0;
					hNew = CalculateHValue(next_i, next_j, dest_pos);
					fNew = gNew + hNew;
					if (fNew < cells[next_i][next_j].f) {
						cells[next_i][next_j].f = fNew;
						cells[next_i][next_j].g = gNew;
						cells[next_i][next_j].h = hNew;
						cells[next_i][next_j].x = i;
						cells[next_i][next_j].y = j;
						std::pair<float, std::pair<int, int>> next_cell;
						next_cell.first = cells[next_i][next_j].f;
						next_cell.second.first = next_i;
						next_cell.second.second = next_j;
						open_list.insert(next_cell);
					}
				}

				
			}
		}
		
	}

	return found;
  }

}
