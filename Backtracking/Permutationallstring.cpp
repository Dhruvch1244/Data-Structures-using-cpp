#include <iostream>
#include <string>
#include <vector>

using namespace std;

void permute(string str, int index, vector<bool>& used, string current) {
    if (index == str.length()) {
        cout << current << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        if (!used[i]) {
            used[i] = true;
            permute(str, index + 1, used, current + str[i]);
            used[i] = false;
        }
    }
}

void printPermutations(string str) {
    int n = str.length();
    vector<bool> used(n, false); 
    
    permute(str, 0, used, "");
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "Permutations of the given string:" << endl;
    printPermutations(str);

    return 0;
}
