#include "BottomUp.h"
#include "TopDown.h"
#include <iostream>

int main() {
    std::vector<int> dims = {10, 30, 5, 60, 10};
    
    std::cout << "Matrices:\n";
    for (int i = 0; i < (int)dims.size() - 1; i++) {
        std::cout << "A" << i + 1 << ": " << dims[i] << "x" << dims[i + 1] << "\n";
    }
    
    std::cout << "\nBOTTOM-UP\n";
    MatrixChainBottomUp bottomUp(dims);
    std::cout << "Minimum cost: " << bottomUp.solve() << "\n";
    bottomUp.printOptimalOrder();
    bottomUp.printDPTable();
    
    std::cout << "\nTOP-DOWN\n";
    MatrixChainTopDown topDown(dims);
    std::cout << "Minimum cost: " << topDown.solve() << "\n";
    topDown.printOptimalOrder();
    topDown.printDPTable();
    
    return 0;
}