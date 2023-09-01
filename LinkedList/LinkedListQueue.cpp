#include <iostream>
using namespace std;
struct Node {
    int   data;
    Node *next;
};

struct Queue {
    Node *front;
    Node *rear;

    Queue() {
        front = nullptr;
        rear  = nullptr;
    }

    bool isEmpty() { return front == nullptr; }

    void enqueue(int data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            rear  = newNode;
        } else {
            rear->next = newNode;
            rear       = newNode;
        }

        cout << "Enqueued element: " << data << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot perform dequeue operation." << endl;
            return;
        }

        Node *temp = front;
        front      = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        cout << "Dequeued element: " << temp->data << endl;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot perform peek operation." << endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node *current = front;
        cout << "Queue elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();

    queue.dequeue();
    queue.display();

    cout << "Front element: " << queue.peek() << endl;
    return 0;
}
