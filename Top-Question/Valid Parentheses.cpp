#include <iostream>
#include <stack>

using namespace std;

bool isValidParentheses(string s) {
    stack<char> stk;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else {
            if (stk.empty()) {
                return false;
            }
            
            char top = stk.top();
            stk.pop();
            
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stk.empty();
}

int main() {
    string input1 = "()";
    string input2 = "()[]{}";
    string input3 = "(]";
    string input4 = "([)]";

    cout << "Input: " << input1 << " - Output: " << (isValidParentheses(input1) ? "true" : "false") << endl;
    cout << "Input: " << input2 << " - Output: " << (isValidParentheses(input2) ? "true" : "false") << endl;
    cout << "Input: " << input3 << " - Output: " << (isValidParentheses(input3) ? "true" : "false") << endl;
    cout << "Input: " << input4 << " - Output: " << (isValidParentheses(input4) ? "true" : "false") << endl;

    return 0;
}
