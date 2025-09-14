#pragma once
#include <vector>

template<typename T>
std::vector<std::vector<T>> multiply(const std::vector<std::vector<T>> &A, const std::vector<std::vector<T>> &B) {
    return {
        {A[0][0] * B[0][0] + A[0][1] * B[1][0], A[0][0] * B[0][1] + A[0][1] * B[1][1]},
        {A[1][0] * B[0][0] + A[1][1] * B[1][0], A[1][0] * B[0][1] + A[1][1] * B[1][1]}
    };
}

template<typename T>
std::vector<std::vector<T>> power(std::vector<std::vector<T>> M, long long n) {
    if (n == 1) return M;
    if (n % 2 == 0) {
        auto half = power(M, n / 2);
        return multiply(half, half);
    } else {
        return multiply(M, power(M, n - 1));
    }
}

template<typename T>
T matrix(long long n) {
    if (n == 0) return 0;
    std::vector<std::vector<T>> F = {{1, 1}, {1, 0}};
    return power(F, n)[0][1];
}