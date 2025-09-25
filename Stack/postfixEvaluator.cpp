#include "postfixEvaluator.h"
#include <iostream>
#include <sstream>

int main() {
    std::cout << "Enter a postfix expression (space-separated, e.g., '2 3 1 * + 9 -'): ";
    std::string input;
    std::getline(std::cin, input);

    try {
        std::vector<std::string> tokens;
        std::istringstream iss(input);
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }

        if (tokens.empty()) {
            throw std::invalid_argument("Empty input");
        }

        int result = evaluatePostfix(tokens);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}