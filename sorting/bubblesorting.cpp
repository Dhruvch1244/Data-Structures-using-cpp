#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr = {2, 5, 1, 4, 7};
    int         i, j;
    for (i = 0; i < arr.size() - 1; i++) {
        for (j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int x      = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = x;
            }
        }
    }
    for (int k = 0; k < arr.size(); k++) {
        cout << arr[k] << " ";
    }
    return 0;
}