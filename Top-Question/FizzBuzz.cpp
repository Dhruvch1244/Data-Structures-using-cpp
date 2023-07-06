#include <iostream>
using namespace std;

void fizzBuzz(int n) {
    for (int i = 1; i <= n; ++i) {
        bool divisibleBy3 = (i % 3 == 0);
        bool divisibleBy5 = (i % 5 == 0);

        if (divisibleBy3 && divisibleBy5) {
            cout << "FizzBuzz";
        } else if (divisibleBy3) {
            cout << "Fizz";
        } else if (divisibleBy5) {
            cout << "Buzz";
        } else {
            cout << i;
        }

        cout << " ";
    }
}

int main() {
    int n = 100;
    fizzBuzz(n);
    return 0;
}
