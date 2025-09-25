#include <string>
#include <stdexcept>
#include <cctype>
#include <limits>

class stringToLong {
private:
    template<typename T>
    static T processDigits(const std::string& str, size_t& index, T result) {
        if (index >= str.size() || !std::isdigit(str[index])) {
            return result;
        }
        int digit = str[index] - '0';
        if (result > (std::numeric_limits<T>::max() - digit) / 10 ||
            (result == std::numeric_limits<T>::max() / 10 &&
             digit > std::numeric_limits<T>::max() % 10)) {
            throw std::out_of_range("Integer overflow");
        }
        result = result * 10 + digit;
        ++index;
        return processDigits(str, index, result);
    }

public:
    template<typename T>
    static T stoi(const std::string& str) {
        static_assert(std::is_same<T, int>::value || std::is_same<T, long>::value || std::is_same<T, long long>::value,
                      "Template type T must be int, long, or long long");
        if (str.empty()) {
            throw std::invalid_argument("Empty string");
        }
        size_t index = 0;
        while (index < str.size() && std::isspace(str[index])) {
            ++index;
        }
        if (index == str.size()) {
            throw std::invalid_argument("String contains only whitespace");
        }
        bool isNegative = false;
        if (str[index] == '-') {
            isNegative = true;
            ++index;
        } else if (str[index] == '+') {
            ++index;
        }
        if (index >= str.size() || !std::isdigit(str[index])) {
            throw std::invalid_argument("No valid digits");
        }
        T result = processDigits(str, index, T(0));
        while (index < str.size()) {
            if (!std::isspace(str[index])) {
                throw std::invalid_argument("Invalid character in string");
            }
            ++index;
        }
        if (isNegative) {
            result = -result;
            if (result < std::numeric_limits<T>::min()) {
                throw std::out_of_range("Integer underflow");
            }
        } else {
            if (result > std::numeric_limits<T>::max()) {
                throw std::out_of_range("Integer overflow");
            }
        }
        return result;
    }
};