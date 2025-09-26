#include <stack>
#include <string> 

bool isPalindrome(const std::string& str) {
    std::stack<char> st;

    for (char ch : str) {
        st.push(ch);
    }
    for (char ch : str) {
        if (st.top() != ch) {
            return false;
        }
        st.pop();
    }

    return true;
}

