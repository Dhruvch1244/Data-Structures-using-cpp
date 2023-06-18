#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n) {
    vector<int> fib_table(n + 1, 0);

    fib_table[0] = 0;
    fib_table[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib_table[i] = fib_table[i - 1] + fib_table[i - 2];
    }

    return fib_table[n];
}

int main() {
    int n = 10;
    cout << fibonacci(n) << endl;  // Output: 55

    n = 20;
    cout << fibonacci(n) << endl;  // Output: 6765

    n = 30;
    cout << fibonacci(n) << endl;  // Output: 832040

    return 0;
}
