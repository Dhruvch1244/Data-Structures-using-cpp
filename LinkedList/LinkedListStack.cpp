#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;

    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        cout << "Pushed element: " << data << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform pop operation." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped element: " << temp->data << endl;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform peek operation." << endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* current = top;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();  

    stack.pop();
    stack.display();  

    cout << "Top element: " << stack.peek() << endl;  

    return 0;
}
