#include <iostream>
#include <vector>

using namespace std;

bool subsetSumUtil(vector<int>& nums, int target, int index, int currentSum) {

    if (currentSum == target) {
        return true;
    }

    if (currentSum > target || index >= nums.size()) {
        return false;
    }


    bool include = subsetSumUtil(nums, target, index + 1, currentSum + nums[index]);


    if (include) {
        return true;
    }


    bool exclude = subsetSumUtil(nums, target, index + 1, currentSum);


    return exclude;
}

bool subsetSum(vector<int>& nums, int target) {
    
    return subsetSumUtil(nums, target, 0, 0);
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    if (subsetSum(nums, target)) {
        cout << "Subset with the given target sum exists." << endl;
    } else {
        cout << "No subset with the given target sum exists." << endl;
    }

    return 0;
}
