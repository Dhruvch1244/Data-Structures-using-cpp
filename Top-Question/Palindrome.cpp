#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string &str) {
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());
    return str == reversedStr;
}

int main() {
    string str        = "radar";
    bool   palindrome = isPalindrome(str);
    if (palindrome) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}
