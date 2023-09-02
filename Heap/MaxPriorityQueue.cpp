#include "./MaxPriorityQueue.h"

MaxPriorityQueue::MaxPriorityQueue() { mh = MaxHeap(); }
MaxPriorityQueue::MaxPriorityQueue(vector<int> d) {
    mh = MaxHeap(d);
    mh.heapsort();
    reverse(mh.data.begin() + 1, mh.data.end());
}

int MaxPriorityQueue::top() { return mh.getTop(); }

void MaxPriorityQueue::insert(int data) {
    mh.data.push_back(INT_MIN);
    _replaceByGreaterElement(mh.data.size() - 1, data);
}

void MaxPriorityQueue::printPQ() { mh.printHeap(); }
void MaxPriorityQueue::_replaceByGreaterElement(unsigned int pos, int data) {
    if (pos < mh.data.size() && mh.data[pos] < data) {
        mh.data[pos]        = data;
        unsigned int parent = pos / 2;
        while (parent > 0 && mh.data[parent] < mh.data[pos]) {
            swap(mh.data[pos], mh.data[parent]);
            pos    = parent;
            parent = pos / 2;
        }
    }
}
int MaxPriorityQueue::pop() {
    if (mh.getSize()) {
        int ret    = top();
        mh.data[1] = mh.data[mh.data.size() - 1];
        mh.data.pop_back();
        mh.heapify(1);
        return ret;
    } else
        return INT_MIN;
}

#ifdef MAIN_PRIORITY_QUEUE
int main() {
    // Test case 1: Creating an empty MaxPriorityQueue
    MaxPriorityQueue pq1;
    assert(pq1.top() ==
           INT_MIN); // Since the queue is empty, top() should return -1
    assert(pq1.pop() == INT_MIN); // Similarly, pop() should return -1

    // Test case 2: Creating a MaxPriorityQueue from a vector
    std::vector<int> data = {5, 2, 9, 1, 7};
    MaxPriorityQueue pq2(data);
    assert(pq2.top() == 9); // The top element should be 9

    // Test case 3: Inserting elements into the MaxPriorityQueue
    pq2.insert(10);
    assert(pq2.top() == 10); // The top element should now be 10

    pq2.insert(3);
    assert(pq2.top() == 10); // The top element should still be 10

    // Test case 4: Popping elements from the MaxPriorityQueue
    assert(pq2.pop() == 10); // Popping the top element (10)
    assert(pq2.top() == 9);  // The top element should now be 9

    assert(pq2.pop() == 9); // Popping the top element (9)
    assert(pq2.top() == 7); // The top element should now be 7

    // Test case 5: Printing the MaxPriorityQueue
    pq2.printPQ(); // You can manually check the printed queue for correctness

    // Test case 6: Edge case with an empty MaxPriorityQueue
    MaxPriorityQueue pq3;
    pq3.pop(); // Popping from an empty queue should not cause any errors

    std::cout << "All test cases passed!" << std::endl;

    return 0;
}
#endif
