#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "stack.h"
#include "linkedStack.h"

bool isOperand(char c) {
    return std::isalpha(c) || std::isdigit(c);
}

bool isOperator(char c) {
    switch (c) {
    case '+':
    case '-':
    case '/':
    case '*':
    case '^':
        return true;
    }
    return false;
}

int Priority(char c) {
    switch (c) {
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

int main() {
    linkedStack<char> st;
    std::string input, output;
    int parenCount = 0;

    try {
        std::cout << "Enter infix expression: ";
        std::getline(std::cin, input);

        if (input.empty()) {
            throw std::runtime_error("Error: Empty input expression");
        }

        for (auto it = input.rbegin(); it != input.rend(); ++it) {
            char c = *it;
            if (c == ')') {
                st.push(c);
                parenCount++;
            }
            else if (c == '(') {
                if (st.empty()) {
                    throw std::runtime_error("Error: Unmatched closing parenthesis");
                }
                while (!st.empty() && st.top() != ')') {
                    output += st.top();
                    st.pop();
                }
                if (st.empty()) {
                    throw std::runtime_error("Error: Unmatched closing parenthesis");
                }
                st.pop();
                parenCount--;
            }
            else if (isOperator(c)) {
                while (!st.empty() && st.top() != ')' && 
                       (Priority(st.top()) > Priority(c) || 
                        (Priority(st.top()) == Priority(c) && c != '^'))) {
                    output += st.top();
                    st.pop();
                }
                st.push(c);
            }
            else if (isOperand(c)) {
                output += c;
            }
            else {
                throw std::runtime_error("Error: Invalid character '" + std::string(1, c) + "'");
            }
        }

        while (!st.empty()) {
            if (st.top() == ')') {
                throw std::runtime_error("Error: Unmatched opening parenthesis");
            }
            output += st.top();
            st.pop();
        }

        if (parenCount != 0) {
            throw std::runtime_error("Error: Mismatched parentheses");
        }

        std::reverse(output.begin(), output.end());
        std::cout << "Prefix: " << output << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
