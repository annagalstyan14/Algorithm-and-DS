#include "BottomUp.h"
#include <iostream>
#include <climits>

MatrixChainBottomUp::MatrixChainBottomUp(const std::vector<int>& dims)
    : dimensions(dims) {
    int n = dimensions.size() - 1;
    dp.assign(n + 1, std::vector<int>(n + 1, 0));
    split.assign(n + 1, std::vector<int>(n + 1, -1));
}

int MatrixChainBottomUp::solve() {
    int n = dimensions.size() - 1;

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j]
                         + dimensions[i - 1] * dimensions[k] * dimensions[j];
                
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    split[i][j] = k;
                }
            }
        }
    }
    
    return dp[1][n];
}

std::string MatrixChainBottomUp::getParenthesization(int i, int j) const {
    if (i == j) {
        return "A" + std::to_string(i);
    }
    
    return "(" + getParenthesization(i, split[i][j])
         + " x " + getParenthesization(split[i][j] + 1, j) + ")";
}

void MatrixChainBottomUp::printDPTable() const {
    int n = dimensions.size() - 1;
    
    std::cout << "Cost Table:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < i) {
                std::cout << "0\t";
            } else {
                std::cout << dp[i][j] << "\t";
            }
        }
        std::cout << "\n";
    }
}

void MatrixChainBottomUp::printOptimalOrder() const {
    int n = dimensions.size() - 1;
    std::cout << "Optimal order: " << getParenthesization(1, n) << "\n";
}