/*****************************************************************//**
 * \file   main.cpp
 * \brief  This is the main file
 * 
 * \author aremneva
 * \date   December 2024
 *********************************************************************/



/* Выход Из Лабиринта

  Лабиринт задан матрицей: 1 --- вход, 2 ---выход, 3 --- проход, 4 --- стена (либо цифры заменить на символы).
    Реализовать алгоритм (на основе волнового алгоритма) построения пути от входа до выхода.
    Во входном файле --- лабиринт, в выходном лабиринт, в котором отмечен путь.
*/


/**
    *@brief The main function of a program that reads a maze from a file,
    *   applies the wave algorithm and writes the result to the output file.
    *
    * @return Program Termination Code.
*/
#include "LeeAlgorithm.h"

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Cant open the file\n";
        return 1;
    }

    std::vector<std::vector<char>> maze;
    std::string line;

    while (std::getline(inputFile, line)) {
        std::vector<char> row;
        for (char value : line) {
            if (value != ' ') {
                row.push_back(value);
            }
        }
        maze.push_back(row);
    }

    std::vector<std::vector<char>> result = maze;

    LeeAlgorithm(maze, result);

    for (const auto& row : result) {
        for (char cell : row) {
            std::cout << cell << " ";
            outputFile << cell << " ";
        }
        std::cout << std::endl;
        outputFile << std::endl;
    }

    outputFile.close();
    inputFile.close();

    return 0;
}
