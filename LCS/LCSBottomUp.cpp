#include "LCSBottomUp.h"
#include <iostream>
#include <algorithm>

LCSBottomUp::LCSBottomUp(const std::string& s1, const std::string& s2)
    : str1(s1), str2(s2) {
    dp.assign(str1.length() + 1, std::vector<int>(str2.length() + 1, 0));
}

int LCSBottomUp::solve() {
    int m = str1.length();
    int n = str2.length();
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

std::string LCSBottomUp::getLCS() const {
    std::string lcs;
    int i = str1.length();
    int j = str2.length();
    
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs += str1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    std::reverse(lcs.begin(), lcs.end());
    return lcs;
}

void LCSBottomUp::printDPTable() const {
    int m = str1.length();
    int n = str2.length();
    
    std::cout << "DP Table:\n";
    std::cout << "      ";
    for (int j = 0; j <= n; j++) {
        if (j == 0) std::cout << "-  ";
        else std::cout << str2[j - 1] << "  ";
    }
    std::cout << "\n";
    
    for (int i = 0; i <= m; i++) {
        if (i == 0) std::cout << "-  ";
        else std::cout << str1[i - 1] << "  ";
        
        for (int j = 0; j <= n; j++) {
            std::cout << dp[i][j] << "  ";
        }
        std::cout << "\n";
    }
}