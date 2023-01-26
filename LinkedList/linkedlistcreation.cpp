#include <iostream>
using namespace std;

struct LinkedList{
    int val;
    LinkedList* next;
};

void creation(struct LinkedList* head,int data){
    LinkedList* node = head;
    while(node->next!=NULL){
        node = node->next;
    }
    LinkedList* newnode = new LinkedList();
    newnode->val = data;
    node->next = newnode;
    newnode->next = NULL;
}
void printList(struct LinkedList* head){
    LinkedList* node = head;
    while(node!=NULL){
        cout<<"->"<<node->val;
        node = node->next;
    }
}
int main(){
    LinkedList* head = new LinkedList();
    head->next = NULL;
    head->val = 7;
    creation(head,6);
    creation(head,5);
    creation(head,4);
    creation(head,3);
    printList(head);
    return 0;
}
