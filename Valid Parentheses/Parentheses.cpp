#include "Parentheses.h"
#include <iostream>

int main() {
    std::string input;
    std::cout << "Enter a sequence of brackets: ";
    std::cin >> input;

    if (isBalanced(input)) {
        std::cout << "Balanced" << std::endl;
    } else {
        std::cout << "Not Balanced" << std::endl;
    }

    return 0;
}