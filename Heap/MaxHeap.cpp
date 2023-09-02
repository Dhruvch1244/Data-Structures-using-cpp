#include "./MaxHeap.h"
using namespace std;

MaxHeap::MaxHeap() { data.push_back(-1); }
MaxHeap::MaxHeap(vector<int> d) {
    data = d;
    data.insert(data.begin(), -1);
}

void MaxHeap::_heapify(unsigned int pos, unsigned int size) {

    if (pos >= size)
        return;
    unsigned int leftChildIndex  = pos * 2;
    unsigned int rightChildIndex = pos * 2 + 1;
    unsigned int largestPos      = pos;
    if (leftChildIndex < size && data[leftChildIndex] > data[pos])
        largestPos = leftChildIndex;

    if (rightChildIndex < size && data[rightChildIndex] > data[largestPos])
        largestPos = rightChildIndex;
    if (largestPos != pos) {
        swap(data[largestPos], data[pos]);
        _heapify(largestPos, size);
    }
}

void MaxHeap::heapsort() {
    buildMaxHeap();
    unsigned int size = data.size();
    for (unsigned int i = getSize(); i >= 2; i--) {
        swap(data[i], data[1]);
        _heapify(1, --size);
    }
}

void MaxHeap::buildMaxHeap() {
    for (unsigned int i = getSize() / 2; i >= 1; i--)
        heapify(i);
}

void MaxHeap::printHeap() {
    for (unsigned int i = 1; i < data.size(); i++)
        cout << data[i] << " , ";
    cout << endl;
}

int MaxHeap::getTop() {
    if (getSize())
        return data[1];
    else
        return INT_MIN;
}

#ifdef MAIN_HEAP

int main() {
    vector<int> d = {3, 6, 2, 7, 43, 53, 42, 78, 84, 8};
    MaxHeap     m = MaxHeap(d);
    m.heapsort();
    m.printHeap();
    return 0;
}

#endif
