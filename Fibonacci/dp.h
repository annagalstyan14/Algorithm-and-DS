#pragma once 
#include <vector>

template<typename T>
T dp(T n){
    if (n<=1) return n;
    std::vector<T> dp(n+1);
    dp[0] = 0; dp[1] = 1;
    for (T i = 2, i <=n; i++)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
    
}