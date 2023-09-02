#pragma once
#include <iostream>
#include <vector>
#include <climits>
#include <cassert>
#include <algorithm>
#include "./MaxHeap.h"

class MaxPriorityQueue{
    MaxHeap mh;
        void _replaceByGreaterElement (unsigned int pos, int data);
    public:
        MaxPriorityQueue ();
        MaxPriorityQueue (vector <int> d);
        int top ();
        void insert (int data);
        void printPQ();
        int pop();
};

