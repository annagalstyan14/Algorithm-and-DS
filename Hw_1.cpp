#include <stdexcept>
#include <iostream>
#include <cmath>

double iterative(double x, long long n){

    if(std::abs(x)< 1e-10){
        if (n == 0){
            return 1.0;
        }
        return 0.0;
    }

    bool isNegative = n < 0;
    if (isNegative){
        n = std::llabs(n);
    }

    double result = 1.0;
    for (long long i =0; i < n ; i++){
        result *= x;
    }

    if (isNegative){
        result = 1.0/result;
    }

    return result;
};

double recursive(double x, long long n){

    if(std::abs(x)< 1e-10){
        if (n == 0){
            return 1.0;
        }
        return 0.0;
    }

    if(n< 0){
        return 1.0/recursive(x, std::llabs(n));
    }

    if(n ==0){
        return 1.0;
    }
    if (n == 1){
        return x;
    }

    if (std::abs(n) > 10000){
        throw std::runtime_error("Recursion depth exceeded");
    }

    double result = x * recursive(x, n-1);

    return result;
};

double logn(double x, long long n){

    if(std::abs(x)< 1e-10){
        if (n == 0){
            return 1.0;
        }
        return 0.0;
    }

    bool isNegative = n < 0;
    if (isNegative){
        n = std::llabs(n);
    }
    
    double result = 1.0;
    double base = x;
    while (n>0){
        if (n %2 ==1){
            result *= base;
        }
        base *= base;
        n/= 2;
    }

    if (isNegative){
        result = 1.0/result;
    }

    return result;
};

int main(){

    double x;
    long long n;
    
    std::cout << "Enter base x and component n: ";
    std::cin >> x >>n;

    if(std::cin.fail()){
        std::cerr << "Invalid input";
        return 1; 
    }

    if(std::abs(x)< 1e-10 && n<0){
        std::cerr << "Impossible to raise 0 to a negative power\n";
        return 1;
    }

    try {
        double result_iterative = iterative(x,n);
        std::cout << "Iterative result: " << result_iterative << "\n";
    }
    catch(const std::exception& e){
        std::cout << "Iterative error: " << e.what() << "\n";
    }

    try {
        double result_recursive = recursive(x,n);
        std::cout << "Recursive result: " << result_recursive << "\n";
    }
    catch(const std::exception& e){
        std::cout << "Recursive error: " << e.what() << "\n";
    }

    try {
        double result_logn = logn(x,n);
        std::cout << "O(logn) result: " << result_logn << "\n";
    }
    catch(const std::exception& e){
        std::cout << "O(logn) error: " << e.what() << "\n";
    }

    return 0;
}
