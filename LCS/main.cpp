#include "LCSBottomUp.h"
#include "LCSTopDown.h"
#include <iostream>

int main() {
    std::string s1 = "ABCDGH";
    std::string s2 = "AEDFHR";
    
    std::cout << "String 1: " << s1 << "\n";
    std::cout << "String 2: " << s2 << "\n\n";
    
    // Bottom-up method
    std::cout << "BOTTOM-UP (Tabular)\n";
    LCSBottomUp bottomUp(s1, s2);
    std::cout << "LCS Length: " << bottomUp.solve() << "\n";
    std::cout << "LCS: " << bottomUp.getLCS() << "\n\n";
    bottomUp.printDPTable();
    
    std::cout << "\nTOP-DOWN (Memoization)\n";
    LCSTopDown topDown(s1, s2);
    std::cout << "LCS Length: " << topDown.solve() << "\n";
    std::cout << "LCS: " << topDown.getLCS() << "\n\n";
    topDown.printDPTable();
    
    return 0;
}