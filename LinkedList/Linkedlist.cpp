#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void remove(int data) {
        if (isEmpty()) {
            cout << "Linked list is empty." << endl;
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->data == data) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }

        cout << "Item not found in the linked list." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Linked list is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;

    linkedList.insertAtEnd(10);
    linkedList.insertAtEnd(20);
    linkedList.insertAtEnd(30);

    linkedList.display();  

    linkedList.remove(20);

    linkedList.display();  

    return 0;
}
