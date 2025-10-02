#include <iostream>
#include "Palindrome.h"

int main() {
    std::string input;
    std::cout << "Enter a word: ";
    std::cin >> input;

    if (isPalindrome(input)) {
        std::cout << "Palindrome" << std::endl;
    } else {
        std::cout << "Not Palindrome" << std::endl;
    }

    return 0;
}
