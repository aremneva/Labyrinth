/*****************************************************************//**
 * \file   LeeAlgorithm.h
 * \brief  This is the header file with constants and structure 
 * 
 * \author aremneva
 * \date   December 2024
 *********************************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
/// Constants describing the different elements of the labyrinth
const char WALL = '4'; ///< wall
const char PASSAGE = '3'; ///< passage
const char ENTRANCE = '1';///< entrance
const char EXIT = '2';///< exit
const char PATH = '*';///< path
///A structure for representing a position in a maze
struct Position {
    int x, y;
};
/**
*@brief Implements a wave algorithm for finding a path in a maze
* @param maze initial maze
* @param result matrix to record the result with the path found
*/
void LeeAlgorithm(const std::vector<std::vector<char>>& maze,
    std::vector<std::vector<char>>& result);
#pragma once
