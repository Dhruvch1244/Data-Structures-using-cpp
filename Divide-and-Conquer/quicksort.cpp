#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i     = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

void printArray(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr  = {9, 5, 1, 8, 3, 2, 7, 6, 4};
    int         size = arr.size();

    cout << "Array before sorting: ";
    printArray(arr);

    quicksort(arr, 0, size - 1);

    cout << "Array after sorting: ";
    printArray(arr);

    return 0;
}
