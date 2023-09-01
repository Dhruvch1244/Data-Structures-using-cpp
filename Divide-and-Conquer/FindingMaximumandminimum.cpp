#include <climits>
#include <iostream>

using namespace std;

struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(int arr[], int start, int end) {
    MinMax result;

    if (start == end) {
        result.min = arr[start];
        result.max = arr[start];
        return result;
    }

    if (end - start == 1) {
        if (arr[start] < arr[end]) {
            result.min = arr[start];
            result.max = arr[end];
        } else {
            result.min = arr[end];
            result.max = arr[start];
        }
        return result;
    }

    int    mid   = (start + end) / 2;
    MinMax left  = findMinMax(arr, start, mid);
    MinMax right = findMinMax(arr, mid + 1, end);

    result.min = min(left.min, right.min);
    result.max = max(left.max, right.max);

    return result;
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 4, 6, 3};
    int n     = sizeof(arr) / sizeof(arr[0]);

    MinMax result = findMinMax(arr, 0, n - 1);

    cout << "Minimum: " << result.min << endl;
    cout << "Maximum: " << result.max << endl;

    return 0;
}
