#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(const vector<int> &nums, int target) {
    unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.count(complement)) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums   = {2, 7, 11, 15};
    int         target = 9;

    vector<int> indices = twoSum(nums, target);

    if (!indices.empty()) {
        cout << "Indices: " << indices[0] << ", " << indices[1] << endl;
        cout << "Numbers: " << nums[indices[0]] << ", " << nums[indices[1]]
             << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
