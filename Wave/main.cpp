#include "wave.h"
#include <iostream>
#include <limits>

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int n, m;

    std::cout << "Welcome to the Shortest Path Finder (Wave Algorithm)!\n";
    std::cout << "Enter the matrix dimensions (rows columns):\n";

    while (true) {
        std::cout << "Rows: ";
        if (std::cin >> n && n > 0) {
            std::cout << "Columns: ";
            if (std::cin >> m && m > 0) {
                break;
            }
        }
        std::cout << "Error: Please enter positive integers for rows and columns.\n";
        clearInputBuffer();
    }
    clearInputBuffer();

    std::vector<std::vector<char>> mat(n, std::vector<char>(m));

    std::cout << "\nEnter the matrix elements row by row (use 's' for source, 'd' for destination, '0' for blocked, '1' for passable):\n";
    bool validInput = true;
    for (int i = 0; i < n; i++) {
        std::cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < m; j++) {
            char c;
            std::cin >> c;
            if (c == 's' || c == 'd' || c == '0' || c == '1') {
                mat[i][j] = c;
            } else {
                std::cout << "Error: Invalid character '" << c << "'. Use 's', 'd', '0', or '1'.\n";
                validInput = false;
                break;
            }
        }
        if (!validInput) break;
        clearInputBuffer();
    }

    if (validInput && !validateMatrix(mat, n, m)) {
        std::cout << "Error: Matrix must contain exactly one 's' (source) and one 'd' (destination).\n";
        return 1;
    }

    printMatrix(mat, n, m);

    int result = shortestPath(mat);

    std::cout << "\nResult:\n";
    if (result != -1) {
        std::cout << "Shortest path length from 's' to 'd': " << result << std::endl;
    } else {
        std::cout << "No path exists from source to destination.\n";
    }
    return 0;
}
