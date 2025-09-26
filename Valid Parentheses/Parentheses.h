#include "../Stack/ArrayStack.h"
#include <string>
#include <unordered_map>
#include <iostream>

bool isBalanced (const std::string& s) {
    arrayStack<char> stack;
    std::unordered_map<char, char> matchingBrackets = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.empty() || stack.top() != matchingBrackets[ch]) {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}
