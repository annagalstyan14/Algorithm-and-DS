#ifndef LCS_TOPDOWN_H
#define LCS_TOPDOWN_H

#include <string>
#include <vector>

class LCSTopDown {
private:
    std::string str1;
    std::string str2;
    std::vector<std::vector<int>> dp;
    
    int helper(int i, int j);

public:
    LCSTopDown(const std::string& s1, const std::string& s2);
    
    int solve();
    std::string getLCS() const;
    void printDPTable() const;
};

#endif