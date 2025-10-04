#ifndef WAVE_H
#define WAVE_H

#include <iostream>
#include <vector>
#include "../Queue/queueArray.h"

inline bool isValid(int row, int col, int n, int m,
                    std::vector<std::vector<char>> &mat,
                    std::vector<std::vector<bool>> &visited) {
    return row >= 0 && row < n &&
           col >= 0 && col < m &&
           mat[row][col] != '0' &&
           !visited[row][col];
}

inline bool validateMatrix(const std::vector<std::vector<char>>& mat, int n, int m) {
    int sCount = 0, dCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = mat[i][j];
            if (c == 's') sCount++;
            else if (c == 'd') dCount++;
            else if (c != '0' && c != '1') return false;
        }
    }
    return sCount == 1 && dCount == 1;
}

inline void printMatrix(const std::vector<std::vector<char>>& mat, int n, int m) {
    std::cout << "\nInput Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int shortestPath(std::vector<std::vector<char>> &mat) {
    int n = mat.size();   
    int m = mat[0].size();

    std::vector<int> dRow = {-1, 1, 0, 0};
    std::vector<int> dCol = {0, 0, -1, 1};

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));

    Queue<std::vector<int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 's') {
                q.enqueue({i, j, 0});
                visited[i][j] = true;
                break;
            }
        }
    }

    while (!q.isEmpty()) {
        std::vector<int> curr = q.dequeue();
        int row = curr[0];
        int col = curr[1];
        int dist = curr[2];

        if (mat[row][col] == 'd') {
            return dist;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];

            if (isValid(newRow, newCol, n, m, mat, visited)) {
                visited[newRow][newCol] = true;
                q.enqueue({newRow, newCol, dist + 1});
            }
        }
    }

    return -1;
}

#endif // WAVE_H
