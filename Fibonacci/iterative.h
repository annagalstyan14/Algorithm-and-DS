#pragma once

template<typename T>
T iterative(T n){
    if (n<=1) return n;
    T a =0, b = 1;
    for (T i =2; i<=n; i++){
        T c = a + b;
        a = b;
        b = c;
    }
    return b;
}
