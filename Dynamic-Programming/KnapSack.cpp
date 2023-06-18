#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

int knapsack(int capacity, const vector<Item>& items) {
    int n = items.size();

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (items[i - 1].weight <= j) {
                dp[i][j] = max(dp[i - 1][j], items[i - 1].value + dp[i - 1][j - items[i - 1].weight]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity = 10;
    vector<Item> items = {{2, 6}, {2, 10}, {3, 12}};

    int max_value = knapsack(capacity, items);
    cout << "Maximum value: " << max_value << endl;  // Output: 22

    return 0;
}
