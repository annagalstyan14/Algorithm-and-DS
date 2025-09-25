#ifndef POSTFIX_EVALUATOR_H
#define POSTFIX_EVALUATOR_H

#include "stoi.h"
#include "ArrayStack.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <limits>

long long floorDiv(long long a, long long b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if (a * b < 0 && a % b != 0)
        return (a / b) - 1;
    return a / b;
}

long long evaluatePostfix(std::vector<std::string>& arr) {
    arrayStack<long long> st;

    for (const std::string& token : arr) {
        if (std::isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            try {
                st.push(stringToLong::stoi<long long>(token));
            } catch (const std::exception& e) {
                throw std::invalid_argument("Invalid number: " + token);
            }
        } else {
            if (st.empty()) {
                throw std::invalid_argument("Invalid postfix expression: not enough operands");
            }
            long long val1 = st.top(); st.pop();
            if (st.empty()) {
                throw std::invalid_argument("Invalid postfix expression: not enough operands");
            }
            long long val2 = st.top(); st.pop();

            if (token == "+") {
                if (val2 > std::numeric_limits<long long>::max() - val1) {
                    throw std::out_of_range("Addition overflow");
                }
                st.push(val2 + val1);
            }
            else if (token == "-") {
                if (val2 < std::numeric_limits<long long>::min() + val1) {
                    throw std::out_of_range("Subtraction underflow");
                }
                st.push(val2 - val1);
            }
            else if (token == "*") {
                if (val2 != 0 && (val1 > std::numeric_limits<long long>::max() / val2 || val1 < std::numeric_limits<long long>::min() / val2)) {
                    throw std::out_of_range("Multiplication overflow");
                }
                st.push(val2 * val1);
            }
            else if (token == "/") {
                if (val1 == 0) {
                    throw std::invalid_argument("Division by zero");
                }
                st.push(floorDiv(val2, val1));
            }
            else if (token == "^") {
                double result = std::pow(static_cast<double>(val2), static_cast<double>(val1));
                if (result > static_cast<double>(std::numeric_limits<long long>::max()) ||
                    result < static_cast<double>(std::numeric_limits<long long>::min())) {
                    throw std::out_of_range("Exponentiation overflow");
                }
                st.push(static_cast<long long>(result));
            }
            else {
                throw std::invalid_argument("Invalid operator: " + token);
            }
        }
    }
    if (st.empty()) {
        throw std::invalid_argument("Invalid postfix expression: no result");
    }
    long long result = st.top(); st.pop();
    if (!st.empty()) {
        throw std::invalid_argument("Invalid postfix expression: too many operands");
    }
    return result;
}

#endif