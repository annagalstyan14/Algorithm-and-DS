#ifndef WAVE_H
#define WAVE_H

#include <iostream>
#include <vector>
#include "../Queue/queueArray.h"

bool isValid(int row, int col, int n, int m,
             std::vector<std::vector<char>> &mat,
             std::vector<std::vector<bool>> &visited);

bool validateMatrix(const std::vector<std::vector<char>>& mat, int n, int m);

void printMatrix(const std::vector<std::vector<char>>& mat, int n, int m);

int shortestPath(std::vector<std::vector<char>> &mat);

#endif // WAVE_H
