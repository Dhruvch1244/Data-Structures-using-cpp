#include <iostream>
#include <string>

using namespace std;

string reverseString(const string &str) {
    string reversedStr;
    for (int i = str.length() - 1; i >= 0; --i) {
        reversedStr.push_back(str[i]);
    }
    return reversedStr;
}

int main() {
    string str         = "Hello, World!";
    string reversedStr = reverseString(str);
    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversedStr << endl;
    return 0;
}
