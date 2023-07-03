#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers = {5, 2, 9, 1, 7};
    
    make_heap(numbers.begin(), numbers.end());

    for (const auto& num : numbers) {
        cout << num << " ";
    }

    return 0;
}
