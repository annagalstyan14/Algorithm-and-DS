#include "TopDown.h"
#include <iostream>
#include <climits>

MatrixChainTopDown::MatrixChainTopDown(const std::vector<int>& dims)
    : dimensions(dims) {
    int n = dimensions.size() - 1;
    dp.assign(n + 1, std::vector<int>(n + 1, -1));
    split.assign(n + 1, std::vector<int>(n + 1, -1));
}

int MatrixChainTopDown::helper(int i, int j) {
    if (i == j) return 0;
    
    if (dp[i][j] != -1) return dp[i][j];
    
    dp[i][j] = INT_MAX;
    
    for (int k = i; k < j; k++) {
        int cost = helper(i, k) + helper(k + 1, j)
                 + dimensions[i - 1] * dimensions[k] * dimensions[j];
        
        if (cost < dp[i][j]) {
            dp[i][j] = cost;
            split[i][j] = k;
        }
    }
    
    return dp[i][j];
}

int MatrixChainTopDown::solve() {
    int n = dimensions.size() - 1;
    return helper(1, n);
}

std::string MatrixChainTopDown::getParenthesization(int i, int j) const {
    if (i == j) {
        return "A" + std::to_string(i);
    }
    
    return "(" + getParenthesization(i, split[i][j])
         + " x " + getParenthesization(split[i][j] + 1, j) + ")";
}

void MatrixChainTopDown::printDPTable() const {
    int n = dimensions.size() - 1;
    
    std::cout << "Cost Table:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < i) {
                std::cout << "0\t";
            } else if (dp[i][j] == -1) {
                std::cout << "0\t";
            } else {
                std::cout << dp[i][j] << "\t";
            }
        }
        std::cout << "\n";
    }
}

void MatrixChainTopDown::printOptimalOrder() const {
    int n = dimensions.size() - 1;
    std::cout << "Optimal order: " << getParenthesization(1, n) << "\n";
}