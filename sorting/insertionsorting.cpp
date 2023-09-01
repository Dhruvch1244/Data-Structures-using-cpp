#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr = {2, 5, 1, 4, 7};
    int         i, j;
    for (i = 0; i < arr.size(); i++) {
        for (j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                swap(arr[j], arr[i]);
            }
        }
    }
    for (auto k : arr) {
        cout << k << " ";
    }
    return 0;
}