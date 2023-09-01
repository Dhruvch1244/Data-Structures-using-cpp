#include <iostream>
#define MAX_SIZE 100
using namespace std;

class Stack {
  private:
    int top;
    int arr[MAX_SIZE];

  public:
    Stack() { top = -1; }

    bool isFull() { return top == MAX_SIZE - 1; }

    bool isEmpty() { return top == -1; }

    void push(int element) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        top++;
        arr[top] = element;
        cout << "Pushed " << element << " to the stack." << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    return 0;
}
