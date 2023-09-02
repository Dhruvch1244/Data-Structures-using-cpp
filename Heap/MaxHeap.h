#pragma once
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MaxHeap {
    public:
    // valid index are from 1 to n
    //  data[0] is -1, an invalid node
    vector<int> data;

    void _heapify(unsigned int pos, unsigned int size);

  public:
    MaxHeap();
    MaxHeap(vector<int> d);

    inline unsigned int getSize() { return data.size() - 1; }
    void heapify(unsigned int pos) { _heapify(pos, data.size()); }

    void heapsort();
    void buildMaxHeap();

    void printHeap();

    int getTop();
};
