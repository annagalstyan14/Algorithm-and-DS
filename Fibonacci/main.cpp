#include "iterative.h"
#include "recursive.h"
#include "dp.h"
#include "fi_power_n.h"
#include "matrix.h"
#include <iostream>
#include <limits>
#include <cassert>

constexpr int RECURSIVE_LIMIT = 20;
constexpr int ITERATIVE_LIMIT = 92;

template<typename T>
T compute_fib(int n) {
    if (n <= RECURSIVE_LIMIT) {
        return recursive<T>(n);
    } else if (n <= ITERATIVE_LIMIT) {
        T result_dp = dp<T>(n);
        T result_iter = iterative<T>(n);
        assert(result_dp == result_iter && "DP and iterative methods disagree");
        return result_dp;
    } else {
        if constexpr (std::is_floating_point<T>::value) {
            return fi_power_n<T>(n);
        } else {
            return matrix<T>(n);
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of Fibonacci numbers to display (non-negative integer): ";
    while (!(std::cin >> n) || n < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Enter a non-negative integer: ";
    }

    int type_choice;
    std::cout << "Choose numeric type:\n";
    std::cout << "1. int\n2. long long\n3. long double\n";
    std::cout << "Enter choice: ";
    while (!(std::cin >> type_choice) || type_choice < 1 || type_choice > 3) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Enter 1, 2, or 3: ";
    }

    std::cout << "\nFirst " << n << " Fibonacci numbers:\n";

    switch (type_choice) {
        case 1: // int
            if (n > ITERATIVE_LIMIT + 1) {
                std::cout << "Input too large for int (max: " << (ITERATIVE_LIMIT + 1) << " numbers)\n";
            } else {
                std::cout << "Recursive: ";
                for (int i = 0; i < n; i++) {
                    if (i <= RECURSIVE_LIMIT) {
                        std::cout << recursive<int>(i) << (i < n - 1 ? ", " : "");
                    } else {
                        std::cout << "Skipped (too large)";
                        break;
                    }
                }
                std::cout << "\nIterative: ";
                for (int i = 0; i < n; i++) {
                    std::cout << iterative<int>(i) << (i < n - 1 ? ", " : "");
                }
                std::cout << "\nDP: ";
                for (int i = 0; i < n; i++) {
                    std::cout << dp<int>(i) << (i < n - 1 ? ", " : "");
                }
                std::cout << "\nFi^n: ";
                for (int i = 0; i < n; i++) {
                    std::cout << fi_power_n<int>(i) << (i < n - 1 ? ", " : "");
                }
                std::cout << "\nMatrix: ";
                for (int i = 0; i < n; i++) {
                    std::cout << matrix<int>(i) << (i < n - 1 ? ", " : "");
                }
                std::cout << "\nAutomatically selected: ";
                for (int i = 0; i < n; i++) {
                    std::cout << compute_fib<int>(i) << (i < n - 1 ? ", " : "");
                }
                std::cout << "\n";
            }
            break;
        case 2: // long long
            if (n > ITERATIVE_LIMIT + 1) {
                std::cout << "Input too large for long long (max: " << (ITERATIVE_LIMIT + 1) << " numbers)\n";
            } else {
                std::cout << "Recursive: ";
                for (int i = 0; i < n; i++) {
                    if (i <= RECURSIVE_LIMIT) {
                        std::cout << recursive<long long>(i) << (i < n - 1 ? ", " : "");
                    } else {
                        std::cout << "Skipped (too large)";
                        break;
                    }
                }
                std::cout << "\nIterative: ";
                for (int i = 0; i < n; i++) {
                    std::cout << iterative<long long>(i) << (i < n - 1 ? ", " : "");
                }
                std::cout << "\nDP: ";
                for (int i = 0; i < n; i++) {
                    std::cout << dp<long long>(i) << (i < n - 1 ? ", " : "");
                }
                std::cout << "\nFi^n: ";
                for (int i = 0; i < n; i++) {
                    std::cout << fi_power_n<long long>(i) << (i < n - 1 ? ", " : "");
                }
                std::cout << "\nMatrix: ";
                for (int i = 0; i < n; i++) {
                    std::cout << matrix<long long>(i) << (i < n - 1 ? ", " : "");
                }
                std::cout << "\nAutomatically selected: ";
                for (int i = 0; i < n; i++) {
                    std::cout << compute_fib<long long>(i) << (i < n - 1 ? ", " : "");
                }
                std::cout << "\n";
            }
            break;
        case 3: // long double
            std::cout << "Recursive: ";
            for (int i = 0; i < n; i++) {
                if (i <= RECURSIVE_LIMIT) {
                    std::cout << recursive<long double>(i) << (i < n - 1 ? ", " : "");
                } else {
                    std::cout << "Skipped (too large)";
                    break;
                }
            }
            std::cout << "\nIterative: ";
            for (int i = 0; i < n; i++) {
                std::cout << iterative<long double>(i) << (i < n - 1 ? ", " : "");
            }
            std::cout << "\nDP: ";
            for (int i = 0; i < n; i++) {
                std::cout << dp<long double>(i) << (i < n - 1 ? ", " : "");
            }
            std::cout << "\nFi^n: ";
            for (int i = 0; i < n; i++) {
                std::cout << fi_power_n<long double>(i) << (i < n - 1 ? ", " : "");
            }
            std::cout << "\nMatrix: ";
            for (int i = 0; i < n; i++) {
                std::cout << matrix<long double>(i) << (i < n - 1 ? ", " : "");
            }
            std::cout << "\nAutomatically selected: ";
            for (int i = 0; i < n; i++) {
                std::cout << compute_fib<long double>(i) << (i < n - 1 ? ", " : "");
            }
            std::cout << "\n";
            break;
    }

    return 0;
}
