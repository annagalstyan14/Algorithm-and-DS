#ifndef MATRIX_CHAIN_BOTTOMUP_H
#define MATRIX_CHAIN_BOTTOMUP_H

#include <vector>
#include <string>

class MatrixChainBottomUp {
private:
    std::vector<int> dimensions;
    std::vector<std::vector<int>> dp;
    std::vector<std::vector<int>> split;
    
    std::string getParenthesization(int i, int j) const;

public:
    MatrixChainBottomUp(const std::vector<int>& dims);
    
    int solve();
    void printDPTable() const;
    void printOptimalOrder() const;
};

#endif