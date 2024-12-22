/*****************************************************************//**
 * \file   LeeAlgorithm.cpp
 * \brief  This file contains the function with wave algortihm
 * 
 * \author aremneva
 * \date   December 2024
 *********************************************************************/

#include "LeeAlgorithm.h"
/**
* @brief Checks whether the position is valid for movement.
*
* @param x coordinate in the x-axis
* @param y coordinate in the y-axis
* @param maze labyrinth matrix
* @param visited matrix of visited cells
* @return true if the position is eligible
* @return false if the position is inadmissible
*/

bool isValid(int x, int y, const std::vector<std::vector<char>>& maze,
    const std::vector<std::vector<bool>>& visited) {
    return (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() &&
        maze[x][y] != WALL && !visited[x][y]);
}
/**
*@brief Implements a wave algorithm for finding a path in a maze
* @param maze initial maze
* @param result matrix to record the result with the path found
*/
void LeeAlgorithm(const std::vector<std::vector<char>>& maze,
    std::vector<std::vector<char>>& result) {
    int rows = maze.size();
    int cols = maze[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::vector<std::vector<Position>> parent(rows, std::vector<Position>(cols, { -1, -1 }));

    Position entrance;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (maze[i][j] == ENTRANCE) {
                entrance = { i, j };
            }
        }
    }

    std::vector<Position> queue;
    queue.push_back(entrance);
    visited[entrance.x][entrance.y] = true;

    std::vector<Position> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while (!queue.empty()) {
        Position current = queue.front();
        queue.erase(queue.begin());

        if (maze[current.x][current.y] == EXIT) {
            Position trace = current;
            while (trace.x != entrance.x || trace.y != entrance.y) {
                result[trace.x][trace.y] = PATH;
                trace = parent[trace.x][trace.y];
            }
            result[entrance.x][entrance.y] = PATH;
            result[current.x][current.y] = PATH;
            return;
        }

        for (const auto& dir : directions) {
            int newX = current.x + dir.x;
            int newY = current.y + dir.y;

            if (isValid(newX, newY, maze, visited)) {
                visited[newX][newY] = true;
                parent[newX][newY] = current;
                queue.push_back({ newX, newY });
            }
        }
    }
}

