#include <iostream>
#define MAX_SIZE 100

using namespace std;
class Stack {
  private:
    int top;
    int arr[MAX_SIZE];

  public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }

    void push(int element) {
        // ...
    }

    int pop() {
        // ...
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);

    if (stack.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    stack.pop();
    stack.pop();

    if (stack.isEmpty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
