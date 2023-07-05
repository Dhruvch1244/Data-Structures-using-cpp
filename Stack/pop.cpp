#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Stack {
private:
    int top;                  
    int arr[MAX_SIZE];        

public:
    Stack() {
        top = -1;             
    }

    bool isEmpty() {
        return top == -1;     
    }

    void push(int element) {
        // ...
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;  
        }

        int poppedElement = arr[top]; 
        top--;                      
        return poppedElement;        
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    int poppedElement1 = stack.pop();
    cout << "Popped element: " << poppedElement1 << endl;

    int poppedElement2 = stack.pop();
    cout << "Popped element: " << poppedElement2 << endl;

    int poppedElement3 = stack.pop();
    cout << "Popped element: " << poppedElement3 << endl;

    int poppedElement4 = stack.pop();  
    cout << "Popped element: " << poppedElement4 << endl;

    return 0;
}
