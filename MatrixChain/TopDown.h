#ifndef MATRIX_CHAIN_TOPDOWN_H
#define MATRIX_CHAIN_TOPDOWN_H

#include <vector>
#include <string>

class MatrixChainTopDown {
private:
    std::vector<int> dimensions;
    std::vector<std::vector<int>> dp;
    std::vector<std::vector<int>> split;
    
    int helper(int i, int j);
    std::string getParenthesization(int i, int j) const;

public:
    MatrixChainTopDown(const std::vector<int>& dims);
    
    int solve();
    void printDPTable() const;
    void printOptimalOrder() const;
};

#endif