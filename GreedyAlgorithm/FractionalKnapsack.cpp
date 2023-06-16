#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item item1, Item item2) {
    double ratio1 = (double)item1.value / item1.weight;
    double ratio2 = (double)item2.value / item2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (const auto& item : items) {
        if (remainingCapacity >= item.weight) {
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else {
            double fraction = (double)remainingCapacity / item.weight;
            totalValue += fraction * item.value;
            break;
        }
    }

    return totalValue;
}

int main() {
    int capacity = 50;
    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120},
    };

    double maxValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value obtained: " << maxValue << endl;

    return 0;
}
