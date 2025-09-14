#pragma once 
#include <vector>

template<typename T>
T prev2 = 0, prev1 = 1;
    for (T i = 2; i <= n; i++) {
        T curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
