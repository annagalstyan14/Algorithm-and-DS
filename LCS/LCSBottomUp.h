#ifndef LCS_BOTTOMUP_H
#define LCS_BOTTOMUP_H

#include <string>
#include <vector>

class LCSBottomUp {
private:
    std::string str1;
    std::string str2;
    std::vector<std::vector<int>> dp;

public:
    LCSBottomUp(const std::string& s1, const std::string& s2);
    
    int solve();
    std::string getLCS() const;
    void printDPTable() const;
};

#endif