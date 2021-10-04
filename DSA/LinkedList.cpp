#include<iostream>

using namespace std;

/*
Arguments are passed by value, unless the function signature specifies otherwise:

    in void foo(type arg), arg is passed by value regardless of whether type is a simple type, a pointer type or a class type,
    in void foo(type& arg), arg is passed by reference.

In case of arrays, the value that is passed is a pointer to the first elements of the array. If you know the size of the array at compile time, you can pass an array by reference as well: void foo(type (&arg)[10]).

*/

class node {
    public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


void insetAtTail(node* &head,int data) { //pass by refrence 

    node* nodeToinsert = new node(data);
    if(head == NULL) {
        head = nodeToinsert;
        return;
    }

    node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nodeToinsert;
}

void insertAtHead(node* &head, int data) {
    node* nodeToinsert = new node(data);
    if(head == NULL) {
        head = nodeToinsert;
        return;
    }
    nodeToinsert->next = head;

    head = nodeToinsert;
}

void printList(node* &head) {

    node* temp = head;
    int i = 0;
    while(temp != NULL) {
        cout<<i<<"  "<<temp->data<<endl;
        temp = temp->next;
        i++;
    }

}

int main() {


    node* head = NULL;
    insertAtHead(head, 12);
    insertAtHead(head, 13);
    insetAtTail(head, 23);

    printList(head);

    return 0;
}