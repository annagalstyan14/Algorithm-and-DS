#include <iostream>
#include "stack.h"
#include "ArrayStack.h"
#include <string>
#include <unordered_map>
#include <stdexcept>

enum class Operator{
    ADD, SUB, DIV, MULT, POW, NONE
};

bool isOperand(char c) {
    return std::isalpha(c) || std::isdigit(c);
}

Operator CharToOperator(char c) {
    switch (c) {
    case '+': return Operator::ADD;
    case '-': return Operator::SUB; 
    case '/': return Operator::DIV;
    case '*': return Operator::MULT;
    case '^': return Operator::POW;
    default: return Operator::NONE;
    }
}

int Priority(Operator op) {
    static const std::unordered_map<Operator, int> precedence = {
        {Operator::ADD, 1},
        {Operator::SUB, 1},
        {Operator::MULT,2},
        {Operator::DIV, 2},
        {Operator::POW, 3}
    };
    auto it = precedence.find(op);
    return it != precedence.end() ? it->second : -1;
}

int main() {
    arrayStack<char> st;
    std::string input;
    int parenCount = 0;

    try {
        std::cout << "Enter infix expression: ";
        std::getline(std::cin, input);

        if (input.empty()) {
            throw std::runtime_error("Error: Empty input expression");
        }

        for (char c : input) {
            if (c == '(') {
                st.push(c);
                parenCount++;
            }
            else if (c == ')') {
                if (st.empty()) {
                    throw std::runtime_error("Error: Unmatched closing parenthesis");
                }
                while (!st.empty() && st.top() != '(') {
                    std::cout << st.top();
                    st.pop();
                }
                if (st.empty()) {
                    throw std::runtime_error("Error: Unmatched closing parenthesis");
                }
                st.pop();
                parenCount--;
            }
            else if (Operator op = CharToOperator(c); op != Operator::NONE) {
                while (!st.empty() && st.top() != '(' && 
                       Priority(CharToOperator(st.top())) >= Priority(op)) {
                    std::cout << st.top();
                    st.pop();
                }
                st.push(c);
            }
            else if (isOperand(c)) {
                std::cout << c;
            }
            else {
                throw std::runtime_error("Error: Invalid character '" + std::string(1, c) + "'");
            }
        }

        while (!st.empty()) {
            if (st.top() == '(') {
                throw std::runtime_error("Error: Unmatched opening parenthesis");
            }
            std::cout << st.top();
            st.pop();
        }

        if (parenCount != 0) {
            throw std::runtime_error("Error: Mismatched parentheses");
        }

        std::cout << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}